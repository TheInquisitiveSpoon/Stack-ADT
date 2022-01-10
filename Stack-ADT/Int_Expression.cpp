#include <iostream>
#include "Int_Expression.h"

void Int_Expression::Solve()
{
	std::string Input = "";
	Input = Get_Input();

	GetPrefix(Input);
	GetPostFix(Input);
	Result = CalculateExpression(Input);

	Output();
}

std::string Int_Expression::Get_Input()
{
	std::string Input = "";
	bool Input_Valid = false;

	while (!Input_Valid)
	{
		system("CLS");
		std::cout << "Please enter an equation to convert: ";
		std::getline(std::cin, Input);

		for (int i = 0; i < Input.length(); i++)
		{
			if (!Is_Valid_Input(Input[i])) { break; }
		}

		Input_Valid = true;
	}

	for (int i = Input.length(); i >= 0; i--)
	{
		if (Input[i] != ' ')
		{
			Infix.Push(Input[i]);
		}
	}

	return Input;
}


void Int_Expression::GetPrefix(const std::string& Input)
{
	Stack<char> Expression = Stack<char>();
	Stack<char> Operators = Stack<char>();

	for (int i = 0; i < Input.length(); i++)
	{
		if (Input[i] != ' ')
		{
			Expression.Push(Input[i]);
		}
	}

	while (!Expression.Is_Empty() || !Operators.Is_Empty())
	{
		if (isalnum(Expression.Top()))
		{
			Prefix.Push(Expression.Pop());
		}
		else if (Expression.Top() == ')')
		{
			Operators.Push(Expression.Pop());
		}
		else if (Expression.Top() == '(')
		{
			Expression.Pop();

			while (Operators.Top() != ')')
			{
				Prefix.Push(Operators.Pop());
			}

			Operators.Pop();
		}
		else
		{
			if (Precedence(Expression.Top()) >= Precedence(Operators.Top()))
			{
				Operators.Push(Expression.Pop());
			}
			else
			{
				do
				{
					Prefix.Push(Operators.Pop());
				} while (Precedence(Expression.Top()) < Precedence(Operators.Top()));
			}
		}

		if (Expression.Is_Empty())
		{
			Prefix.Push(Operators.Pop());
		}
	}
}

void Int_Expression::GetPostFix(const std::string& Input)
{
	Stack<char> Expression = Stack<char>();
	Stack<char> Operators = Stack<char>();

	for (int i = Input.length(); i >= 0; i--)
	{
		if (Input[i] != ' ')
		{
			Expression.Push(Input[i]);
		}
	}

	while (!Expression.Is_Empty() || !Operators.Is_Empty())
	{
		if (isalnum(Expression.Top()))
		{
			Postfix.Push(Expression.Pop());
		}
		else if (Expression.Top() == '(')
		{
			Operators.Push(Expression.Pop());
		}
		else if (Expression.Top() == ')')
		{
			while (Operators.Top() != '(')
			{
				Postfix.Push(Operators.Pop());
			}

			Expression.Pop();
			Operators.Pop();
		}
		else
		{
			while (!Operators.Is_Empty() && Precedence(Expression.Top()) <= Precedence(Operators.Top()))
			{
				Postfix.Push(Operators.Pop());
			}

			Operators.Push(Expression.Pop());
		}

		if (Expression.Is_Empty())
		{
			Postfix.Push(Operators.Pop());
		}
	}

	Reverse(Postfix);
}

int Int_Expression::CalculateExpression(const std::string& Input)
{
	Stack<int> Values = Stack<int>();
	Stack<char> Operators = Stack<char>();

	for (int i = 0; i < Input.length(); i++)
	{
		if (Input[i] == ' ') { continue; }
		else if (Input[i] == '(')
		{
			Operators.Push(Input[i]);
		}
		else if (isdigit(Input[i]))
		{
			int Num = 0;

			while (i < Input.length() && isdigit(Input[i]))
			{
				Num = (Num * 10) + (Input[i] - '0');
				i++;
			}

			Values.Push(Num);
			i--;
		}
		else if (Input[i] == ')')
		{
			while (!Operators.Is_Empty() && Operators.Top() != '(')
			{
				int Num2 = Values.Pop();
				int Num1 = Values.Pop();
				char Operator = Operators.Pop();

				Values.Push(Apply_Operator(Num1, Num2, Operator));
			}

			Operators.Pop();
		}
		else
		{
			while (!Operators.Is_Empty() && Precedence(Operators.Top() >= Precedence(Input[i])))
			{
				int Num2 = Values.Pop();
				int Num1 = Values.Pop();
				char Operator = Operators.Pop();

				Values.Push(Apply_Operator(Num1, Num2, Operator));
			}

			Operators.Push(Input[i]);
		}
	}

	while (!Operators.Is_Empty())
	{
		int Num2 = Values.Pop();
		int Num1 = Values.Pop();
		char Operator = Operators.Pop();

		Values.Push(Apply_Operator(Num1, Num2, Operator));
	}

	return Values.Top();
}

void Int_Expression::Output()
{
	system("CLS");
	std::cout << "Expression conversion:" << std::endl << std::endl;

	std::cout << "Infix: ";
	while (!Infix.Is_Empty())
	{
		std::cout << Infix.Pop();
	}

	std::cout << std::endl << "Prefix: ";
	while (!Prefix.Is_Empty())
	{
		std::cout << Prefix.Pop();
	}

	std::cout << std::endl << "Postfix: ";
	while (!Postfix.Is_Empty())
	{
		std::cout << Postfix.Pop();
	}
	
	if (Can_Calculate)
	{
		std::cout << std::endl << "Result: " << Result;
		std::cout << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << std::endl;
	}
	system("PAUSE");
}

int Int_Expression::Apply_Operator(const int& a, const int& b, const char& Operator)
{
	switch (Operator)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
}

int Int_Expression::Precedence(const char& c)
{
	if (c == '/' || c == '*') { return 2; }
	if (c == '+' || c == '-') { return 1; }
	return 0;
}

bool Int_Expression::Is_Valid_Input(const char& c)
{
	std::string Symbols = "+-/*()";

	if (isalpha(c)) { Can_Calculate = false; return true; }
	if (isdigit(c)) { return true; }
	if (isspace(c)) { return true; }
	if (Is_Symbol(c)) { return true; }

	return false;
}

bool Int_Expression::Is_Symbol(const char& c)
{
	std::string		Symbols = "+-/*()";

	if (Symbols.find(c) != std::string::npos) { return true; }
	return false;
}

void Int_Expression::Reverse(Stack<char>& Stack)
{
	std::string		String = "";

	while (!Stack.Is_Empty())
	{
		String += Stack.Pop();
	}

	for (int i = 0; i < String.length(); i++)
	{
		Stack.Push(String[i]);
	}
}