#ifndef MANAGEBUTTON_H
#define MANAGEBUTTON_H

#include "Button.h"
#include "DeviceData.h"
#include <string>

class ManageButton : public Button
{
private:
    DeviceData buttonData;

public:
    ManageButton(int pin, std::string name);
    virtual ~ManageButton();

    bool CheckButton();
    DeviceData getButtonData();

};

#endif