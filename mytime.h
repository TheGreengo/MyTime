#ifndef MYTIME
#define MYTIME

#include <string>

class MyTime {
private:
    unsigned int time;
public:
    MyTime(unsigned int t): time(t) {}
    MyTime(int month, int day, int year) {
        
    }
    MyTime(int month, int day, int year, int hour, int minute) {
        
    }
    MyTime(int month, int day, int year, int hour, int minute, std::string tz) {
        
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
        return (this->time & 0x00007C00) >> 10;
    }

    int getQuarter() {
        return (this->time & 0x00000300) >> 8;
    }

    int getFiver() {
        return (this->time & 0x000000C0) >> 6;
    }

    int getTZ() {
        return this->time & 0x0000003F;
    }

    void setYear() {
        
    }

    void setMonth() {
        
    }

    void setDay() {
        
    }

    void setHour() {
        
    }

    void setQuarter() {
        
    }

    void setFiver() {
        
    }

    void setMinutes() {
        
    }

    void setTZ() {
        
    }

    std::string toString() {
        return "lolz";
    }
};

#endif