#include "MembersEntity.h"
#include <cstring> // or #include <string.h>

MembersEntity::MembersEntity()
{
    loadMembersInfo();
}

MembersEntity::~MembersEntity()
{

}

void MembersEntity::loadMembersInfo()
{
    fpDBData = fopen("memberLists.bin", "r");
    if(fpDBData == NULL) // file open 실패
    {
        fprintf(stderr, "file open error!\n"); // 화면에 에러표시, stdout : 버퍼를 거침
        // printf("file open error\n");
        return; //그냥 빠져나옴
    }

    while(fread(&memberInfo, sizeof(MemberInfo), 1, fpDBData)) 
    //fread 매개변수 : 읽어온 데이터를 담을 버퍼, 데이터의 크기, 읽는 횟수, 어디것을 읽을 것인가?, 몇 byte 만큼 읽어왔는지 리턴)
    {
        vecMembersList.push_back(memberInfo);
    }
    fclose(fpDBData);   // 파일은 항상 닫아줘야 함.
}

void MembersEntity::printMemberInfo(int index)
{
    if(index > (int)vecMembersList.size()) { // vector의 사이즈보다 클 경우 예외처리
        fprintf(stderr, "out of range member!\n");
        return; //그냥 빠져나옴
    } 
    
    printf("%04d, %s, %s, %s, %0x-%0x-%0x-%0x-%0x\n", 
        vecMembersList[index].id, 
        vecMembersList[index].name, 
        vecMembersList[index].address,
        vecMembersList[index].phoneNumber,
        vecMembersList[index].cardNum[0],
        vecMembersList[index].cardNum[1],
        vecMembersList[index].cardNum[2],
        vecMembersList[index].cardNum[3],
        vecMembersList[index].cardNum[4]
    );
}

void MembersEntity::printMemberInfo(std::string name)
{
    for(const auto &member : vecMembersList)     //10만개 데이터가 heap 저장되어 있음
    // &member : 레퍼런스 변수
    {
        if(strcmp(member.name, name.c_str()) == 0)   //c_str() name에 들어간 string을 char형으로 변환, 문자열은 ==로 비교안됨, strcmp사용, 반환값이 0이면 같음
        {
            printMemberInfo(member.id);
            return; // 같은 것을 찾았으니, 검색 중지
        }
    }
    
}

void MembersEntity::printMemberInfo(int *cardNum)
{
    for(const auto &member : vecMembersList)     //10만개 데이터가 heap 저장되어 있음
    // &member : 레퍼런스 변수
    {
        if(memcmp(member.cardNum, cardNum, sizeof(member.cardNum)) == 0)   
        {
            printf("%04d, %s, %s, %s, %0x-%0x-%0x-%0x-%0x\n",
                   member.id,
                   member.name,
                   member.address,
                   member.phoneNumber,
                   member.cardNum[0],
                   member.cardNum[1],
                   member.cardNum[2],
                   member.cardNum[3],
                   member.cardNum[4]);
            return; // 같은 것을 찾았으니, 검색 중지
        }
    }
    
}

bool MembersEntity::findMemberInfo(std::string name)
{
    for(const auto &member : vecMembersList)     
    //10만개 데이터가 heap 저장되어 있음
    {
        if(strcmp(member.name, name.c_str()) == 0)   
        //c_str() name에 들어간 string을 char형으로 변환, 문자열은 ==로 비교안됨, strcmp사용, 반환값이 0이면 같음
        {
            // printMemberInfo(member.id);
            return true; // 같은 것을 찾았으니, 검색 중지
        }
    }
    return false;
}

bool MembersEntity::findMemberInfo(int *cardNum)
{
    for(const auto &member : vecMembersList)     
    //10만개 데이터가 heap 저장되어 있음
    {
        if(memcmp(member.cardNum, cardNum, sizeof(member.cardNum)) == 0)   
        // memcmp 메모리 비교함수 : 비교할 변수1, 2, 메모리크기(byte)
        {
            return true; // 같은 것을 찾았으니, 검색 중지
        }
    }
    return false;
}

void MembersEntity::addMemberInfo(MemberInfo member)
{
    vecMembersList.push_back(member);
}

bool MembersEntity::delMemberInfo(int *cardNum)
{
    std::vector<MemberInfo>::iterator itrMember;
    itrMember = vecMembersList.begin();                                             // begin() : vector 배열의 시작주소

    for(itrMember; itrMember != vecMembersList.end(); itrMember++)                  // end() : vector 배열의 끝주소
    {
        if(memcmp(itrMember->cardNum, cardNum, sizeof(itrMember->cardNum)) == 0)    //0 : 값이 같다면
        {
            vecMembersList.erase(itrMember);
            return true;
        }
    }
    return false;
 }

 void MembersEntity::memoryToDB(){
    /**
        file open
        vecMemberList의 배열을 하나씩 read
        vecMembersList값을 file에 vecMemberList 끝까지 write/
        file close
     */

    fpDBData = fopen("memberLists.bin", "w");
    FILE *fpDBData2 = fopen("memberLists.txt", "w");
    if(fpDBData == NULL) // file open 실패
    {
        fprintf(stderr, "file open error!\n"); // 화면에 에러표시, stdout : 버퍼를 거침
        return; //그냥 빠져나옴
    }

    for(const auto &member : vecMembersList)
    {   
        fwrite(&member, sizeof(member), 1, fpDBData);
        fprintf(fpDBData2, "%5d, %s\n", member.id, member.name);
    }
    fclose(fpDBData);   // 파일은 항상 닫아줘야 함.
    fclose(fpDBData2);   // 파일은 항상 닫아줘야 함.

 }