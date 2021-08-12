#include "Student.h"
#include<iostream>

using namespace std;

string Student::getStudentID()
{
	return studentId;
}

void Student::setStudentID(string sId)
{
	studentId = sId;
}

string Student::getFirstName()
{
	return firstName;
}

void Student::setFirstName(string fName)
{
	firstName = fName;
}

string Student::getLastName()
{
	return lastName;
}

void Student::setLastName(string lName)
{
	lastName = lName;
}

string Student::getEmail()
{
	return emailAddress;
}

void Student::setEmail(string email)
{
	emailAddress = email;
}

int Student::getAge()
{
	return age;
}

void Student::setAge(int inputAge)
{
	age = inputAge;
}

int* Student::getDaysInCourse()
{
	return daysInCourse;
}

void Student::setDaysInCourse(int* daysIn)
{
	for (int i = 0; i < 3; i++)
	{
		daysInCourse[i] = daysIn[i];
	}
	return;
}


DegreeProgram Student::getDegreeProgram()
{
	return programName;
}

void Student::setDegreeProgram(DegreeProgram program)
{

	programName = program;
}

void Student::print()
{
	int* daysInCourse = getDaysInCourse();

	cout << " " << getStudentID() << "\t"
		<< "First Name: " << getFirstName() << "\t"
		<< "Last Name: " << getLastName() << "\t"
		<< "Email: " << getEmail() << "\t"
		<< "Age: " << getAge() << "   "
		<< "Days in course's: " << daysInCourse[0] << ","
		<< daysInCourse[1] << "," << daysInCourse[2] << "\t"
		<< "Degree Program: ";

	switch (getDegreeProgram())
	{
	case DegreeProgram::SECURITY:
		cout << "SECURITY\t\n";
		break;
	case DegreeProgram::NETWORK:
		cout << "NETWORK\t\n";
		break;
	case DegreeProgram::SOFTWARE:
		cout << "SOFTWARE\t\n";
		break;
	}
	return;
}

Student::Student
(
	string sId,
	string fName,
	string lName,
	string email,
	int inputAge,
	int daysIn[3],
	DegreeProgram program
)
{
	setStudentID(sId);
	setFirstName(fName);
	setLastName(lName);
	setEmail(email);
	setAge(inputAge);
	setDaysInCourse(daysIn);
	setDegreeProgram(program);
}

