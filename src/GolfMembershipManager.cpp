#include "GolfMembershipManager.h"

GolfMembershipManager::GolfMembershipManager()
// mfrc522 *rfid = new mfrc522(new SPI(10, 3000000));
{
    listener = new Listener();
}

GolfMembershipManager::~GolfMembershipManager()
{

}

void GolfMembershipManager::run()
{
    while(1)
    {
        listener->checkEvent();
        delay(10);
    }
}