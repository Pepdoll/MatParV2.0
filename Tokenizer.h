#pragma once
#include "Token.h"

class Tokenizer
{
	enum State
	{
		init,
		err,
		numInt,
		numDec,
		op,
		fin
	};

protected:
	static State state;
	Token parseNum(const std::string&, size_t&);
	static int32_t parseInt(const std::string&, size_t&);
	static double parseDec(const std::string&, size_t&);
	static Token parseOp(const std::string&, size_t&);
	static double pow10(const uint8_t& num, const int8_t &power);
public:
	Tokenizer();
	std::vector<Token> tokenize(const std::string&);
	~Tokenizer();
};

