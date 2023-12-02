#include <iostream>
#include "mytime.h"

int main(int argc, char ** argv) {
    MyTime test = MyTime(1162494284);
    std::cout << "Year: " << test.getYear() << std::endl;
    std::cout << "Month: " << test.getMonthWord() << std::endl;
    std::cout << "Day: " << test.getDay() << std::endl;
    std::cout << "Hour: " << test.getHour() << std::endl;
    std::cout << "Quarter: " << test.getQuarter() << std::endl;
    std::cout << "Fiver: " << test.getFiver() << std::endl;
    std::cout << "TZ: " << test.getTZ() << std::endl;
    std::cout << "1162494284 vs. " << test.getRaw() << std::endl;
    return 0;
}