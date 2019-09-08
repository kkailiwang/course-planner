#include <iostream>
#include "console.h"
#include "constraints.h"
#include "parser.h"
#include "util.h"
#include "set.h"
#include <fstream>

using namespace std;

void printWelcome() {

}

int main() {
    //welcome message
    printWelcome();
    // prompt for track of cs

    //create structures
    /*Map<string, req> generalReqs;
    buildGeneralReqMap(generalReqs);
    Map<string, int> yearSpecificReqs;
    buildYearSpecificReqMap(yearSpecificReqs)*/;

    Map<string, Set<course*>> reqCourses;
    Map<string, course*> courseIDMap;


    string filename = "csdata3.txt";
    ifstream file(filename.c_str());
    if (file.fail()) {
        cout << "failed to open file";
    }
    //file.open(filename.c_str()); //this will later be based on user input.
    readCourses(reqCourses, courseIDMap, file);


  //parse the files.
  return 0;
}
