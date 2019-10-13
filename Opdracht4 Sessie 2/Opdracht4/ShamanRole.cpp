#include "ShamanRole.h"

ShamanRole::ShamanRole(NPC* npc) : Role(npc){}

ShamanRole::~ShamanRole(){}

void ShamanRole::render()
{
	Role::render();
	std::cout << "Role: Shaman" << std::endl;
}
