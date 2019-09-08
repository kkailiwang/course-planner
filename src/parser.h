
#ifndef PARSER_H
#define PARSER_H
#pragma once

#include "tokenscanner.h"
#include <iostream>
#include "filelib.h"
#include "set.h"
#include "util.h"
//include the files with the structs i'm loading in.

course* digestCourse(Map<string, Set<course*>>& reqCourses, istream &file, TokenScanner scanner);

void readCourses(Map<string, Set<course*>>& reqCourses, Map<string, course*>& courseIDMap, istream& file);

#endif // PARSER_H
