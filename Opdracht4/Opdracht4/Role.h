#pragma once
#include "NPC.h"

class Role
{
	private:
		NPC* theNPC;
	public:
		Role(NPC* npc);
		virtual ~Role();

		virtual void render();
};

