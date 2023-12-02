#ifndef MYTIME
#define MYTIME

// test date: 1162494284 (should be 4-20-69 4:20 tz:12)

class MyTime {
private:
    unsigned int time;
public:
    MyTime(unsigned int t): time(t) {}

    unsigned int getRaw() {
        return time;
    }
    // this needs reworking, there's no way it actually does stuff
    int getDay() {
        unsigned int result = this->time;
        result = result & 0x000F8000;
        result = result >> 15;
        return result;
    }
};

#endif