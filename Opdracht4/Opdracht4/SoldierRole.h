#pragma once
#include "Role.h"
class SoldierRole : public Role
{
	public:
		SoldierRole(NPC* npc);
		virtual ~SoldierRole();

		void render();
};

