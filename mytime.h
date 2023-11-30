#ifndef MYTIME
#define MYTIME

class MyTime {
private:
    unsigned int time;
public:
    MyTime(unsigned int t): time(t) {}

    // this needs reworking, there's no way it actually does stuff
    int getDay() {
        unsigned int result = this->time;
        result = result & 0x000F8000;
        result = result >> 15;
        return result;
    }
};

#endif