#pragma once
#include "Operator.h"

class TokenValue
{
protected:
	double number;
	Operator op;
public:
	TokenValue();
	explicit TokenValue(const char &c);
	explicit TokenValue(const double &num);
	double getNumber() const;
	Operator getOp() const;
	TokenValue(const TokenValue&);
	~TokenValue();
};
