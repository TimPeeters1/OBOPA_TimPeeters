#include "SoldierRole.h"

SoldierRole::SoldierRole(NPC* npc) : Role(npc) {}

SoldierRole::~SoldierRole() {}

void SoldierRole::render()
{
	Role::render();
	std::cout << "Role: Soldier" << std::endl;
}