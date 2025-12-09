#include "serialize.hpp"

// int main()
// {
//     Data *ptr = new Data();
//     Serializer test;
//     std::cout << ptr << std::endl;
//     test.serialize(ptr);
//     std::cout << ptr << std::endl;
//     std::cout << test.deserialize( test.serialize(ptr)) << std::endl;
    
// }
int main()
{
    Data *ptr = new Data();
    ptr->num = 42;
    
    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Original value: " << ptr->num << std::endl;
    

    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Serialized: " << raw << std::endl;
    
    Data *ptr2 = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr2 << std::endl;
    std::cout << "Deserialized value: " << ptr2->num << std::endl;
    
    if (ptr == ptr2)
        std::cout << " Pointers match!" << std::endl;
    
    delete ptr;
    return 0;
}