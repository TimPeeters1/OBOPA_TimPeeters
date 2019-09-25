#pragma once
#include <iostream>

class Cell {
	public:
		Cell();

		void drawCell();
		void checkRules(int neighbourAmount);

		bool getStatus();

	private:
		bool isAlive;
};
