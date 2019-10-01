#pragma once
#include <iostream>

#include "RuleType.h";

class Cell {
	public:
		Cell();

		void drawCell();
		void checkRules(int neighbourAmount, RuleType* rules);

		bool getStatus();
		bool setStatus(bool status);
	private:
		bool isAlive;
		
};
