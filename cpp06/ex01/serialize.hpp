#pragma once
#include <cstdint>
#include <iostream>
#include <ostream>
typedef struct Data
{
    unsigned int num;
}Data;

class Serializer
{
    public :
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};