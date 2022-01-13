//  Int_Expression.cpp : By Niall Starkey

//	HEADERS:
#include	<iostream>
#include	"Int_Expression.h"

//	Solves the expression, retrieving it from the user then outputting the solution and infix, postfix and prefix equation.
void Int_Expression::Solve()
{
	std::string Input = "";
	Input = Get_Input();	//	Gets the expression from the user.

	GetPrefix(Input);	//	Gets the prefix version of the expression.
	GetPostFix(Input);	//	Gets the postfix version of the expression.	
	Result = CalculateExpression(Input);	//	Calculates the result of the expression.

	Output();	//	Outputs the results to the user.
}

//	Gets the input from the user, ensuring it is valid before returning.
std::string Int_Expression::Get_Input()
{
	std::string Input = "";
	bool Input_Valid = false;

	//	Repeats until valid input entered.
	while (!Input_Valid)
	{
		system("CLS");
		std::cout << "Please enter an equation to convert: ";
		std::getline(std::cin, Input);

		//	Checks each character to ensure only allowed characters are entered.
		for (int i = 0; i < Input.length(); i++)
		{
			if (!Is_Valid_Input(Input[i])) { break; }
		}

		Input_Valid = true;
	}

	//	Pushes the equation onto the infix stack.
	for (int i = Input.length(); i >= 0; i--)
	{
		if (Input[i] != ' ')
		{
			Infix.Push(Input[i]);
		}
	}

	return Input;
}

//	Fills the prefix stack with the prefix notation of the expression.
void Int_Expression::GetPrefix(const std::string& Input)
{
	Stack<char> Expression = Stack<char>();
	Stack<char> Operators = Stack<char>();

	//	Get the infix expression from the Input.
	for (int i = 0; i < Input.length(); i++)
	{
		if (Input[i] != ' ')
		{
			Expression.Push(Input[i]);
		}
	}

	//	Loop until prefix expression is in stack.
	while (!Expression.Is_Empty() || !Operators.Is_Empty())
	{
		//	Pop letters and numbers to stack.
		if (isalnum(Expression.Top()))
		{
			Prefix.Push(Expression.Pop());
		}
		//	Push closed bracket into operators.
		else if (Expression.Top() == ')')
		{
			Operators.Push(Expression.Pop());
		}
		//	Pop from operators stack until finding a closed bracket if current char is an open bracket.
		else if (Expression.Top() == '(')
		{
			Expression.Pop();

			while (Operators.Top() != ')')
			{
				Prefix.Push(Operators.Pop());
			}

			Operators.Pop();
		}
		//	Push char to operators stack if it has equal or higher precedence than the top, else pop from stack until condition is met.
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

		//	Empty operators stack is expression is already empty.
		if (Expression.Is_Empty())
		{
			Prefix.Push(Operators.Pop());
		}
	}
}

//	Fills the postfix stack with the postfix notation of the expression.
void Int_Expression::GetPostFix(const std::string& Input)
{
	Stack<char> Expression = Stack<char>();
	Stack<char> Operators = Stack<char>();

	//	Get the infix expression from the Input.
	for (int i = Input.length(); i >= 0; i--)
	{
		if (Input[i] != ' ')
		{
			Expression.Push(Input[i]);
		}
	}

	//	Loop until postfix expression is in stack.
	while (!Expression.Is_Empty() || !Operators.Is_Empty())
	{
		//	Pop letters and numbers to stack.
		if (isalnum(Expression.Top()))
		{
			Postfix.Push(Expression.Pop());
		}
		//	Push open bracket into operators.
		else if (Expression.Top() == '(')
		{
			Operators.Push(Expression.Pop());
		}
		//	Pop operators until finding an open bracket, if current char is a closed bracket.
		else if (Expression.Top() == ')')
		{
			while (Operators.Top() != '(')
			{
				Postfix.Push(Operators.Pop());
			}

			Expression.Pop();
			Operators.Pop();
		}
		//	Pop operators if current char has lower or equal precedence to the top until condition is reversed.
		else
		{
			while (!Operators.Is_Empty() && Precedence(Expression.Top()) <= Precedence(Operators.Top()))
			{
				Postfix.Push(Operators.Pop());
			}

			Operators.Push(Expression.Pop());
		}

		//	Empty operators if expression is empty.
		if (Expression.Is_Empty())
		{
			Postfix.Push(Operators.Pop());
		}
	}

	//	Reverse the expression for output.
	Reverse(Postfix);
}

//	Calculate the numeric value of the expression.
int Int_Expression::CalculateExpression(const std::string& Input)
{
	Stack<int> Values = Stack<int>();
	Stack<char> Operators = Stack<char>();

	//	Loop through the input.
	for (int i = 0; i < Input.length(); i++)
	{
		if (Input[i] == ' ') { continue; }	//	Ignore spaces.
		//	Push bracket into operators.
		else if (Input[i] == '(')
		{
			Operators.Push(Input[i]);
		}
		//	Workout the value of the whole number if digit is found
		else if (isdigit(Input[i]))
		{
			int Num = 0;

			//	Loop through to find other digits.
			while (i < Input.length() && isdigit(Input[i]))
			{
				//	Add digit to total value.
				Num = (Num * 10) + (Input[i] - '0');
				i++;
			}

			//	Push number to values.
			Values.Push(Num);
			i--;
		}
		//	Workout value of operations inside brackets, if char is a closed bracket.
		else if (Input[i] == ')')
		{
			//	Loop until empty or open bracket found.
			while (!Operators.Is_Empty() && Operators.Top() != '(')
			{
				int Num2 = Values.Pop();
				int Num1 = Values.Pop();
				char Operator = Operators.Pop();

				//	Apply operator to operands and push result to values.
				Values.Push(Apply_Operator(Num1, Num2, Operator));
			}

			Operators.Pop();
		}
		//	Workout value of most precedent operation between two operands.
		else
		{
			//	Loops until values are obtained.
			while (!Operators.Is_Empty() && Precedence(Operators.Top() >= Precedence(Input[i])))
			{
				int Num2 = Values.Pop();
				int Num1 = Values.Pop();
				char Operator = Operators.Pop();

				//	Apply operator to operands and push result to values.
				Values.Push(Apply_Operator(Num1, Num2, Operator));
			}

			Operators.Push(Input[i]);
		}
	}

	//	Calculate values of final operations in stack.
	while (!Operators.Is_Empty())
	{
		int Num2 = Values.Pop();
		int Num1 = Values.Pop();
		char Operator = Operators.Pop();

		//	Apply operator to operands and push result to values.
		Values.Push(Apply_Operator(Num1, Num2, Operator));
	}

	// Return final value.
	return Values.Pop();
}

//	Output the infix, prefix and postfix expressions, as well as the result if possible.
void Int_Expression::Output()
{
	system("CLS");
	std::cout << "Expression conversion:" << std::endl << std::endl;

	//	Empty infix stack to console.
	std::cout << "Infix: ";
	while (!Infix.Is_Empty())
	{
		std::cout << Infix.Pop();
	}

	//	Empty prefix stack to console.
	std::cout << std::endl << "Prefix: ";
	while (!Prefix.Is_Empty())
	{
		std::cout << Prefix.Pop();
	}

	//	Empty postfix stack to console.
	std::cout << std::endl << "Postfix: ";
	while (!Postfix.Is_Empty())
	{
		std::cout << Postfix.Pop();
	}
	
	//	Output result if it can be calculated.
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

//	Return result of operation between two operands.
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

//	Return precedence of the current operator.
int Int_Expression::Precedence(const char& c)
{
	if (c == '/' || c == '*') { return 2; }
	if (c == '+' || c == '-') { return 1; }
	return 0;
}

//	Checks if the char is valid for an expression, and if it can be calculated or not.
bool Int_Expression::Is_Valid_Input(const char& c)
{
	std::string Symbols = "+-/*()";

	if (isalpha(c)) { Can_Calculate = false; return true; }	//	Cannot calculate expression with alphabetical characters.
	if (isdigit(c)) { return true; }
	if (isspace(c)) { return true; }
	if (Is_Symbol(c)) { return true; }

	return false;
}

//	Returns true if the char is one of the matching symbols.
bool Int_Expression::Is_Symbol(const char& c)
{
	std::string		Symbols = "+-/*()";

	if (Symbols.find(c) != std::string::npos) { return true; }	//	Checks if char is in the Symbols string.
	return false;
}

//	Reverse the contents of a stack.
void Int_Expression::Reverse(Stack<char>& Stack)
{
	std::string		String = "";

	//	Pop contents to a string.
	while (!Stack.Is_Empty())
	{
		String += Stack.Pop();
	}

	//	Push each char of string onto stack.
	for (int i = 0; i < String.length(); i++)
	{
		Stack.Push(String[i]);
	}
}