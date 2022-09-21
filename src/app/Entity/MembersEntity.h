#ifndef MEMBERSENTITY_H
#define MEMBERSENTITY_H

#include <vector>
#include <string>
#include <iostream>
#include "MemberInfo.h"

class MembersEntity
{
private:
    std::vector<MemberInfo> vecMembersList;
    MemberInfo memberInfo;
    FILE *fpDBData;

public:
    MembersEntity();
    virtual ~MembersEntity();
    void loadMembersInfo(); // 멤버를 메모리에 로드
    void addMemberInfo(MemberInfo member);
    bool delMemberInfo(int *cardNum);
    void memoryToDB();
    // void makeDBMembersInfo();
    void printMemberInfo(int index);
    void printMemberInfo(std::string name);
    void printMemberInfo(int *cardNum);
    // char 문자열과 std::string과는 내부 형태가 다름
    bool findMemberInfo(std::string name);
    bool findMemberInfo(int *cardNum);
};

#endif