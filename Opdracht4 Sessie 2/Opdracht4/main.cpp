#include <iostream>
#include <vector>

#include "NPC.h"

int main()
{
	NPC* npc1;
	RoleType type1 = shaman;
	Species specie1 = orc;

	std::cout << "NPC 1 :" << std::endl;
	npc1 = NPC::createNPC(type1, specie1, "Morgat");
	npc1->render();

	NPC* npc2;
	RoleType type2 = soldier;
	Species specie2 = elf;

	std::cout << "NPC 2 :" << std::endl;
	npc2 = NPC::createNPC(type2, specie2, "Arwen");
	npc2->render();
	
	return 0;
}

