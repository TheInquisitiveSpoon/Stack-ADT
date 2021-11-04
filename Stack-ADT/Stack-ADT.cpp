// Stack-ADT.cpp : By Niall Starkey

#include <iostream>
#include <crtdbg.h>
#include <stack>
#include "Stack.h"

enum Choice
{
    Arithmetic = 1,
    NQueen = 2,
    Empty = 0
};

void Start();
Choice Menu();

int main()
{
    Start();
    _CrtDumpMemoryLeaks();
}

void Start()
{
    Choice c = Menu();

    switch (c)
    {
        case Arithmetic:
            std::cout << "Arithmetic";
            break;

        case NQueen:
            std::cout << "NQueen";
            break;

        case Empty:
            break;
    }
}

Choice Menu()
{
    std::cout << "1. Evaluate arithmetic expression" << std::endl;
    std::cout << "2. Solve N Queen" << std::endl;
    std::cout << "Choose a number from the menu:" << std::endl;

    std::string c = "";
    std::cin >> c;

    if (c == "1")
    {
        return Arithmetic;
    }
    else if (c == "2")
    {
        return NQueen;
    }
    else
    {
        return Empty;
    }
}