#include <iostream>
#include "mytime.h"

int main(int argc, char ** argv) {
    MyTime test = MyTime(1162494284);
    std::cout << "Day: " << test.getDay() << std::endl;
    return 0;
}