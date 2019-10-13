#pragma once
#include <iostream>
#include <vector>

#include "Docent.h"
#include "Student.h"

using string = std::string;

class Module
{
	public:	
		Module(string naam, int ec);
		~Module();

		string getNaam();
		int setEC(int newEC);
		int getEC();

		void addDocent(Docent* d);
		void addStudent(Student* s);

		void removeStudent();

		string getDocent();
		std::vector<Student*> getStudents(); //get functie voor studenten?

		void updateEC();

	private:
		int moduleEC;
		string mooduleNaam;

		Docent* moduleDocent;
		std::vector<Student*> studenten;
		

};

