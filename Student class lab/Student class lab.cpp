// Student class lab.cpp : Defines the entry point for the console application.
//

// Student.h
#include "stdafx.h"
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int IdNumber;
	double gpa;
public:
	// constructors
	Student();  // default constructor
	Student(string n, int id, double g);

	//mutators and accessors
	void setName(string n);
	string getName();
	void setIdNumber(int id);
	int  getIdNumber();
	void setGpa(double g);
	double getGpa();
};

// Student.cpp - contains the code for the Student class member methods

#include "stdafx.h"     // only for Microsoft Visual Studio C++ programs
#include "Student.h"   //Include student class variables (public and private)
#include <cctype>      // used by isalpha (test for a character)
using namespace std;

// default Student constructor
Student::Student()
{
	name = "";  // set name to an empty string
	IdNumber = 0;
	gpa = 0.0;
}
// Fully qualified Student constructor
Student::Student(string n, int id, double g)
{
	setName(n);         // use setName to validate data
	setIdNumber(id);    // use setIdNumber to validate data
	setGpa(g);          // use setGpa to validate data (i.e. process errors)
}

//mutators and accessors
void Student::setName(string n)
{
	if (isupper(n[0]))   // 1st character of name must be A-Z
		name = n;
	else
		name = "--Bad name entered";
}
string Student::getName()
{
	return name;
}
void Student::setIdNumber(int id)
{
	if (id>1 && id<100000)   // must be from 0 to 100000
		IdNumber = id;
	else
		IdNumber = 0;          // indicate an illegal selection
}
int  Student::getIdNumber()
{
	return IdNumber;
}
void Student::setGpa(double g)
{
	if (g >= 0.0 && g <= 4.0)         // gpa must be from 0.0 to 4.0
		gpa = g;
	else
		gpa = 0;
}
double Student::getGpa()
{
	return gpa;
}

// Student_Class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"    // for some versions of Microsoft Visual C++
#include <iostream>
#include "Student.h"
using namespace std;

// define an array of students
Student CIS054[] = {
	Student("Joe Williams", 44536, 3.4),
	Student("Sally Washington", 55458, 3.7),
	Student("Fred MacIntosh", 66587, 2.9),
	Student("Jose De La Cruz", 67892, 3.5),
	Student("777 Dan McElroy", 77777, 4.0),
	Student("Thinh Nguyen", 73657, 3.6)
};


int main(int argc, char* argv[])
{
	int NumberOfStudents = sizeof(CIS054) / sizeof(Student);

	// Display the header line
	// List all the students in the course
	for (int i = 0; i<NumberOfStudents; i++)
		cout << "  " << CIS054[i].getIdNumber() << "  " << CIS054[i].getName() << endl;
	cout << endl;   // blank line after displaying the student names

					// compute the average gpa of all the students
	double total = 0;
	for (int i = 0; i<NumberOfStudents; i++)
		total += CIS054[i].getGpa();
	double average = total / NumberOfStudents;
	cout << "  " << "The average GPA of all the students is " << average << endl << endl;
	return 0;
}


