#include "stdafx.h"
#include "Simplificator.h"
#include <vector>
#include "Token.h"
#include "Converter.h"
#include "Tokenizer.h"
#include "Evaluator.h"

void printRPN(const std::vector<Token>& vec)
{
	std::cout << "RPN: ";
	for (Token token : vec)
	{
		if (token.getType() == EOperator)
			std::cout << token.getValue().getOp().getSymbol() << " ";
		else
			std::cout << token.getValue().getNumber() << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::string str;
	Tokenizer tokenizer = Tokenizer();
	
	do {
		std::cout << "Infix: " ;
		std::cin >> str;

		Simplificator::simplify(str);
		try
		{
			printRPN(Converter::convert(tokenizer.tokenize(str)));
			std::cout << "Result: " << std::round(Evaluator::Evaluate(Converter::convert(tokenizer.tokenize(str)))*1000)/1000 << std::endl;
		}
		catch (std::runtime_error e)
		{
			std::cout << e.what() << std::endl;
		}
	} while (str != "exit");
    return 0;
}

