#pragma once
#include "RuleType.h"

class ConwayRules : public RuleType
{
	public:
		// Inherited via RuleType
		virtual bool returnStatus(int amount, bool status) override;
};

