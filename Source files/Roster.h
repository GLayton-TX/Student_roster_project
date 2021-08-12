#pragma once
#include <iostream>
#include <string>
#include "student.h"

using namespace std;

class Roster
{
public:

    int index = 0;
    Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    int rosterSize = (sizeof(classRosterArray) / sizeof(classRosterArray[0]));

    void add
    (
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram
    );
    void printAll();
    void printAvgDaysInCourse(string studentID);
    void printInvalidEmails();
    void remove(string studentID);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void parseData(const string studentData);
    void printBuffer();

    ~Roster();
};

