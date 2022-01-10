#include "NQueen_Factory.h"
#include "NQueen.h"
#include "Basic_NQueen.h"

NQueen* New_NQueen(NQueen_Type NQueen)
{
	switch (NQueen)
	{
	case Basic:
		return new Basic_NQueen();
	}
}