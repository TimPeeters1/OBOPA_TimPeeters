#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> 



#include "Student.h"
#include "Docent.h"
#include "Module.h"

class School
{
	public:
		School();
		~School();

		void printList();
		void defineObjects(); //Deze void creert alle objecten (studenten, modules en docenten).

		void assignObjects();
		void changeModuleEC();

		void removeFromModule();
	private:
		std::vector<Module*> modules;
		std::vector<Student*> studenten;
		std::vector<Docent*> docenten;

};

