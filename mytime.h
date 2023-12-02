#ifndef MYTIME
#define MYTIME

#include <string>
#include <iostream>

class MyTime {
private:
    unsigned int time;
public:
    // Constructor from raw int
    MyTime(unsigned int t): time(t) {}

    // Default constructor
    MyTime(): time(1162494284) {}

    // mm-dd-yyyy type constructor
    MyTime(int month, int day, int year) {
        this->time = year;
        this->time <<= 4;
        this->time += month;
        this->time <<= 5;
        this->time += day;
        this->time <<= 15;
    }

    // mm-dd-yy hh:mm type constructor
    MyTime(int month, int day, int year, int hour, int minute) {
        this->time = year;
        this->time <<= 4;
        this->time += month;
        this->time <<= 5;
        this->time += day;
        this->time <<= 5;
        this->time += hour;
        this->time <<= 2;
        this->time += (minute / 15);
        this->time <<= 2;
        this->time += ((minute % 15)  / 5);
        this->time <<= 6;
    }

    // mm-dd-yy hh:mm tz type constructor 
    MyTime(int month, int day, int year, int hour, int minute, std::string tz) {
        // TODO: Make this work ---------------------------------------------------------------------
    }

    unsigned int getRaw() {
        return time;
    }

    int getYear() {
        return ((this->time & 0xFF000000) >> 24) + 1900;
    }

    int getMonth() {
        return (this->time & 0x00F00000) >> 20;
    }

    std::string getMonthWord() {
        switch (this->getMonth()) {
            case 1:
                return "January";
            case 2:
                return "February";
            case 3:
                return "March";
            case 4:
                return "April";
            case 5:
                return "May";
            case 6:
                return "June";
            case 7:
                return "July";
            case 8:
                return "August";
            case 9:
                return "September";
            case 10:
                return "October";
            case 11:
                return "November";
            case 12:
                return "December";
            default:
                return "Error: invalid month value";
        }
    }

    int getDay() {
        return (this->time & 0x000F8000) >> 15;
    }

    int getHour() {
        unsigned int temp = (this->time & 0x00007C00) >> 10;
        return temp % 12 == 0 ? 12 : temp % 12;
    }

    int getMilHour() {
        return (this->time & 0x00007C00) >> 10;
    }

    int getQuarter() {
        return (this->time & 0x00000300) >> 8;
    }

    int getFiver() {
        return (this->time & 0x000000C0) >> 6;
    }

    int getMinutes() {
        return (this->getQuarter()*15) + (this->getFiver() * 5);
    }

    std::string getTZ() {
        switch(this->time & 0x0000003F) {
            case(0):
                return "UTC-12:00";
            case(1):
                return "UTC-11:00";
            case(2):
                return "UTC-10:00";
            case(3):
                return "UTC-09:30";
            case(4):
                return "UTC-09:00";
            case(5):
                return "UTC-08:00";
            case(6):
                return "UTC-07:00";
            case(7):
                return "UTC-06:00";
            case(8):
                return "UTC-05:00";
            case(9):
                return "UTC-04:00";
            case(10):
                return "UTC-03:30";
            case(11):
                return "UTC-03:00";
            case(12):
                return "UTC-02:00";
            case(13):
                return "UTC-01:00";
            case(14):
                return "UTC-00:00";
            case(15):
                return "UTC+01:00";
            case(16):
                return "UTC+02:00";
            case(17):
                return "UTC+03:00";
            case(18):
                return "UTC+03:30";
            case(19):
                return "UTC+04:00";
            case(20):
                return "UTC+04:30";
            case(21):
                return "UTC+05:00";
            case(22):
                return "UTC+05:30";
            case(23):
                return "UTC+05:45";
            case(24):
                return "UTC+06:00";
            case(25):
                return "UTC+06:30";
            case(26):
                return "UTC+07:00";
            case(27):
                return "UTC+08:00";
            case(28):
                return "UTC+08:45";
            case(29):
                return "UTC+09:00";
            case(30):
                return "UTC+09:30";
            case(31):
                return "UTC+10:00";
            case(32):
                return "UTC+10:30";
            case(33):
                return "UTC+11:00";
            case(34):
                return "UTC+12:00";
            case(35):
                return "UTC+12:45";
            case(36):
                return "UTC+13:00";
            case(37):
                return "UTC+14:00";
            default:
                return "Error: Invalid Timezone";
        }
    }

    void setYear(int year) {
        this->time &= 0x00FFFFFF;
        this->time += (year << 24);
    }

    void setMonth(int month) {
        this->time &= 0xFF0FFFFF;
        this->time += (month << 20);
    }

    void setDay(int day) {
        this->time &= 0xFFF07FFF;
        this->time += (day << 15);  
    }

    void setHour(int hour) {
        this->time &= 0xFFFF83FF;
        this->time += (hour << 10); 
    }

    void setQuarter(int quarter) {
        this->time &= 0xFFFFFCFF;
        this->time += (quarter << 8);  
    }

    void setFiver(int fiver) {
        this->time &= 0xFFFFFF3F;
        this->time += (fiver << 6);
    }

    void setMinutes(int minutes) {
        this->time &= 0xFFFFFC3F;
        this->time += ((minutes / 15) << 8) + (((minutes % 15) / 5) << 6);
    }

    void setTZ(std::string tz) {
        this->time &= 0xFFFFFFC0;
    }

    std::string toString() {
        return std::to_string(this->getMonth()) + "-" + \
        std::to_string(this->getDay()) +  "-" + \
        std::to_string(this->getYear()) + " " + \
        std::to_string(this->getHour()) + ":" + \
        std::to_string(this->getMinutes()) + " " + \
        (this->getMilHour() > 12 ? "PM" : "AM") + " " + \
        this->getTZ();
    }

    std::string getMilitary() {
        return std::to_string(this->getMonth()) + "-" + \
        std::to_string(this->getDay()) +  "-" + \
        std::to_string(this->getYear()) + " " + \
        std::to_string(this->getMilHour()) + ":" + \
        std::to_string(this->getMinutes()) + " " + \
        this->getTZ();
    }

    friend std::ostream & operator << (std::ostream& os, MyTime& f) {
        os << f.toString();
        return os;
    }
};

#endif