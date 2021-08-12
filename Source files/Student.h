#pragma once
#include<string>
#include "Degree.h"

using namespace std;

class Student {

public:

	string getStudentID();
	void setStudentID(string sId);

	string getFirstName();
	void setFirstName(string fName);

	string getLastName();
	void setLastName(string lName);

	string getEmail();
	void setEmail(string email);

	int getAge();
	void setAge(int inputAge);

	int* getDaysInCourse();
	void setDaysInCourse(int daysIn[3]);

	DegreeProgram getDegreeProgram();
	void setDegreeProgram(DegreeProgram program);

	void print();


	Student
	(
		string sId,
		string fName,
		string lName,
		string email,
		int inputAge,
		int daysIn[3],
		DegreeProgram program
	);



private:

	string studentId = "";
	string firstName = "";
	string lastName = "";
	string emailAddress = "";
	int age = 0;
	int daysInCourse[3] = { 0 };
	DegreeProgram programName = DegreeProgram::SECURITY;

};