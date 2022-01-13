//  Notation_Factory.cpp : By Niall Starkey

//	HEADERS:
#include	"Notation_Factory.h"
#include	"Notation.h"
#include	"Int_Expression.h"

//	Returns a pointer to the newly created child class of the selected notation type.
std::unique_ptr<Notation> New_Notation(Notation_Type Notation)
{
	switch (Notation)
	{
	case Int:
		return std::make_unique<Int_Expression>();
	}
}