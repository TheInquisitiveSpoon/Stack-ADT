#include "Notation_Factory.h"
#include "Notation.h"
#include "Int_Expression.h"

Notation* New_Notation(Notation_Type Notation)
{
	switch (Notation)
	{
	case Int:
		return new Int_Expression();
	}
}