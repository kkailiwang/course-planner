
#include "strlib.h"
#include "parser.h"


using namespace std;

course* digestCourse(Map<string, Set<course *>> &reqCourses, istream& file, TokenScanner scanner) {
//    if (!equalsIgnoreCase(file, "Course")) {
//        error("Expected another course, but didn't find it.");
//    }
    course* curr = new course;
    curr->sections = Vector<Map<string, Set<meetingTime>>*>(4, NULL);
    /*for (int i = 0; i < 4; i++) {
        (curr->sections)[i] = NULL; //in case it isn't offered all quarters
    }*/

    string line;
    getline(file, line);
    scanner.setInput(line);
    int quarterIndex;
    string section;
    meetingTime sectionSched;


    while(scanner.hasMoreTokens()) {
        scanner.verifyToken(">");
        string field = scanner.nextToken();
        if (field == "Course") {
            curr->courseID = scanner.nextToken();
        }
        else if (field == "Title") {
            curr->title = line.substr(6);
        }
        else if (field == "Units") {
            curr->units = stringToInteger(scanner.nextToken());
        }
        else if (field == "Term") {
            quarterIndex = quarterToIndex(scanner.nextToken());
            if ((curr->sections)[quarterIndex] == NULL) {
                (curr->sections)[quarterIndex] = new Map<string, Set<meetingTime>>;
            }
        }
        else if (field == "Component") {
            section = scanner.nextToken();
        }
        else if (field == "Days") {
            while (scanner.hasMoreTokens()) {
                int dayInt = dayToInt(scanner.nextToken());
                sectionSched = {dayInt, dayInt};
            }
        }
        else if (field == "Starttime") {
            sectionSched.start += timeToInt(scanner.nextToken(), scanner.nextToken());
        }
        else if (field == "Endtime") {
            sectionSched.end += timeToInt(scanner.nextToken(), scanner.nextToken());
            //the meetingTime is now completely formed
            (*((curr->sections)[quarterIndex]))[section].add(sectionSched); //adding the meetingTime to the appropriate place in course
        }
        else if (field == "Req") {
            while (scanner.hasMoreTokens()) {
                string currReq = scanner.nextToken();
                if (currReq == "none") {
                    break;
                }
                reqCourses[currReq].add(curr);
            }
        }
        else if (field == "Prereqs") {
            while (scanner.hasMoreTokens()) {
                string prereq = scanner.nextToken();
                if (prereq == "none") {
                    break;
                }
                curr->prereqs.add(prereq);
            }
        }
        else {
            error("unexpected field within course entry");
        }

        getline(file, line);
        scanner.setInput(line);
    }
    return curr;

}

void readCourses(Map<string, Set<course*>>& reqCourses, Map<string, course*>& courseIDMap, istream& file) {
    //TokenScanner scanner = new TokenScanner(file);
    //scanner.ignoreWhitespace();
    string nextWord;
    TokenScanner scanner(file);
    scanner.ignoreWhitespace();
    while (scanner.hasMoreTokens()) {

        course* currCourse = digestCourse(reqCourses, file, scanner);
        courseIDMap[currCourse->courseID] = currCourse;
    }

}

