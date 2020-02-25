#include "Int.hpp"



int main() {


    Int digit(10);
    Int digit1(7);

    digit1++;
    digit--;
    digit1.dump();
    //Int digit2 = digit1++;
    Int digit2 = digit1 * digit1;
    std::cout << digit2 << std::endl;

    return 0;
}


