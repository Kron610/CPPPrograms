#pragma once
#include "Header.h"
#include <iostream>
using namespace std;


template <typename T>
class Array_Sequence : public Sequence<T>

{

private:

	int MemoryLength;
	T* elements_array;

public:

	Iterator<T>* GetIterator() 
	{
		Iterator<T>* it = new Iterator<T>(this);
		return it;
	}

	int GetMemoryLength() const
	{
		return MemoryLength;
	}

	Array_Sequence<T>(int N = 0)
	{
		this->Length = N;
		this->MemoryLength = N;
		if (N == 0)
			this->IsEmpty = 1;
		else
		{
			this->IsEmpty = 0;
			elements_array = new T[N];
		}
	}

	~Array_Sequence<T>()
	{
		delete [] elements_array;
	}

	T Get(int index) const 
	{
		if ((index < 0) || (index >= this->GetLength()))
		{
			throw "Wrong index";
		}
		return elements_array[index];
	}

	T GetFirst() const 
	{
		if (this->GetIsEmpty())
		{
			throw "Sequence is empty";
		}
		return elements_array[0];
	}

	T GetLast() const
	{
		if (this->GetIsEmpty())
		{
			throw "Sequence is empty";
		}
		return elements_array[this->GetLength() - 1];
	}

	Array_Sequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		if (this->GetIsEmpty())
			throw "Sequence is empty";
		if ((startIndex < 0) || (startIndex > this->GetLength()) || (endIndex < 0) || (endIndex > this->GetLength()))
			throw "Wrong index";
		if (startIndex > endIndex)
			throw "Start index is more than last index";
		Array_Sequence<T> *new_sequence = new Array_Sequence<T>(endIndex - startIndex + 1);
		for (int i = startIndex; i < endIndex + 1; i++)
			new_sequence->elements_array[i - startIndex] = this->Get(i);
		return new_sequence;
	}

	void Swap(int i, int j)
	{
		T element = this->Get(i);
		this->Put(this->Get(j), i);
		this->Put(element, j);
	}

	void Append(const T &item)
	{
		if (this->GetIsEmpty())
			this->IsEmpty = 0;
		if (this->GetLength() == this->GetMemoryLength())
		{
			this->MemoryLength = this->GetLength() * 2 + 1;
			T* elements_array1 = new T[this->GetMemoryLength()];
			for (int i = 0; i < this->GetLength(); i++)
			{
				elements_array1[i] = this->Get(i);
			}
			elements_array1[this->GetLength()] = item;
			this->elements_array = elements_array1;
			this->Length += 1;
		}
		else
		{
			this->elements_array[this->GetLength()] = item;
			this->Length += 1;
		}
	}

	void Prepend(const T &item) 
	{
		if (this->GetIsEmpty())
			this->IsEmpty = 0;
		if (this->GetLength() == this->GetMemoryLength())
		{
			this->MemoryLength = this->GetLength() * 2 + 1;
			T* elements_array1 = new T[this->GetMemoryLength()];
			elements_array1[0] = item;
			for (int i = 0; i < this->GetLength(); i++)
			{
				elements_array1[i+1] = this->Get(i);
			}
			this->elements_array = elements_array1;
			this->Length += 1;
		}
		else
		{
			this->elements_array[this->GetLength()] = item;
			this->Length += 1;
			for (int i = this->GetLength()-1; i > 0; i--)
			{
				Swap(i, i - 1);
			}

		}
	}

	void InsertArt(int index, const T &item)
	{
		if ((index < 0) || (index >= this->GetLength()))
		{
			throw "Wrong index";
		}
		if (this->GetLength() == this->GetMemoryLength())
		{
			this->MemoryLength = this->GetLength() * 2 + 1;
			T* elements_array1 = new T[this->GetMemoryLength()];
			for (int i = 0; i < index; i++)
			{
				elements_array1[i] = this->Get(i);
			}
			elements_array1[index] = item;
			for (int i = index; i < this->GetLength(); i++)
			{
				elements_array1[i + 1] = this->Get(i);
			}
			this->elements_array = elements_array1;
			this->Length += 1;
		}
		else
		{
			this->elements_array[this->GetLength()] = item;
			this->Length += 1;
			for (int i = this->GetLength() - 1; i > index; i--)
			{
				Swap(i, i - 1);
			}
		}
	}

	int SearchItem(const T &item) const
	{
		for (int i = 0; i < this->GetLength(); i++)
		{
			if (this->elements_array[i] == item)
				return i+1;
		}
		return 0;
	}

	void Remove(const T &item)
	{
		int st = this->SearchItem(item);
		if (st)
		{
			Array_Sequence<T> *new_sequence = new Array_Sequence<T>(this->GetLength() - 1);
			for (int i = 0; i < st - 1; i++)
				new_sequence->elements_array[i] = this->Get(i);
			for (int i = st - 1; i < new_sequence->GetLength(); i++)
				new_sequence->elements_array[i] = this->Get(i + 1);
			this->elements_array = new_sequence->elements_array;
			this->Length = new_sequence->GetLength();
		}
	}

	

	void Output() const
	{
		if (this->GetIsEmpty())
			cout << "This sequence is empty" << endl;
		else
		{
			cout << "Your sequence:" << endl;
			for (int i = 0; i < this->GetLength(); i++)
			{
				cout << this->Get(i) << '\t';
			}
			cout << endl << endl;
		}
	}
	void InputElements()
	{
		if (this->GetIsEmpty() == 0)
		{
			cout << "Enter the items" << endl;
			for (int i = 0; i < this->GetLength(); i++)
			{
				cout << "Enter the " << i + 1 << " item" << endl;
				cin >> this->elements_array[i];
			}
		}
	}

	// Методы для 1 л/р:

	void Put(T item, int index)
	{
		this->elements_array[index] = item;
	}
	
};

void test_iterator()
{
	Array_Sequence<int>* sequence = new Array_Sequence<int>();
	sequence->Append(0);
	sequence->Append(1);
	sequence->Append(3);
	sequence->Append(2);
	Iterator<int>* it = sequence->GetIterator();
	int i = 0;
	for (it; it->HasNext(); it->Next())
	{
		if (it->CurrentItem() != sequence->Get(i))
		{
			cout << "Test.iterator isn't passed" << endl;
			break;
		}
		i += 1;
	}
	cout << "Test.iterator is passed" << endl;
}