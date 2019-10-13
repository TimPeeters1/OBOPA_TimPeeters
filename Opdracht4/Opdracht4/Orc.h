#pragma once
#include "NPC.h"
class Orc : public NPC
{
	public:
		Orc(std::string naam);
		virtual ~Orc();

		void render();
	private:
		std::string thisNaam;
};

