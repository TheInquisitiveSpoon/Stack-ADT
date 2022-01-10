#include <iostream>
#include <string>
#include "Main_Menu.h"
#include "Menu_Factory.h"

void Main_Menu::Show()
{
    Menu_Type Current_Menu = EMain_Menu;
    Menu* Menu_Manager = New_Menu(Current_Menu);
    Options Choice = Empty;

    while (Choice != Exit)
    {
        system("CLS");
        std::cout << "1. Evaluate arithmetic expression" << std::endl;
        std::cout << "2. Solve N Queen" << std::endl;
        std::cout << "3. Exit" << std::endl;

        Choice = (Options)Get_Choice();

        if (Choice == Notation)
        {
            Current_Menu = ENotation_Menu;
            Menu_Manager = New_Menu(Current_Menu);
            Menu_Manager->Show();
        }
        else if (Choice == NQueen)
        {
            Current_Menu = ENQueen_Menu;
            Menu_Manager = New_Menu(Current_Menu);
            Menu_Manager->Show();
        }
    }

    delete Menu_Manager;
}

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
