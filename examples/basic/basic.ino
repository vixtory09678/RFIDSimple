#include <SPI.h>
#include <RFIDSimple.h>

#define SDA_PIN 21
#define RST_PIN 22

RFIDSimple rfid(SDA_PIN, RST_PIN);

void onRead(String id) {
    Serial.print("id is ");
    Serial.println(id);
}

void setup() {
    Serial.begin(9600);
    SPI.begin();
    rfid.setup();
    rfid.setCallback(onRead);
}

void loop() {
    rfid.run();
}