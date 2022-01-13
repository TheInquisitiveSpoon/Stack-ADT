//  Notation_Menu.cpp : By Niall Starkey

//	HEADERS:
#include	<iostream>
#include	<string>
#include	"Notation_Menu.h"
#include	"Notation_Factory.h"


//  Shows the notation menu, and allows the user to pick an option, executing the notation solver of the selected notation.
void Notation_Menu::Show()
{
	Notation_Type Current_Notation = Int;
	std::unique_ptr<Notation> Notation_Manager = New_Notation(Current_Notation);	//	Notation menu manager for changing the notation type..
	Options Choice = Empty;

	while (Choice != Exit)
	{
		system("CLS");
		std::cout << "1. Start with integer." << std::endl;
		std::cout << "2. Exit" << std::endl;

		Choice = (Options)Get_Choice();	//	Gets user input.

		//	Solves the notation equation based on the type that the user selected.
		if (Choice == Int_Expression)
		{
			Notation_Manager.reset();
			Notation_Manager = New_Notation(Current_Notation);
			Notation_Manager->Solve();
		}
	}

	Notation_Manager.reset();
}

//	Gets the menu option from the user based on input.
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
