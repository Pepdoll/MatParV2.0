#include "stdafx.h"
#include "Operator.h"

Operator::Operator(): priority(0), symbol(0)
{
}

Operator::Operator(const Operator& obj): priority(obj.priority), symbol(obj.symbol)
{
}

Operator::Operator(const uint8_t &c) : symbol(c)
{
	switch (c)
	{
	case '+':
	case  '-':
	{
		priority = 1;
		break;
	}
	case '*':
		case '/':
	{
		priority = 2;
		break;
	}
		case '(':
		case ')':
		{
			priority = 0;
		}
	}
}

uint8_t Operator::getSymbol() const
{
	return symbol;
}

uint8_t Operator::getPriority() const
{
	return priority;
}

Operator::~Operator()
{
}
