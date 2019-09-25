#include "School.h"

School::School()
{
	srand(time(0));
}

School::~School()
{
	//Is dit hoe het verwijderen van vectoren werkt op de heap?!?
	//TODO effectiever maken(?)

	std::vector<Module*>::iterator it = modules.begin();
	while (it != modules.end()) {
		delete* it;
		it++;
	}

	std::vector<Student*>::iterator it1 = studenten.begin();
	while (it1 != studenten.end()) {
		delete* it1;
		it1++;
	}

	std::vector<Docent*>::iterator it2 = docenten.begin();
	while (it2 != docenten.end()) {
		delete* it2;
		it2++;
	}
}


void School::printList()
{
	for (int i = 0; i < modules.size(); i++)
	{
		modules[i]->updateEC(); //Update de ec van alle studenten in de module.

		std::cout << "Module: \n" << modules[i]->getNaam() << " | EC: " << modules[i]->getEC() << std::endl;
		std::cout << "	Docent: " << modules[i]->getDocent() << "\n\n";
		std::cout << "	Studenten: \n " << std::endl;

		for (int j = 0; j < modules[i]->getStudents().size(); j++)
		{
			std::cout << "	|" << modules[i]->getStudents().at(j)->getNaam() << std::endl;
		}

	}

	std::cout << "\n\n\n Studenten met behaalde EC:" << std::endl;
	for (int j = 0; j < studenten.size(); j++)
	{
		std::cout << studenten[j]->getNaam() << " | " << studenten[j]->getEC() << std::endl;
	}

}

void School::defineObjects()
{
	modules.push_back(new Module("OBOPA", 3));
	modules.push_back(new Module("Kernmodule GameDev", 4));
	modules.push_back(new Module("Interface Design", 3));

	studenten.push_back(new Student("Mark"));
	studenten.push_back(new Student("Laura"));
	studenten.push_back(new Student("Leon"));
	studenten.push_back(new Student("Joey"));
	studenten.push_back(new Student("Beau"));
	studenten.push_back(new Student("Douwe"));
	studenten.push_back(new Student("Jael"));
	studenten.push_back(new Student("Anna"));
	studenten.push_back(new Student("Dennis"));
	studenten.push_back(new Student("Pim"));

	docenten.push_back(new Docent("Edwin"));
	docenten.push_back(new Docent("Aaron"));
	docenten.push_back(new Docent("Dimme"));
}

void School::assignObjects()
{
	for (int i = 0; i < modules.size(); i++)
	{
		modules[i]->addDocent(docenten[i]);

		int studentAmount = std::rand() % (studenten.size() +1);
		for (int j = 0; j < studentAmount; j++)
		{
			modules[i]->addStudent(studenten[j]); //TODO zorgen dat 2 mensen niet vaker voorkomen.
		}
	}

}

void School::changeModuleEC()
{
	modules[0]->setEC(2);
	for (int i = 0; i < studenten.size(); i++)
	{
		studenten[i]->resetEC();
	}
}

void School::removeFromModule()
{
	modules[std::rand() % (modules.size() + 1)]->removeStudent();

	for (int i = 0; i < studenten.size(); i++)
	{
		studenten[i]->resetEC();
	}
}



