#include "Docent.h"

Docent::Docent(std::string naam)
{
	docentNaam = naam;
}

Docent::~Docent()
{}

string Docent::getNaam()
{
	return docentNaam;
}
