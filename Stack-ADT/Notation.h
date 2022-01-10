#pragma once

class Notation
{
public:
	virtual void	Solve()																= 0;
	virtual int		Precedence(const char& c)											= 0;
	virtual int		Apply_Operator(const int& a, const int& b, const char& Operator)	= 0;
	virtual void	Output()															= 0;

	virtual			~Notation()	{}
};

