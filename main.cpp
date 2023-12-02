#include <iostream>
#include "mytime.h"

int main(int argc, char ** argv) {
    MyTime test = MyTime(4,20,69, 16, 20);
    std::cout << test << std::endl;
    std::cout << "Raw: " << test.getRaw() << std::endl;
    return 0;
}