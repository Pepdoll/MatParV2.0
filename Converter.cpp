#include "stdafx.h"
#include "Converter.h"

Converter::Converter()
{
}

std::vector<Token> Converter::convert(const std::vector<Token>& expression)
{
	std::vector<Token> result;
	std::stack<Token> stack;
	for (Token token : expression)
	{
		if (token.getType() == EOperand)
		{
			result.push_back(token);
		}
		else
		{
			Operator op = token.getValue().getOp();
			if (op.getSymbol() == '(')
			{
				stack.push(token);
			}
			else
			if (op.getSymbol() == ')')
			{
				while (!stack.empty() && stack.top().getValue().getOp().getSymbol() != '(')
				{
					result.push_back(stack.top());
					stack.pop();
				}
				if (!stack.empty())
				{
					stack.pop();
				}
				else
				{
					throw std::runtime_error("Error in converting to RPN. Missing parenthesis");
				}
			}
			else
			if (!stack.empty())
			{
				if (stack.top().getValue().getOp().getPriority() < op.getPriority())
				{
					stack.push(token);
				}
				else
				{
					while ( !stack.empty() && op.getPriority()<=stack.top().getValue().getOp().getPriority() )
					{
						result.push_back(stack.top());
						stack.pop();
					}
					stack.push(token);
				}
			}
			else
			{
				stack.push(token);
			}
		}
	}
	while (!stack.empty())
	{
		if (stack.top().getValue().getOp().getSymbol() != '(')
		{
			result.push_back(stack.top());
			stack.pop();
		}
		else
		{
			throw std::runtime_error("Error in converting to RPN. Missing parenthesis");
		}
	}
	return result;
}

Converter::~Converter()
{
}
