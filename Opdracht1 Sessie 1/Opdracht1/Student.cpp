#include "Student.h"

Student::Student(std::string naam)
{
	studentNaam = naam;
}

Student::~Student()
{}

std::string Student::getNaam()
{
	return studentNaam;
}

void Student::setEC(int newEC)
{
	EC += newEC;
}

int Student::getEC() { return EC; }

void Student::resetEC()
{
	EC = 0;
}


