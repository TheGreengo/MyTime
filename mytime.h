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
        this->setTZ(tz);
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
        int val;
        int id = (tz.at(3) == '-' ? 0 : 10000) + 2*int(tz.at(4)) + 3*int(tz.at(5) + 5*int(tz.at(7)));
        switch(id) {
            case(968):
                val = 0;
                break;
            case(965):
                val = 1;
                break;
            case(962):
                val = 2;
                break;
            case(1032):
                val = 3;
                break;
            case(987):
                val = 4;
                break;
            case(984):
                val = 5;
                break;
            case(981):
                val = 6;
                break;
            case(978):
                val = 7;
                break;
            case(975):
                val = 8;
                break;
            case(972):
                val = 9;
                break;
            case(1014):
                val = 10;
                break;
            case(969):
                val = 11;
                break;
            case(966):
                val = 12;
                break;
            case(963):
                val = 13;
                break;
            case(960):
                val = 14;
                break;
            case(10963):
                val = 15;
                break;
            case(10966):
                val = 16;
                break;
            case(10969):
                val = 17;
                break;
            case(11014):
                val = 18;
                break;
            case(10972):
                val = 19;
                break;
            case(11017):
                val = 20;
                break;
            case(10975):
                val = 21;
                break;
            case(11020):
                val = 22;
                break;
            case(11035):
                val = 23;
                break;
            case(10978):
                val = 24;
                break;
            case(11023):
                val = 25;
                break;
            case(10981):
                val = 26;
                break;
            case(10984):
                val = 27;
                break;
            case(11044):
                val = 28;
                break;
            case(10987):
                val = 29;
                break;
            case(11032):
                val = 30;
                break;
            case(10962):
                val = 31;
                break;
            case(11007):
                val = 32;
                break;
            case(10965):
                val = 33;
                break;
            case(10968):
                val = 34;
                break;
            case(11028):
                val = 35;
                break;
            case(10971):
                val = 36;
                break;
            case(10974):
                val = 37;
                break;
            default:
                val = 62;
        }
        this->time &= 0xFFFFFFC0;
        this->time += val;
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