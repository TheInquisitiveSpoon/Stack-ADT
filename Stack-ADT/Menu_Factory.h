#pragma once

#include "Menu.h"

enum Menu_Type
{
	EMain_Menu,
	ENotation_Menu,
	ENQueen_Menu
};

Menu* New_Menu(Menu_Type Menu);