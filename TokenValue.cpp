#include "stdafx.h"
#include "TokenValue.h"


TokenValue::TokenValue(): number(0), op()
{
}

TokenValue::TokenValue(const char& c): number(0), op(c)
{

}

TokenValue::TokenValue(const double& num): number(num), op()
{
}

double TokenValue::getNumber() const
{
	return number;
}

Operator TokenValue::getOp() const
{
	return op;
}

TokenValue::TokenValue(const TokenValue& obj): number(obj.number), op(obj.op)
{

}

TokenValue::~TokenValue()
{
}
