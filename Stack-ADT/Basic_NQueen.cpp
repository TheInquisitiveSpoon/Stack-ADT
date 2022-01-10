#include <iostream>
#include <string>
#include <vector>
#include "Basic_NQueen.h"

void Basic_NQueen::Solve()
{
	Board_Size = Get_Input();

	std::vector<std::vector<int>> Board(Board_Size, std::vector<int>(Board_Size, 0));

	NQUtil(Board, 0);

	Output();
}

int Basic_NQueen::Get_Input()
{
	std::string Input = "";
	system("CLS");
	std::cout << "Please enter a number for the board size: ";
	std::getline(std::cin, Input);

	try
	{
		return stoi(Input);
	}
	catch (const std::exception&)
	{
		return 8;
	}
}

void Basic_NQueen::Output()
{
	system("CLS");
	std::cout << "NQueen:" << std::endl << std::endl;
	std::cout << "Board size: " << Board_Size << std::endl;
	if (!Results.Is_Empty())
	{
		std::cout << "Solution exists: TRUE" << std::endl;

		while (!Results.Is_Empty())
		{
			std::cout << Results.Pop() << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "Solution exists: FALSE" << std::endl << std::endl;
	}
	system("PAUSE");
}

void Basic_NQueen::NQUtil(std::vector<std::vector<int>>& Board, int Row)
{
	if (Row == Board_Size)
	{
		Num_Of_Solutions++;
		std::string Row = "";

		for (int i = 0; i < Board_Size; i++)
		{
			for (int j = 0; j < Board_Size; j++)
			{
				if (Board[i][j]) { Row += "Q "; }
				else { Row += "- "; }
			}

			Row += "\n";
		}

		Results.Push(Row);
	}

	for (int i = 0; i < Board_Size; i++)
	{
		if (Row == 1 && i == 2)
		{
			std::cout << "";
		}

		if (Is_Safe(Board, Row, i))
		{
			Board[Row][i] = 1;
			NQUtil(Board, Row + 1);
			Board[Row][i] = 0;
		}
		else if (i == 3)
		{
			return;
		}
	}
}

bool Basic_NQueen::Is_Safe(std::vector<std::vector<int>>& Board, int Row, int Col)
{
	for (int i = 0; i < Row; i++)
	{
		if (Board[i][Col] == 1) { return false; }
	}

	int i = 0;
	int j = 0;

	for (i = Row, j = Col; i >= 0 && j >= 0; i--, j--)
	{
		if (Board[i][j] == 1) { return false; }
	}

	for (i = Row, j = Col; i >= 0 && j < Board_Size; i--, j++)
	{
		if (Board[i][j] == 1) { return false; }
	}

	return true;
}
