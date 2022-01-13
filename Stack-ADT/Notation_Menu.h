//  Notation_Menu.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	<iostream>
#include	"Menu.h"
#include	"Notation.h"

//	Notation_Menu class.
class Notation_Menu : public Menu
{
private:
	//	Enumeration for each menu option, with empty as default.
	enum Options
	{
		Int_Expression = 1,
		Exit = 3,
		Empty
	};

public:
	//	FUNCTIONS:
	void	Show();
	int		Get_Choice();
};

