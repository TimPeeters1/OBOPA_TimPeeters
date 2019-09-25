#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"

class GameOfLife {
	public:
		GameOfLife();

		void drawGrid();

		void clearGrid();

		Cell grid[26][26];
	private:
		int getNeighbours(int x, int y);
};