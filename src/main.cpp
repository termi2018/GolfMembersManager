#include <iostream>
// #include "mfrc522.h"
// #include "Listener.h"
#include <string>
#include <cstring>
#include "GolfMembershipManager.h"
#include "MembersEntity.h"

int main(void)
{
    // mfrc522 rfid(new SPI(10, 3000000));
    // Listener *listener = new Listener(&rfid);

    // while(1)
    // {
    //     listener->checkEvent();
    //     delay(1000);
    //     printf("hihi\n");
    // }

    GolfMembershipManager golfMembershipManager;
    golfMembershipManager.run();

    // MembersEntity membersEntity;
    // membersEntity.printMemberInfo(10);
    // membersEntity.printMemberInfo(150);
    // membersEntity.printMemberInfo(200);
    // membersEntity.printMemberInfo(2000);

    // std::cout <<std::endl;
    
    // membersEntity.printMemberInfo("lrjtripxojahohdtjvr");
    // membersEntity.printMemberInfo("qcbpjjxpsxgjmzrtlhw");
    
    // std::cout <<std::endl;

    // if(membersEntity.findMemberInfo("qcbpjjxpsxgjmzrtlhw")) {
    //     printf("qcbpjjxpsxgjmzrtlhw is found the name\n");
    // } else {
    //     printf("qcbpjjxpsxgjmzrtlhw is not found the name\n");
    // }
    // if(membersEntity.findMemberInfo("honggildong")) {
    //     printf("honggildong is found the name\n");
    // } else {
    //     printf("honggildong is not found the name\n");
    // }
    
    // std::cout << std::endl;

    // int cardNumer[5] = {0x03, 0x68, 0x77, 0x56, 0xdb};

    // if(membersEntity.findMemberInfo(cardNumer)) {
    //     printf("qcbpjjxpsxgjmzrtlhw is found the name\n");
    //     membersEntity.printMemberInfo(cardNumer);
    // } else {
    //     printf("qcbpjjxpsxgjmzrtlhw is not found the name\n");
    // }

    // int cardNumer2[5] = {0x01, 0x23, 0x45, 0x67, 0x89};
    // if(membersEntity.findMemberInfo(cardNumer2)) {
    //     printf("honggildong is found the name\n");
    // } else {
    //     printf("honggildong is not found the name\n");
    // }

    // std::cout << std::endl;

    // MemberInfo member;
    // member.id = 10000;
    // strcpy(member.name, "HongGilDong");
    // strcpy(member.address, "100dong-100ho");
    // strcpy(member.phoneNumber, "010-1234-1234");
    // memcpy(member.cardNum, cardNumer2, sizeof(cardNumer2));

    // membersEntity.addMemberInfo(member);

    // if(membersEntity.findMemberInfo("HongGilDong")) {
    //     printf("2 HongGilDong is found the name\n");
    //     membersEntity.printMemberInfo("HongGilDong");
    // } else {
    //     printf("2 HongGilDong is not found the name\n");
    // }

    // if(membersEntity.findMemberInfo(cardNumer2)) {
    //     printf("2 HongGilDong is found the name\n");
    //     membersEntity.printMemberInfo(cardNumer2);
    // } else {
    //     printf("2 HongGilDong is not found the name\n");
    // }

    // std::cout << std::endl;

    // if(membersEntity.delMemberInfo(cardNumer)) {
    //     printf("deleted!\n");
    // } else {
    //     printf("delete error!\n");
    // }

    // std::cout << std::endl;

    // if(membersEntity.findMemberInfo(cardNumer)) {

    //     printf("del -- found the name\n");
    //     membersEntity.printMemberInfo(cardNumer);
    // } else {
    //     printf("del -- not found the name\n");
    // }
    
    // std::cout << std::endl;

    // membersEntity.memoryToDB();
    return 0;
}