#include "Cell.h"


Cell::Cell(){

}

void Cell::drawCell()
{
	isAlive ?  std::cout << "*" : std::cout << "-";
}

void Cell::checkRules(int neighbourAmount, RuleType* type)
{
	isAlive = type->returnStatus(neighbourAmount, isAlive);
}

bool Cell::getStatus(){ return isAlive;}

bool Cell::setStatus(bool status)
{
	isAlive = status;
	return isAlive; 
}





