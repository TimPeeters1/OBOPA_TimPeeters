#include "Cell.h"


Cell::Cell(){

}

void Cell::drawCell()
{
	isAlive ?  std::cout << "*" : std::cout << "-";
}

void Cell::setNeighbours(int amount) {
	neighbourCount = amount;
}


void Cell::checkRules(RuleType* type)
{
	isAlive = type->returnStatus(neighbourCount, isAlive);
}

bool Cell::getStatus(){ return isAlive;}

bool Cell::setStatus(bool status)
{
	isAlive = status;
	return isAlive; 
}





