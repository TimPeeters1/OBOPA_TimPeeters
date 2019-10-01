#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"

class GameOfLife {
	public:
		GameOfLife();

		void drawGrid();
		void currentGrid();
		void nextGrid();

		void startGrid();
		void clearGrid();

		Cell grid[26][26];
		Cell lastGrid[26][26];
		RuleType* type;
	private:
		int getNeighbours(int x, int y);
};