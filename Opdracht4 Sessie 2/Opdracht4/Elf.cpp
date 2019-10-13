#include "Elf.h"

Elf::Elf(std::string naam)
{
	thisNaam = naam;
}

Elf::~Elf()
{
}

void Elf::render()
{
	std::cout << "Elf: " << thisNaam << std::endl;
}
