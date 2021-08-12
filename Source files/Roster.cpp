#include <iostream>
#include <string>
#include "roster.h"
#include <iomanip>

using namespace std;


void Roster::add
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
)
{

	int daysInCourse[3] =
	{
		daysInCourse1,
		daysInCourse2,
		daysInCourse3
	};


	classRosterArray[index] =
		new Student
		(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysInCourse,
			degreeProgram
		);
	index++;

	return;
}


void Roster::printAll()
{
	cout << " Student Roster:  \n\n";

	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i] != nullptr) classRosterArray[i]->print();
	}
	printBuffer();
	return;
}


void Roster::printAvgDaysInCourse(string studentID)
{
	cout << " Average number of day's in a course:\n";

	int average = 0;
	int numCourses = 3;

	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID)
		{
			int* daysInCourse = classRosterArray[i]->getDaysInCourse();

			for (int j = 0; j < numCourses; j++)
			{
				average += daysInCourse[j];
			}

			cout << "\tStudent ID: " << classRosterArray[i]->getStudentID()
				<< " --- " << (average / numCourses) << " days\n\n";
		}
	}
	return;
	printBuffer();
}


void Roster::printInvalidEmails()
{
	for (int i = 0; i < rosterSize; i++)
	{
		bool isInvalid = false;
		int emailCheck = classRosterArray[i]->getEmail().find("@");

		if (emailCheck != string::npos)
		{
			emailCheck = classRosterArray[i]->getEmail().find(".");

			if (emailCheck != string::npos)
			{
				emailCheck = classRosterArray[i]->getEmail().find(" ");

				if (emailCheck == string::npos)
				{
					isInvalid = true;
				}
			}
		}

		if (!isInvalid)
		{
			cout << " Invalid email address: \n "
				<< classRosterArray[i]->getStudentID() << " --- "
				<< classRosterArray[i]->getEmail() << "\n\n";
		}
	}
	return;
	printBuffer();
}


void Roster::remove(string ID)
{
	bool idFound = false;
	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i] == nullptr) continue;

		if (classRosterArray[i]->getStudentID().compare(ID) == 0)
		{
			classRosterArray[i] = nullptr;
			idFound = true;
			cout << " Student ID '" << ID << "' was removed\n";
			printBuffer();
			break;
		}
	}
	if (idFound == false)
	{
		cout << setfill('*') << setw(30) << " No student with ID '" << ID << "' was found\n";
		printBuffer();
	}
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	string degree = "";

	switch (degreeProgram)
	{
	case DegreeProgram::SECURITY:
		degree = "SECURITY";
		break;
	case DegreeProgram::NETWORK:
		degree = "NETWORK";
		break;
	case DegreeProgram::SOFTWARE:
		degree = "SOFTWARE";
		break;
	}

	cout << " Student(s) with degree declared as " << degree << ":\n\n";

	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();

		}
	}
	return;
}

void Roster::printBuffer()
{
	cout << endl
		<< setfill('-') << setw(155) << "" << endl
		<< endl;
}

Roster::~Roster() {}