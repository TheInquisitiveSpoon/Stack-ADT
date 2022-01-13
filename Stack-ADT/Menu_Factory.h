//  Menu_Factory.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	"Menu.h"

//	Enumeration for each type of child menu.
enum Menu_Type
{
	EMain_Menu,
	ENotation_Menu,
	ENQueen_Menu
};

//	FUNCTIONS:
std::unique_ptr<Menu>	New_Menu(Menu_Type Menu_Type);