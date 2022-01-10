#pragma once

#include "NQueen.h"
#include "Stack.h"

class Basic_NQueen : public NQueen
{
private:
	int Board_Size = 0;
	int Num_Of_Solutions = 0;
	bool Solution_Exists = false;
	std::vector<std::vector<int>> Solutions;
	Stack<std::string> Results = Stack<std::string>();

	int		Get_Input();
	void	Output();
	void	NQUtil(std::vector<std::vector<int>>& Board, int Row);

	bool	Is_Safe(std::vector<std::vector<int>>& Board, int Row, int Col);

public:
	void	Solve();
};

