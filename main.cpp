#include <iostream>
#include "mytime.h"

int main(int argc, char ** argv) {
    MyTime test = MyTime(4,20,69, 16, 20);
    std::cout << test << std::endl;
    test.setYear(140);
    std::cout << test << std::endl;
    test.setMonth(10);
    std::cout << test << std::endl;
    test.setDay(30);
    std::cout << test << std::endl;
    test.setHour(21);
    std::cout << test << std::endl;
    test.setMinutes(30);
    std::cout << test << std::endl;
    return 0;
}