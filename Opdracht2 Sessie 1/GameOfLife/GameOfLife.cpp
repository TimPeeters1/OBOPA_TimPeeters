#include "GameOfLife.h"
#include "ConwayRules.h"
#include "CustomRules.h"

#include <chrono>
#include <thread>

GameOfLife::GameOfLife() {
	//Parse new rulesets here !!!//

	type = new ConwayRules(); 
	//type = new CustomRules();

	//--------------------------//

	startGrid();
	drawGrid();
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));


	for (int i = 0; i < 500; i++)
	{
		currentGrid();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
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
}

void GameOfLife::currentGrid() {

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			lastGrid[i][j].setNeighbours(getNeighbours(i, j));
		}
	}

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			lastGrid[i][j] = grid[i][j];
		}
	}



	nextGrid();
}

void GameOfLife::nextGrid() {
	clearGrid();

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			grid[i][j].setNeighbours(getNeighbours(i, j));
		}
	}

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			grid[i][j].checkRules(type); 
		}
	}

	drawGrid();
}


void GameOfLife::startGrid() //Verander coordinaten van grid patroon om leuke vormpjes te maken :)
{

	//Huidige vorm is row van 10 die leuke 'explosies' maakt (Reference grid: https://bitstorm.org/gameoflife/)
	for (int i = 10; i < 20; i++)
	{
		grid[10][i].setStatus(true);
	}

}

void GameOfLife::clearGrid()
{
	system("CLS");
}


