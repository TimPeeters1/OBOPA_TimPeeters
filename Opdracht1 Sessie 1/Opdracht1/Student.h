#pragma once
#include <iostream>

//TODO Person superclass maken

class Student
{
	public:
		Student(std::string naam);
		~Student();

		std::string getNaam();

		void setEC(int newEC);
		int getEC();

		void resetEC();
	private:
		std::string studentNaam;
		int EC = 0;
};

