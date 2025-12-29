#pragma once
#include <stdint.h> 
#include <iostream>
#include <ostream>
typedef struct Data
{
    unsigned int num;
}Data;

class Serializer
{
    public :
    Serializer();
    Serializer(const Serializer &oth);
    Serializer& operator=(const Serializer &oth);
    ~Serializer();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};