#include "GameOfLife.h"
#include "ConwayRules.h"

#include <chrono>
#include <thread>

GameOfLife::GameOfLife() {
	type = new ConwayRules();

	startGrid();
	drawGrid();
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));


	for (int i = 0; i < 500; i++)
	{
		nextGrid();
		drawGrid();
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
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
			grid[i][j].drawCell();
		}
		std::cout << "\n";
	}

	currentGrid();
}

void GameOfLife::currentGrid() {
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			grid[i][j].checkRules(getNeighbours(i, j), type);
			lastGrid[i][j] = grid[i][j];
		}
	}
}

void GameOfLife::nextGrid()
{
	clearGrid();
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			lastGrid[i][j].checkRules(getNeighbours(i, j), type);
			grid[i][j] = lastGrid[i][j];
		}
	}
}

void GameOfLife::startGrid() //Verander de i en j waarden voor aparte patronen.
{
	for (int j = 6; j < 20; j++)
	{	
		for (int i = 6; i < 15; i++)
		{
			grid[j][i].setStatus(true);
		}
	}
}

void GameOfLife::clearGrid()
{
	system("CLS");
}


