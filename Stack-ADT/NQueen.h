//  NQueen.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	<vector>
#include	"Stack.h"

//	NQueen class.
class NQueen
{
public:
	//	FUNCTIONS:
	virtual void	Solve()		= 0;
	virtual bool	NQUtil(std::vector<std::vector<int>>& Board, int Row)	= 0;
	virtual bool	Is_Safe(std::vector<std::vector<int>>& Board, int Row, int Col)	= 0;
	virtual void	Output()	= 0;

	virtual			~NQueen() {}
};

