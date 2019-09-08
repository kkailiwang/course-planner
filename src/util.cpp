#include "util.h"
#include "error.h"
#include "strlib.h"
using namespace std;

int quarterToIndex(string quarter) {
    if (quarter == "Autumn") {
        return 0;
    }
    if (quarter == "Winter") {
        return 1;
    }
    if (quarter == "Spring") {
        return 2;
    }
    if (quarter == "Summer") {
        return 3;
    }
    error("Unable to interpret quarter term name.");
    return -1;
}

int dayToInt(string day) {
    if (day == "Monday") {
        return 10000;
    }
    if (day == "Tuesday") {
        return 20000;
    }
    if (day == "Wednesday") {
        return 30000;
    }
    if (day == "Thursday") {
        return 40000;
    }
    if (day == "Friday") {
        return 50000;
    }
    error("Unable to interpret Day");
    return -1;

}

int timeToInt(string time, string ampm) {
    int timeNum = 0;
    if (ampm == "PM") {
        timeNum += 1200; //because this is in army time
    }
    timeNum += stringToInteger(time.substr(0, 2) + time.substr(3, 2));
    return timeNum;
}

bool operator<(meetingTime x, meetingTime y) {
    if (x.end - x.start < y.end - y.start) {
        return true;
    }
    return false;
}
