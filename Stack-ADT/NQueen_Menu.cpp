//  NQueen_Menu.cpp : By Niall Starkey

//	HEADERS:
#include	<iostream>
#include	<string>
#include	"NQueen_Menu.h"
#include	"NQueen_Factory.h"

//	Shows the NQuuen menu and begins solves the nqueen problem based on the user input.
void NQueen_Menu::Show()
{
	NQueen_Type Current_NQueen = Basic;
	std::unique_ptr<NQueen> NQueen_Manager = New_NQueen(Current_NQueen);	//	Manager for current type of nqueen selected.
	Options Choice = Empty;

	//	Loops until exit is chosen.
	while (Choice != Exit)
	{
		system("CLS");
		std::cout << "1. Basic NQueen." << std::endl;
		std::cout << "2. Exit" << std::endl;

		Choice = (Options)Get_Choice();

		//	Runs the nqueen solver depending on what type of nqueen was chosen by the user.
		if (Choice == Run)
		{
			NQueen_Manager.reset();
			NQueen_Manager = New_NQueen(Current_NQueen);
			NQueen_Manager->Solve();
		}
	}

	NQueen_Manager.reset();
}

//	Gets the menu choice from the user input.
int NQueen_Menu::Get_Choice()
{
	std::cout << "Choose a number from the menu:" << std::endl;

	std::string c = "";
	std::getline(std::cin, c);

	if (c == "1")
	{
		return Run;
	}
	else if (c == "2")
	{
		return Exit;
	}
	else
	{
		return Empty;
	}
}
