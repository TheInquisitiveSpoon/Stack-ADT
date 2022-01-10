#include <iostream>
#include <string>
#include "Notation_Menu.h"
#include "Notation_Factory.h"

void Notation_Menu::Show()
{
	Notation_Type Current_Notation = Int;
	Notation* Notation_Manager = New_Notation(Current_Notation);
	Options Choice = Empty;

	while (Choice != Exit)
	{
		system("CLS");
		std::cout << "1. Start with integer." << std::endl;
		std::cout << "2. Exit" << std::endl;

		Choice = (Options)Get_Choice();

		if (Choice == Int_Expression)
		{
			Notation* Notation_Manager = New_Notation(Current_Notation);
			Notation_Manager->Solve();
		}
	}

	delete Notation_Manager;
}

int Notation_Menu::Get_Choice()
{
	std::cout << "Choose a number from the menu:" << std::endl;

	std::string c = "";
	std::getline(std::cin, c);

	if (c == "1")
	{
		return Int_Expression;
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
