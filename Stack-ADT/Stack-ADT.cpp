//  Stack-ADT.cpp : By Niall Starkey

//  HEADERS:
#include    <iostream>
#include    <crtdbg.h>
#include    <stack>
#include    "Stack.h"
#include    "Menu.h"
#include    "Menu_Factory.h"

//  FORWARD DECLARATIONS:
void    Start();

//  MAIN:
int main()
{
    Start();
    _CrtDumpMemoryLeaks();  // Check for memory leaks.
}

//  FUNCTIONS:
//  Function to initialise Main Menu and show it.
void Start()
{
    std::unique_ptr<Menu> Main_Menu = New_Menu(EMain_Menu);
    Main_Menu->Show();
    Main_Menu.reset();
}