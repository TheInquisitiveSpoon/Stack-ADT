#pragma once

#include <iostream>
#include "Menu.h"
#include "Notation.h"

class Notation_Menu : public Menu
{
private:
	enum Options
	{
		Int_Expression = 1,
		Exit = 3,
		Empty
	};

	std::string Expression;
	Notation* Notation_Manager;

public:
	void Show();
	int Get_Choice();
};

