#pragma once
#include <iostream>
#include <vector>

#include "NPC.h"

class Role : public NPC
{
	public:
		Role(NPC* npc);
		virtual ~Role();

		virtual void render();
	private:
		NPC* theNPC;
};

