#pragma once

#include "Notation.h"
#include "Stack.h"

class Int_Expression : public Notation
{
private:
	Stack<char>		Infix			= Stack<char>();
	Stack<char>		Postfix			= Stack<char>();
	Stack<char>		Prefix			= Stack<char>();

	bool			Can_Calculate	= true;
	int				Result			= 0;

	std::string		Get_Input();
	void			Output();
	void			GetPrefix(const std::string& Input);
	void			GetPostFix(const std::string& Input);
	int				CalculateExpression(const std::string& Input);

	bool			Is_Valid_Input(const char& c);
	bool			Is_Symbol(const char& c);
	int				Precedence(const char& c);
	int				Apply_Operator(const int& a, const int& b, const char& Operator);
	void			Reverse(Stack<char>& Stack);

public:
	void			Solve();
};