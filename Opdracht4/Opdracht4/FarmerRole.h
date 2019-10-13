#pragma once
#include "Role.h"
class FarmerRole : public Role
{
	public:
		FarmerRole(NPC* npc);
		virtual ~FarmerRole();

		void render();
};

