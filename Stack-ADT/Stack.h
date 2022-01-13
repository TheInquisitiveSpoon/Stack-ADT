//  Stack.h : By Niall Starkey

#pragma once

//	HEADERS:
#include	<iostream>
#include	<string>

template<typename value_type>

// Stack class
class Stack
{
private:
	//	Node struct for linked list.
	struct Node
	{
		value_type	Data;
		Node*		Next;
	};

	//	Initial node in Stack.
	Node*	Start;

public:
	//	FUNCTIONS:
	//	Default constructor.
	Stack()	= default;

	//	Checks if the stack is empty.
	bool Is_Empty()
	{
		return !Start;
	}

	//	Output the contents of the stack to a string.
	std::string To_String()
	{
		Node* Temp;
		std::string	Contents;

		Temp = Start;
		while (Temp)
		{
			Contents += Temp->Data;
			Contents += " -> ";
			Temp = Temp->Next;
		}

		delete Temp;
		return Contents;
	}

	//	Returns the current size of the stack.
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

	//	Push a new piece of data onto the top of the stack.
	void Push(const value_type& _Data)
	{
		Node* Temp = new Node();
		Temp->Data = _Data;
		Temp->Next = Start;
		Start = Temp;
	}

	//	Pop the top of the stack and return its value.
	value_type Pop()
	{
		if (!Start) { return NULL; }

		Node* Temp;
		value_type Data;

		Temp = Start;
		Start = Start->Next;
		Data = Temp->Data;

		delete Temp;
		return Data;
	}

	//	Peek at the top of the stack, without removing the data.
	value_type Top()
	{
		if (!Start) { return NULL; }

		return Start->Data;
	}

	//	Clears the entire stack.
	void Clear()
	{
		if (!Start) { return; }

		while (Start)
		{
			Pop();
		}
	}
};

