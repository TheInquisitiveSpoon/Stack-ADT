//  Notation_Factory.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	<memory>
#include	"Notation.h"

//	Enumeration for each child notation.
enum Notation_Type
{
	Int
};

//	FUNCTIONS:
std::unique_ptr<Notation>	New_Notation(Notation_Type Notation);