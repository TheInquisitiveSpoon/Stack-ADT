#include "Menu_Factory.h"
#include "Main_Menu.h"
#include "Notation_Menu.h"
#include "NQueen_Menu.h"

Menu* New_Menu(Menu_Type Menu)
{
	switch (Menu)
	{
	case EMain_Menu:
		return new Main_Menu();

	case ENotation_Menu:
		return new Notation_Menu();

	case ENQueen_Menu:
		return new NQueen_Menu();
	}
}