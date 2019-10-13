#pragma once
#include <iostream>

#include "RuleType.h";

class Cell {
	public:
		Cell();

		void drawCell();
		void setNeighbours(int amount);
		void checkRules(RuleType* rules);

		bool getStatus();
		bool setStatus(bool status);
	private:
		bool isAlive;

		int neighbourCount;
		
};
