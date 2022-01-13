//  NQueen_Factory.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	"NQueen.h"

//	Enumeration for each child class.
enum NQueen_Type
{
	Basic
};

//	FUNCTIONS:
std::unique_ptr<NQueen>		New_NQueen(NQueen_Type NQueen);