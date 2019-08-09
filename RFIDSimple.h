#ifndef RFID_SIMPLE_H
#define RFID_SIMPLE_H

#include "RFID.h"

class RFIDSimple
{
private:
    /* data */
    RFID _rfid;
    bool debug;
    bool isFound;
    unsigned long countNotFound;
    void (*callback)(String id);
public:
    RFIDSimple(int sda_pin,int rst_pin);
    void setCallback(void (*call)(String id));
    void setup();
    void run();
    void setDebug(bool state);
    ~RFIDSimple();
};

#endif