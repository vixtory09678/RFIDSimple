#include "RFIDSimple.h"

RFIDSimple::RFIDSimple(int sda_pin,int rst_pin) : _rfid(sda_pin,rst_pin), debug(false)
{
    countNotFound = 0;
    isFound = 0;
}

RFIDSimple::~RFIDSimple()
{

}

void RFIDSimple::setup(){
    _rfid.init();
}

void RFIDSimple::setDebug(bool state){
    debug = state;
}

void RFIDSimple::setCallback(void (*call)(String id)){
    callback = call;
}

void RFIDSimple::run(){
    if (_rfid.isCard()) {

    if (debug) Serial.println("CARD FOUND");

    if (isFound == true) return;

    if (_rfid.readCardSerial()) {
      isFound = true;
      String card = String(_rfid.serNum[0], HEX)
                    + String(_rfid.serNum[1], HEX)
                    + String(_rfid.serNum[2], HEX)
                    + String(_rfid.serNum[3], HEX)
                    + String(_rfid.serNum[4], HEX);

      if (countNotFound > 1) { 
        // do one time
        if (debug) {
            Serial.print("Card is ");
            Serial.println(card);
        }

        if (callback != NULL) {
            callback(card);
        }
      }
      countNotFound = 0;
    }
  } else {
    isFound = false;
    countNotFound += 1;
  }
  _rfid.halt();
}