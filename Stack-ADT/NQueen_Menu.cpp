#include <iostream>
#include <string>
#include "NQueen_Menu.h"
#include "NQueen_Factory.h"

void NQueen_Menu::Show()
{
	NQueen_Type Current_NQueen = Basic;
	NQueen* NQueen_Manager = New_NQueen(Current_NQueen);
	Options Choice = Empty;

	while (Choice != Exit)
	{
		system("CLS");
		std::cout << "1. Basic NQueen." << std::endl;
		std::cout << "2. Exit" << std::endl;

		Choice = (Options)Get_Choice();

		if (Choice == Run)
		{
			NQueen* NQueen_Manager = New_NQueen(Current_NQueen);
			NQueen_Manager->Solve();
		}
	}

	delete NQueen_Manager;
}

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
