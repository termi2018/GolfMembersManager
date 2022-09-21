#include "Listener.h"
#include <string.h>

Listener::Listener() : 
rfid(new CardReader(new SPI(10, 3000000))), controller(new Controller()) //mfrc522 *rfid = rfid;
{
    //this->rfid = rfid;
    //monitor = new Monitor(); // 주체에서 생성

    // rfid = new CardReader(new SPI(10, 3000000));
    // controller = new Controller();

    modeButton = new ManageButton(27, "ModeButton");

}

Listener::~Listener()
{

}

void Listener::checkEvent()
{
    if(checkRfid()) {
        // monitor->print(rfidData, 16);
        controller->updateEvent(rfid->getCardNumber());
    }

    if(modeButton->CheckButton())
    {
        controller->updateEvent(modeButton->getButtonData());
    }
}

bool Listener::checkRfid()
{
    static unsigned int prevCheckTime = 0;
    if(millis() - prevCheckTime < 1000) { 
        return false;
    } 

    prevCheckTime = millis();
    
    if(rfid->isCard()) return true;
    
    return false;
}