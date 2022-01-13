//  Basic_NQueen.cpp : By Niall Starkey

//	HEADERS:
#include	<iostream>
#include	<string>
#include	<vector>
#include	"Basic_NQueen.h"

//	Solves the NQueen problem with the user given board size, returning all solutions.
void Basic_NQueen::Solve()
{
	Board_Size	= Get_Input();	//	Gets the user input for board size.

	std::vector<std::vector<int>> Board(Board_Size, std::vector<int>(Board_Size, 0));	//	Initialises the board.

	//	Recursive function to solve the NQueen problem.
	if (NQUtil(Board, 0))
	{
		Solution_Exists = true;
	}

	Output();	//	Outputs the solutions.
}

//	Receives the user input, and attempts to convert it into a number for the board size.
int Basic_NQueen::Get_Input()
{
	std::string Input = "";
	system("CLS");
	std::cout << "Please enter a number for the board size: ";
	std::getline(std::cin, Input);

	//	Attempt to turn the input into a number.
	try
	{
		return stoi(Input);
	}
	catch (const std::exception&)
	{
		return 8;	// By default return 8.
	}
}

//	Outputs basic statistics for the search, as well as each solution for the problem.
void Basic_NQueen::Output()
{
	system("CLS");
	std::cout << "NQueen:" << std::endl << std::endl;
	std::cout << "Board size: " << Board_Size << std::endl;
	std::cout << "Total Queens placed: " << Total_Queens_Placed << std::endl;
	std::cout << "Squares scanned: " << Squares_Scanned << std::endl;
	//	Change output if solution is found.
	if (!Results.Is_Empty())
	{
		std::cout << "Solution exists: TRUE" << std::endl << std::endl;
		int Count = 1;

		while (!Results.Is_Empty())
		{
			std::cout << "Solution " << Count << ":" << std::endl;
			std::cout << Results.Pop() << std::endl;
			Count++;
		}
	}
	else
	{
		std::cout << "Solution exists: FALSE" << std::endl << std::endl;
	}
	system("PAUSE");
}

//	Recursive function to solve the NQueen problem, adding solution to stack if one exists.
bool Basic_NQueen::NQUtil(std::vector<std::vector<int>>& Board, int Row)
{
	//	Solution found if at the last row of the board.
	if (Row == Board_Size)
	{
		Num_Of_Solutions++;
		std::string Row = "";

		//	Create string for the solution representation.
		for (int i = 0; i < Board_Size; i++)
		{
			for (int j = 0; j < Board_Size; j++)
			{
				if (Board[i][j]) { Row += "Q "; }
				else { Row += "- "; }
			}

			Row += "\n";
		}

		//	Add solution string to stack.
		Results.Push(Row);
		return true;
	}

	bool Result = false;

	//	Check each square in current row if queen can be placed.
	for (int i = 0; i < Board_Size; i++)
	{
		//	Add queen if it is safe, then move onto next row, using recursion if a solution is not found.
		if (Is_Safe(Board, Row, i))
		{
			Board[Row][i] = 1;
			Total_Queens_Placed++;
			Result = NQUtil(Board, Row + 1) || Result;
			Board[Row][i] = 0;
		}
	}

	return Result;
}

//	Checks to see if a queen can be placed in the current square without attacking another queen already placed.
bool Basic_NQueen::Is_Safe(std::vector<std::vector<int>>& Board, int Row, int Col)
{
	int i = 0;
	int j = 0;

	//	Returns false if queen exists in the same row.
	for (i = 0; i < Row; i++)
	{
		Squares_Scanned++;
		if (Board[i][Col] == 1) { return false; }
	}

	//	Returns false if a queen exists in the top left diagonal.
	for (i = Row, j = Col; i >= 0 && j >= 0; i--, j--)
	{
		Squares_Scanned++;
		if (Board[i][j] == 1) { return false; }
	}

	//	Returns false if a queen exists in the bottom left diagonal.
	for (i = Row, j = Col; i >= 0 && j < Board_Size; i--, j++)
	{
		Squares_Scanned++;
		if (Board[i][j] == 1) { return false; }
	}

	//	Returns true if all checks are passed.
	return true;
}
