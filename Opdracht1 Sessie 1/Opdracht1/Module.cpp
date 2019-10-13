#include "Module.h"

Module::Module(string naam, int ec){
	mooduleNaam = naam;
	moduleEC = ec;
}

Module::~Module(){
	//TODO Opruimen Heap!! (Docent en studenten)
}

string Module::getNaam() { return mooduleNaam; }

int Module::setEC(int newEC) {
	moduleEC = newEC;
	return moduleEC;
}

int Module::getEC() { return moduleEC; }

void Module::addDocent(Docent* d)
{
	moduleDocent = d;
}

void Module::addStudent(Student* s)
{
	studenten.push_back(s);
}

void Module::removeStudent()
{
	std::vector<Student*>::iterator it = studenten.begin(); //Verwijder eerste leerling uit de lijst.
	studenten.erase(it);
}

string Module::getDocent()
{
	return moduleDocent->getNaam();
}

std::vector<Student*> Module::getStudents()
{
	return studenten;
}

void Module::updateEC()
{
	for (int i = 0; i < studenten.size(); i++)
	{
		studenten[i]->setEC(moduleEC);
	}
}


