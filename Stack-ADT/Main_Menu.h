#pragma once

#include "Menu.h"

class Main_Menu : public Menu
{
private:
	enum Options
	{
		Notation = 1,
		NQueen = 2,
		Exit = 3,
		Empty
	};

public:
	void Show();
	int Get_Choice();
};

