#include "Cell.h"


Cell::Cell(){
	//drawCell();
}

void Cell::drawCell()
{
	if (isAlive) {
		std::cout << " [] ";
	}
	else {
		std::cout << " * ";
	}
}

void Cell::checkRules(int neighbourAmount)
{

}

bool Cell::getStatus(){return isAlive;}


