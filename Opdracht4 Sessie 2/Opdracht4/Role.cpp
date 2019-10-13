#include "Role.h"

Role::Role(NPC* npc)
{
	theNPC = npc;
}

Role::~Role()
{
	if (theNPC) delete theNPC;
}

void Role::render()
{
	theNPC->render();
}
