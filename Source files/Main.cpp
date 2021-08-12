#include "Roster.h"
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<vector>

using namespace std;



int main()
{

    cout << " SCRIPTING AND PROGRAMMING APPLICATIONS C867\n"
        << " Using C++\n"
        << " Student ID: 001189396\n"
        << " Gregory Layton\n\n"
        << setfill('-') << setw(155) << "\n\n";


    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Gregory,Layton,glayto1@WGU.edu\t,40,10,20,30,SOFTWARE"
    };


    Roster classRoster;

    for (int i = 0; i < classRoster.rosterSize; i++)
    {
        string studentVal;
        string parseArray[9];
        DegreeProgram parseDegree = DegreeProgram::SOFTWARE;
        string input = studentData[i];
        istringstream studentString(input);
        int j = 0;

        while (getline(studentString, studentVal, ','))
        {
            parseArray[j] = studentVal;
            j++;
        }

        if (parseArray[8] == "NETWORK") parseDegree = DegreeProgram::NETWORK;

        else if (parseArray[8] == "SECURITY") parseDegree = DegreeProgram::SECURITY;

        else if (parseArray[8] == "SOFTWARE") parseDegree = DegreeProgram::SOFTWARE;

        classRoster.add
        (
            parseArray[0],
            parseArray[1],
            parseArray[2],
            parseArray[3],
            stoi(parseArray[4]),
            stoi(parseArray[5]),
            stoi(parseArray[6]),
            stoi(parseArray[7]),
            parseDegree
        );
    }



    classRoster.printAll();
    classRoster.printInvalidEmails();
    classRoster.printBuffer();

    for (int i = 0; i < classRoster.rosterSize; i++)
    {
        classRoster.printAvgDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    classRoster.printBuffer();

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.printBuffer();

    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}


