#pragma once
class RuleType
{
public:
	virtual ~RuleType();
	RuleType();
	virtual bool returnStatus() =0;
};

