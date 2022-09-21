#include "ManageButton.h"

ManageButton::ManageButton(int pin, std::string name)
: Button(pin)
{
    buttonData.devName = name;
}

ManageButton::~ManageButton()
{

}

bool ManageButton::CheckButton()
{
    if(getState() ==  RELEASE_ACTIVE)
        return true;
    
    return false; 
}

DeviceData ManageButton::getButtonData()
{
    //buttonData.devName = "ModeButton";
    buttonData.devData.clear(); //std::vector<int> devData;
    buttonData.devData.push_back(1); //std::vector<int> devData;
    return buttonData;
}