#include "Role.h"

class ShamanRole : public Role
{
	public:
		ShamanRole(NPC* npc);
		virtual ~ShamanRole();

		void render();
};

