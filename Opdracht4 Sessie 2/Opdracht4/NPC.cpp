#include "NPC.h"

#include "ShamanRole.h"
#include "SoldierRole.h"
#include "FarmerRole.h"

#include "Elf.h"
#include "Orc.h"

NPC::NPC()
{
}

NPC::~NPC()
{
}

NPC* NPC::createNPC(RoleType role, Species specie, std::string name)
{
	NPC* npc;
	RoleType thisRole = role;
	Species thisSpecie = specie;

	if (thisRole == shaman) {
		if (specie == orc) {
			npc = new ShamanRole(new Orc(name));
			return npc;
		}
		if (specie == elf) {
			npc = new ShamanRole(new Elf(name));
			return npc;
		}
	}
	else if (thisRole == soldier) {
		if (specie == orc) {
			npc = new SoldierRole(new Orc(name));
			return npc;
		}
		if (specie == elf) {
			npc = new SoldierRole(new Elf(name));
			return npc;
		}
	}
	else if (thisRole == farmer) {
		if (specie == orc) {
			npc = new FarmerRole(new Orc(name));
			return npc;
		}
		if (specie == elf) {
			npc = new FarmerRole(new Elf(name));
			return npc;
		}
	}


}

