//  Basic_NQueen.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	"NQueen.h"
#include	"Stack.h"

//	Basic_NQueen class.
class Basic_NQueen : public NQueen
{
private:
	//	VARIABLES:
	int								Board_Size = 0;
	int								Num_Of_Solutions = 0;
	int								Squares_Scanned = 0;
	int								Total_Queens_Placed = 0;
	bool							Solution_Exists = false;
	std::vector<std::vector<int>>	Solutions;
	Stack<std::string>				Results = Stack<std::string>();

	//	FUNCTIONS:
	int		Get_Input();
	void	Output();
	bool	NQUtil(std::vector<std::vector<int>>& Board, int Row);
	bool	Is_Safe(std::vector<std::vector<int>>& Board, int Row, int Col);

public:
	void	Solve();
};

