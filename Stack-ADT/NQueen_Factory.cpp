//  NQueen_Factory.cpp : By Niall Starkey

//	HEADERS:
#include	"NQueen_Factory.h"
#include	"NQueen.h"
#include	"Basic_NQueen.h"

//	Returns a pointer to the newly created child class of the selected nqueen type.
std::unique_ptr<NQueen> New_NQueen(NQueen_Type NQueen)
{
	switch (NQueen)
	{
	case Basic:
		return std::make_unique<Basic_NQueen>();
	}
}