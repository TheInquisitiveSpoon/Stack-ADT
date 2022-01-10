#pragma once

#include <vector>
#include "Stack.h"

class NQueen
{
public:
	virtual void	Solve()		= 0;
	virtual void	NQUtil(std::vector<std::vector<int>>& Board, int Row)	= 0;
	virtual bool	Is_Safe(std::vector<std::vector<int>>& Board, int Row, int Col)	= 0;
	virtual void	Output()	= 0;

	virtual			~NQueen() {}
};

