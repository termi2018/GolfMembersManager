#include "CardReader.h"
#include <string.h>

CardReader::CardReader(SPI* spi) : mfrc522(spi) 
//base(부모) 생성자에도 값을 알려주기 위해 넣음 
//상속 받은 클래스에도 값을 알려주기 위함 -> 리스너가 mfrc522가 아닌 CardReader로 참조하기 때문
{

}

CardReader::~CardReader()
{

}

bool CardReader::isCard()
{
    uint8_t byte = mfrc522_request(PICC_REQALL, rfidData);
    if(byte ==  CARD_FOUND)
        return true;
    else  
        return false;

    return false; //기본값
}

DeviceData CardReader::getCardNumber()
{
    mfrc522_get_card_serial(rfidData);
    cardData.devName = "cardReader";
    cardData.devData.clear(); //std::vector<int> devData;
    for(const auto data : rfidData)
    {
        cardData.devData.push_back((int) data);
    }
    return cardData;
}