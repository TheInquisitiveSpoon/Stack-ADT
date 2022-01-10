// Stack-ADT.cpp : By Niall Starkey

#include <iostream>
#include <crtdbg.h>
#include <stack>
#include "Stack.h"
#include "Menu.h"
#include "Menu_Factory.h"

void Start();

int main()
{
    Start();
    _CrtDumpMemoryLeaks();
}
void Start()
{
    Menu* Main_Menu = New_Menu(EMain_Menu);
    Main_Menu->Show();
    delete Main_Menu;
}