#ifndef LISTENER_H
#define LISTENER_H

// #include "Monitor.h"
#include "Controller.h"
#include "CardReader.h"
#include "ManageButton.h"

class Listener
{
private:
    //Monitor *monitor;
    CardReader *rfid;
    ManageButton *modeButton;
    Controller *controller;
    uint8_t rfidData[16];

public:
    Listener();
    virtual ~Listener();
    void checkEvent();
    bool checkRfid();
};

#endif