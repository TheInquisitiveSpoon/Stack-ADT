//  Main_Menu.cpp : By Niall Starkey

//  HEADERS:
#include    <iostream>
#include    <string>
#include    "Main_Menu.h"
#include    "Menu_Factory.h"

//  Shows the main menu, and allows the user to pick an option, changing the current menu if the user selects another.
void Main_Menu::Show()
{
    Menu_Type Current_Menu = EMain_Menu;
    std::unique_ptr<Menu> Menu_Manager = New_Menu(Current_Menu);    //  Pointer to menu manager, to control current menu.
    Options Choice = Empty;

    //  Loop until choice is to exit.
    while (Choice != Exit)
    {
        system("CLS");
        std::cout << "1. Evaluate arithmetic expression" << std::endl;
        std::cout << "2. Solve N Queen" << std::endl;
        std::cout << "3. Exit" << std::endl;

        Choice = (Options)Get_Choice(); //  Gets user choice.

        //  Opens notation menu if user selected.
        if (Choice == Notation)
        {
            Current_Menu = ENotation_Menu;
            Menu_Manager.reset();
            Menu_Manager = New_Menu(Current_Menu);
            Menu_Manager->Show();   // Show new menu.
        }
        //  Opens nqueen menu if user selected.
        else if (Choice == NQueen)
        {
            Current_Menu = ENQueen_Menu;
            Menu_Manager.reset();
            Menu_Manager = New_Menu(Current_Menu);
            Menu_Manager->Show();   //  Show new menu.
        }
    }

    Menu_Manager.reset();
}

//  Gets the users choice from input.
int Main_Menu::Get_Choice()
{
    std::cout << "Choose a number from the menu:" << std::endl;

    std::string c = "";
    std::getline(std::cin, c);

    if (c == "1")
    {
        return Notation;
    }
    else if (c == "2")
    {
        return NQueen;
    }
    else if (c == "3")
    {
        return Exit;
    }
    else
    {
        return Empty;
    }
}
