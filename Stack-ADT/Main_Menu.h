//  Main_Menu.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	"Menu.h"

//	Main_Menu class.
class Main_Menu : public Menu
{
private:
	//	Enumeration for the different menu options, with Empty for default.
	enum Options
	{
		Notation = 1,
		NQueen = 2,
		Exit = 3,
		Empty
	};

public:
	//	FUNCTIONS:
	void	Show();
	int		Get_Choice();
};

