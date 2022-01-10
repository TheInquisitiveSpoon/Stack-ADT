#pragma once

#include <iostream>
#include <string>

template<typename value_type>

class Stack
{
private:
	struct Node
	{
		value_type	Data;
		Node*		Next;
	};

	Node*	Start;

public:
	Stack()	= default;

	Stack<value_type>& operator += (Stack<value_type>& _Stack)
	{
		while (_Stack.Start)
		{
			this->Push(_Stack.Pop());
		}

		return *this;
	}

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
			Contents += Temp->Data;
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
		value_type Data;

		Temp = Start;
		Start = Start->Next;
		Data = Temp->Data;

		delete Temp;
		return Data;
	}

	value_type Top()
	{
		if (!Start) { return NULL; }

		return Start->Data;
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

