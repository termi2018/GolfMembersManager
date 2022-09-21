#include "Monitor.h"

Monitor::Monitor()
{

}

Monitor::~Monitor()
{

}

void Monitor::print(uint8_t *data, int size) //size : data 변수(배열)의 크기
{
    for(int i=0; i<size; i++)
    {
        // printf("%d ", data[i]); //10진수
        printf("%x ", data[i]);    //16진수
    }
    printf("\n");
}