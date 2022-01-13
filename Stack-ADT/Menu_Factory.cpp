//  Menu_Factory.cpp : By Niall Starkey

//	HEADERS:
#include	<memory>
#include	"Menu_Factory.h"
#include	"Main_Menu.h"
#include	"Notation_Menu.h"
#include	"NQueen_Menu.h"

//	Returns a pointer to the newly created child class of the selected menu type.
std::unique_ptr<Menu> New_Menu(Menu_Type Menu_Type)
{
	switch	(Menu_Type)
	{
	case	EMain_Menu:
		return std::make_unique<Main_Menu>();

	case	ENotation_Menu:
		return std::make_unique<Notation_Menu>();

	case	ENQueen_Menu:
		return std::make_unique<NQueen_Menu>();
	}
}