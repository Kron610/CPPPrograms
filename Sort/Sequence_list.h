#pragma once
#include "stdafx.h"
#include "Header.h"
#include <iostream>
using namespace std;

template <typename T>
struct List
{
	struct List* next;
	T element;
};

template <typename T>
class List_Sequence : public Sequence<T>
{
private:
	struct List<T>* first;
public:

	Iterator<T>* GetIterator()
	{
		Iterator<T>* it = new Iterator<T>(this);
		return it;
	}

	List_Sequence<T>(int N = 0)
	{
		this->Length = N;
		if (N == 0)
			this->IsEmpty = 1;
		else
		{
			this->IsEmpty = 0;
			this->first = new struct List<T>;
			struct List<T>* cash = new struct List<T>;
			this->first->next = cash;
			for (int i = 0; i < N - 1; i++)
			{
				cash->next = new struct List<T>;
				cash = cash->next;
			}
			cash = nullptr;
		}
	}

	~List_Sequence<T>()
	{
		if (this->GetIsEmpty() == 0)
		{
			struct List<T>* cash1;
			for (int i = 0; i < this->GetLength() - 1; i++)
			{
				cash1 = this->first;
				if (this->first->next!=nullptr)
					this->first = this->first->next;
				delete cash1;
			}
		}
	}

	T Get(int index) const
	{
		if ((index < 0) || (index >= this->GetLength()))
			throw "Wrong index";
		struct List<T>* List_cash = this->first;
		for (int i = 0; i < index; i++)
		{
			List_cash = List_cash->next;
		}
		return List_cash->element;
	}

	T GetFirst() const
	{
		if (this->GetIsEmpty())
		{
			throw "Sequence is empty";
		}
		return this->first->element;
	}

	T GetLast() const
	{
		if (this->GetIsEmpty())
		{
			throw "Sequence is empty";
		}
		struct List<T>* List_cash = this->first;
		for (int i = 0; i < this->GetLength() - 1; i++)
		{
			List_cash = List_cash->next;
		}
		return List_cash->element;
	}

	List_Sequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		if (this->GetIsEmpty())
			throw "Sequence is empty";
		if ((startIndex < 0) || (startIndex > this->GetLength()) || (endIndex < 0) || (endIndex > this->GetLength()))
			throw "Wrong index";
		if (startIndex > endIndex)
			throw "Start index is more than last index";
		struct List<T>* List_cash = this->first;
		List_Sequence<T> *new_sequence = new List_Sequence<T>(endIndex - startIndex + 1);
		for (int i = 0; i < startIndex; i++)
		{
			List_cash = List_cash->next;
		}
		new_sequence->first->element = List_cash->element;
		struct List<T>* List_cash2 = new_sequence->first;
		for (int i = startIndex; i < endIndex; i++)
		{
			List_cash2 = List_cash2->next;
			List_cash = List_cash->next;
			List_cash2->element = List_cash->element;
		}
		return new_sequence;
	}

	void Append(const T &item)
	{
		if (this->GetIsEmpty())
		{
			this->first = new struct List<T>;
			this->first->element = item;
			this->IsEmpty = 0;
		}
		else
		{
			struct List<T>* List_cash = this->first;
			for (int i = 0; i < this->GetLength() - 1; i++)
			{
				List_cash = List_cash->next;
			}
			List_cash->next = new struct List<T>;
			List_cash->next->element = item;
		}
		this->Length += 1;
	}

	void Prepend(const T &item)
	{
		this->Length += 1;
		struct List<T>* cash = new struct List<T>;
		cash->element = item;
		if (this->GetIsEmpty())
		{
			this->IsEmpty = 0;
			this->first = cash;
		}
		else
		{
			cash->next = this->first;
			this->first = cash;
		}
	}

	void InsertArt(int index, const T &item)
	{
		if ((index < 0) || (index >= this->GetLength()))
		{
			throw "Wrong index";
		}
		struct List<T>* cash;
		if (index == 0)
		{
			cash = new struct List<T>;
			cash->element = item;
			cash->next = this->first;
			this->first = cash;
		}
		else
		{
			cash = this->first;
			for (int i = 1; i < index; i++)
				cash = cash->next;
			struct List<T>* cash2;
			cash2 = new struct List<T>;
			cash2->element = item;
			cash2->next = cash->next;
			cash->next = cash2;
		}
		this->Length += 1;
	}

	int SearchItem(const T &item) const
	{
		if (this->GetIsEmpty())
			return 0;
		else
		{
			struct List<T>* cash = this->first;
			if (cash->element == item)
				return 1;
			for (int i = 1; i < this->GetLength(); i++)
			{
				cash = cash->next;
				if (cash->element == item)
					return i+1;
			}
			return 0;
		}
	}

	void Remove(const T &item)
	{
		int st = this->SearchItem(item);
		if (st)
		{
			struct List<T>* cash = this->first;
			if (st == 1)
			{
				this->first = this->first->next;
				delete cash;
			}
			else 
			{
				for (int i = 0; i < st - 2; i++)
					cash = cash->next;
				struct List<T>* cash2 = cash->next;
				cash->next = cash2->next;
				delete cash2;
			}
		}
		this->Length -= 1;
		if (this->GetLength() == 0)
			this->IsEmpty = 1;
	}

	void Output() const
	{

		if (this->GetIsEmpty())
			cout << "This sequence is empty" << endl;
		else
		{
			cout << "Your sequence:" << endl;
			struct List<T>* cash = this->first;
			cout << cash->element << '\t';
			for (int i = 0; i < this->GetLength() - 1; i++)
			{
				cash = cash->next;
				cout << cash->element << '\t';
			}
			cout << endl << endl;
		}
	}

	void InputElements()
	{
		if (this->GetIsEmpty() == 0)
		{
			struct List<T>* cash = this->first;
			cout << "Enter the items" << endl;
			cout << "Enter the first item" << endl;
			cin >> cash->element;
			for (int i = 0; i < this->GetLength() - 1; i++)
			{
				cash = cash->next;
				cout << "Enter the " << i + 2 << " item" << endl;
				cin >> cash->element;
			}
		}
	}

	// Ìועמהû הכÿ 1 כ/נ:

	void Put(T item, int index)
	{
		struct List<T>* cash = this->first;
		if (index == 0)
		{
			this->first->element = item;
		}
		for (int i = 0; i < index; i++)
			cash = cash->next;
		cash->element = item;
	}
};
