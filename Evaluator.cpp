#include "stdafx.h"
#include "Evaluator.h"

Token Evaluator::doOperation(const Token& left, const Token& right, const Token& operation)
{
	switch (operation.getValue().getOp().getSymbol())
	{
	case '+':
		return Token(left.getValue().getNumber() + right.getValue().getNumber());
	case '-':
		return Token(-left.getValue().getNumber() + right.getValue().getNumber());
	case '*':
		return Token(left.getValue().getNumber() * right.getValue().getNumber());
	case '/':
		return Token(right.getValue().getNumber() / left.getValue().getNumber());
	}
}

Evaluator::Evaluator()
{
}

double Evaluator::Evaluate(const std::vector<Token>& tokens)
{
	std::stack<Token> stack;
	for (Token token : tokens)
	{
		if (token.getType()==EOperand)
		{
			stack.push(token);
		}
		else
		{
			Token tmp1;
			Token tmp2;
			if (!stack.empty() && stack.top().getType() == EOperand)
			{
				tmp1 = stack.top();
				stack.pop();
			}
			else
				throw std::runtime_error("Something gone wrong!");

			if (!stack.empty() && stack.top().getType() == EOperand)
			{
			tmp2 = stack.top();
			stack.pop();
			}
			else
				throw std::runtime_error("Something gone wrong!");
			stack.push(doOperation(tmp1, tmp2, token));
		}
	}
	if (stack.size() == 1)
	{
		return stack.top().getValue().getNumber();
	}
	else
	{
		throw std::runtime_error("Something gone wrong! Missing Operators!");
	}
}

Evaluator::~Evaluator()
{
}
