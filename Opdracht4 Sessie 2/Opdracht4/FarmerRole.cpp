#include "FarmerRole.h"

FarmerRole::FarmerRole(NPC* npc) : Role(npc) {}

FarmerRole::~FarmerRole() {}

void FarmerRole::render()
{
	Role::render();
	std::cout << "Role: Farmer" << std::endl;
}
