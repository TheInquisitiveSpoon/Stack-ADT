#pragma once

#include <iostream>
#include <string>

template<typename value_type>

class Stack
{
private:
	struct Node
	{
		value_type Data;
		Node* Next;
	};

	Node* Start;

public:
	Stack() = default;

	bool Is_Empty()
	{
		return !Start;
	}

	std::string To_String()
	{
		Node* Temp;
		std::string Contents;

		Temp = Start;
		while (Temp)
		{
			Contents += std::to_string(Temp->Data);
			Contents += " -> ";
			Temp = Temp->Next;
		}

		delete Temp;
		return Contents;
	}

	int Size()
	{
		Node* Temp;
		int Count = 0;

		Temp = Start;
		while (Temp)
		{
			Count++;
			Temp = Temp->Next;
		}

		delete Temp;
		return Count;
	}

	void Push(const value_type& _Data)
	{
		Node* Temp = new Node();
		Temp->Data = _Data;
		Temp->Next = Start;
		Start = Temp;
	}

	value_type Pop()
	{
		if (!Start) { return NULL; }

		Node* Temp;
		Temp = Start;
		Start = Start->Next;
		Temp->Next = NULL;
		delete Temp;
	}

	void Top()
	{
		if (!Start) { return; }

		std::cout << Start->Data;
	}

	void Clear()
	{
		if (!Start) { return; }

		while (Start)
		{
			Pop();
		}
	}
};

