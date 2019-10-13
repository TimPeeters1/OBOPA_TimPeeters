#include "ConwayRules.h"

bool ConwayRules::returnStatus(int neighbours, bool status)
{
	if (status == true && (neighbours < 2 || neighbours > 3)) {
		return false;
	}
	if (status == false && neighbours == 3) {
		return true;
	}
}
