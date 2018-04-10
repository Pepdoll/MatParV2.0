#pragma once
#include "Token.h"
#include <vector>

class Evaluator
{
	static Token doOperation(const Token& left, const Token& right, const Token& operation);
public: 
	Evaluator();
	static double Evaluate(const std::vector<Token>& tokens);
	~Evaluator();
};

