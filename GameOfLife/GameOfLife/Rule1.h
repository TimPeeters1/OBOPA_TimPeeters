#pragma once
#include "RuleType.h"

class Rule1 : public RuleType
{
	// Inherited via RuleType
	virtual bool returnStatus() override;
};

