#pragma once
class RuleType
{
public:
	virtual ~RuleType();
	RuleType();
	virtual bool returnStatus(int amount, bool status) =0;
};

