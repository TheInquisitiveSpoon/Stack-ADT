#pragma once

#include <iostream>
#include "Menu.h"
#include "NQueen.h"

class NQueen_Menu : public Menu
{
private:
	enum Options
	{
		Run = 1,
		Exit = 3,
		Empty
	};

	std::string Expression;
	NQueen* NQueen_Manager;

public:
	void Show();
	int Get_Choice();
};

