#include "Orc.h"

Orc::Orc(std::string naam)
{
	thisNaam = naam;
}

Orc::~Orc()
{
}

void Orc::render()
{
	std::cout << "Orc: " << thisNaam << std::endl;
}
