#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <string>
#include "vector.h"
#include "map.h"
#include "set.h"
using namespace std;

struct meetingTime {
    int start;
    int end;
};

struct course {
    string courseID;
    string title;
    int units;
    Vector<Map<string, Set<meetingTime>>*> sections; //this will be a 4-element vector (one cell per quarter)
    Set<string> prereqs;
    //string description;
};

struct chosenCourse {
    course* coursep;
    Map<string, Vector<meetingTime>> sched;
    string reqfulfilled; //should this be a req pointer or just the name of the req?
};

struct quarter {
    int totalUnits;
    Vector<chosenCourse> courses;

};

int quarterToIndex(string quarter);

int dayToInt(string day);

int timeToInt(string time, string ampm);

bool operator<(meetingTime x, meetingTime y);

#endif // UTIL_H


