#pragma once
#include <string>

#include "Role.h"

typedef enum species{ elf, orc };

class NPC
{
	public:
		NPC();
		virtual ~NPC();

		static Role* setRole(); 

		virtual void render() = 0;
	private:
		std::string name;
};

