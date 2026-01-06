#include <iostream>
#include <vector>
#include <deque>

class work
{
    private :
    std::vector<int> array;
    public :
    work(std::vector<int> ar) {array = ar;}
    std::vector<int> get_array(){return array;}
};