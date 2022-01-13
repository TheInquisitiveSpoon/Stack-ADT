//  NQueen_Menu.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	"Menu.h"
#include	"NQueen.h"

//	NQueen_Menu class.
class NQueen_Menu : public Menu
{
private:
	//	Enumeration for each of the menu options, with a default empty.
	enum Options
	{
		Run = 1,
		Exit = 3,
		Empty
	};

public:
	//	FUNCTIONS:
	void	Show();
	int		Get_Choice();
};

