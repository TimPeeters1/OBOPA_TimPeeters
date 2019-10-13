#pragma once
#include "NPC.h"

class Elf : public NPC
{
	public:
		Elf(std::string naam);
		virtual ~Elf();

		void render();

	private:
		std::string thisNaam;
};

