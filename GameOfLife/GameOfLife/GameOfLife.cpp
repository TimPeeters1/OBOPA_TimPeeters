#include "GameOfLife.h"

GameOfLife::GameOfLife() {
	drawGrid();
}

int GameOfLife::getNeighbours(int x, int y)
{
	/* Coordinate representation of neighbours
		(-1,1) (0,1)  (1,1)
		(-1,0)  CELL  (1,0)
		(-1,-1)(0,-1)(1,-1)
	*/

	int center = 0;
	//Top Row
	center += (grid[x - 1][y + 1].getStatus() == 1);
	center += (grid[x][y + 1].getStatus() == 1);
	center += (grid[x + 1][y + 1].getStatus() == 1);
	//Middle Row
	center += (grid[x - 1][y].getStatus() == 1);
	center += (grid[x + 1][y].getStatus() == 1);
	//Bottom Row
	center += (grid[x - 1][y - 1].getStatus() == 1);
	center += (grid[x][y - 1].getStatus() == 1);
	center += (grid[x + 1][y - 1].getStatus() == 1);
	return center;
}

void GameOfLife::drawGrid()
{
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			Cell cellObject;
			cellObject.checkRules(getNeighbours(j, i));
		}
	}
}

void GameOfLife::clearGrid()
{
	system("CLS");
}


