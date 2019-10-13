#include "CustomRules.h"
#include "ConwayRules.h"

bool CustomRules::returnStatus(int neighbours, bool status)
{
	if (status == true && (neighbours < 0 || neighbours > 1)) {
		return false;
	}
	if (status == false && neighbours == 2) {
		return true;
	}
}
