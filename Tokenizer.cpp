#include "stdafx.h"
#include "Tokenizer.h"

Tokenizer::State Tokenizer::state = Tokenizer::State::init;

Token Tokenizer::parseNum(const std::string& str, size_t& pos)
{
	auto neg = false;
	double number(0);
	if (str[pos] == '-')
	{
		neg = true;
	}
	if (str[pos] == '-' || str[pos] == '+')
		pos++;
	state = numInt;
	number += parseInt(str, pos);
	if (state == numDec)
	{
		number += parseDec(str, pos);
	}
	return (neg) ? Token(-number) : Token(number);
}

int32_t Tokenizer::parseInt(const std::string& str, size_t& pos)
{
	int32_t result(0);
	bool firstNum(true);
	while (str[pos] >= '0' && str[pos] <= '9' && pos < str.length())
	{
		if (!firstNum)
		{
			result *= 10;
		}
		else
		{
			firstNum = false;
		}
		result += str[pos] - '0';
		pos++;
	}
	if (str[pos] == '.')
	{
		pos++;
		state = numDec;
	}
	else
		if (str[pos] == '/' || str[pos] == '*' || str[pos] == '+'
			|| str[pos] == '-' || str[pos] == '(' || str[pos] == ')')
		{
			state = op;
		}
		else
			if (pos == str.length())
			{
				state = fin;
			}
			else
			{
				state = err;
			}
	return result;
}

double Tokenizer::parseDec(const std::string& str, size_t& pos)
{
	double res(0);
	size_t i(-1);
	while (str[pos] >= '0' && str[pos] <= '9' && pos < str.length())
	{
		res += pow10(str[pos] - '0', i);
		pos++;
		i--;
	}
	if (pos == str.length())
	{
		state = fin;
	}
	else
		if (str[pos] == '/' || str[pos] == '*' || str[pos] == '+'
			|| str[pos] == '-' || str[pos] == '(' || str[pos] == ')')
		{
			state = op;
		}
		else
		if (str[pos]=='.')
		{
			state = numDec;
		}
		else
		{
			state = err;
		}
	return res;

}

Token Tokenizer::parseOp(const std::string& str, size_t& pos)
{
	auto result = Token(str[pos]);
	pos++;
	if (pos == str.length())
	{
		state = fin;
	}
	else
		if (str[pos] >= '0' && str[pos] <= '9' || str[pos] == '.')
		{
			state = numDec;
		}
		else
			if (str[pos] == '/' || str[pos] == '*' || str[pos] == '+'
				|| str[pos] == '-' || str[pos] == '(' || str[pos] == ')')
			{
				state = op;
			}
			else
			{
				state = err;
			}
	return result;
}

double Tokenizer::pow10(const uint8_t& num, const int8_t& power)
{
	double res(num);
	auto tmp = abs(power);
	for (auto i(0); i < tmp; i++)
	{
		(power < 0) ? res /= 10 : res *= 10;
	}
	return res;
}

Tokenizer::Tokenizer()
{
}
std::vector<Token> Tokenizer::tokenize(const std::string& str)
{
	auto result = std::vector<Token>();
	state = init;
	size_t i(0);
	while (state != fin && state != err && i < str.length())
	{
		if (state == init)
		{
			if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			{
				result.push_back(parseNum(str, i));
			}
			else
				if (str[i] == '(')
				{
					state = op;
				}
				else
				{
					state = err;
				}
		}
		if (state == op)
		{
			result.push_back(parseOp(str, i));
		}
		if (state == numDec)
		{
			result.push_back(parseNum(str, i));
		}
		if (state == fin)
		{
			return result;
		}
		if (state == err)
		{
			throw std::runtime_error("Tokenizing error");
		}
	}
}

Tokenizer::~Tokenizer()
{
}
