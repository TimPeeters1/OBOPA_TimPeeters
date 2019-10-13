#pragma once
#include <iostream>
#include <vector>

typedef enum RoleType{farmer, shaman, soldier};

typedef enum Species{elf, orc};

class NPC
{
	public:
		NPC();
		virtual ~NPC();

		static NPC* createNPC(RoleType role, Species specie, std::string name);

		virtual void render() = 0;
	private:
		std::string name;
};

