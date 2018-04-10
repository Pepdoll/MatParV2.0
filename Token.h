#pragma once
#include "TokenValue.h"
enum TokenType
{
	EOperator,
	EOperand,
};
class Token
{
protected:
	TokenType type;
	TokenValue value;
public:
	Token();
	Token(const char &);
	Token(const double &);
	Token(const Token& obj);
	TokenType getType() const;
	TokenValue getValue() const;
	Token& operator=(const Token& obj);
	~Token();
};
