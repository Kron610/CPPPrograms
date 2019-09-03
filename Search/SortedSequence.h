#pragma once
#include "stdafx.h"
#include <time.h>
using namespace std;



template <typename T>
struct List
{
	struct List* next;
	T element;
};

template<typename T> class SortedSequence
{
protected:
	int Length, IsEmpty;
public:
	int GetLength()
	{
		return Length;
	}
	int GetIsEmpty()
	{
		return IsEmpty;
	}

	virtual T Get(int index) = 0;
	virtual T GetFirst() = 0;
	virtual T GetLast() = 0;
	virtual void Output() = 0;
	virtual void InputElements() = 0;
	virtual void Add(const T &element) = 0;
	virtual int IndexOf(const T &element) = 0;
	virtual void Put(const T &element, int index) = 0;
};

template <typename T>
void ShellSort(SortedSequence<T>* sequence)
{
	int i, j, step;
	T tmp;
	int n = sequence->GetLength();
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = sequence->Get(i);
			for (j = i; j >= step; j -= step)
			{
				if (tmp < sequence->Get(j - step))
					sequence->Put(sequence->Get(j - step), j);
				else
					break;
			}
			sequence->Put(tmp, j);
		}
}

template <typename T>
class SortedArraySequence : public SortedSequence<T>
{
private:
	int MemoryLength;
	T* elements_array;

	void Put(const T &item, int index)
	{
		this->elements_array[index] = item;
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

public:

	int GetMemoryLength()
	{
		return MemoryLength;
	}

	SortedArraySequence<T>(int N = 0)
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

	~SortedArraySequence<T>()
	{
		delete[] elements_array;
	}

	T Get(int index)
	{
		if ((index < 0) || (index >= this->GetLength()))
		{
			throw "Wrong index";
		}
		return elements_array[index];
	}

	T GetFirst()
	{
		if (this->GetIsEmpty())
		{
			throw "Sequence is empty";
		}
		return elements_array[0];
	}

	T GetLast()
	{
		if (this->GetIsEmpty())
		{
			throw "Sequence is empty";
		}
		return elements_array[this->GetLength() - 1];
	}

	SortedArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		if (this->GetIsEmpty())
			throw "Sequence is empty";
		if ((startIndex < 0) || (startIndex > this->GetLength()) || (endIndex < 0) || (endIndex > this->GetLength()))
			throw "Wrong index";
		if (startIndex > endIndex)
			throw "Start index is more than last index";
		SortedArraySequence<T> *new_sequence = new SortedArraySequence<T>(endIndex - startIndex + 1);
		for (int i = startIndex; i < endIndex + 1; i++)
			new_sequence->elements_array[i - startIndex] = this->Get(i);
		return new_sequence;
	}

	void Output()
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
			ShellSort(this);
		}
	}

	void Add(const T &element)
	{
		this->Append(element);
		ShellSort(this);
	}

	int IndexOf(const T &item)
	{
		for (int i = 0; i < this->GetLength(); i++)
		{
			if (this->elements_array[i] == item)
				return i;
		}
		return -1;
	}
};



template <typename T>
class SortedListSequence : public SortedSequence<T>
{
private:
	struct List<T>* first;

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

	void ShellSort()
	{
		int i, j, step;
		T tmp;
		int n = this->GetLength();
		for (step = n / 2; step > 5; step /= 2)
			for (i = step; i < n; i++)
			{
				tmp = this->Get(i);
				for (j = i; j >= step; j -= step)
				{
					if (tmp < this->Get(j - step))
						this->Put(this->Get(j - step), j);
					else
						break;
				}
				this->Put(tmp, j);
			}
	}

	void Put(const T& item, int index)
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

public:
	SortedListSequence<T>(int N = 0)
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

	~SortedListSequence<T>()
	{
		if (this->GetIsEmpty() == 0)
		{
			struct List<T>* cash1;
			for (int i = 0; i < this->GetLength() - 1; i++)
			{
				cash1 = this->first;
				if (this->first->next != nullptr)
					this->first = this->first->next;
				delete cash1;
			}
		}
	}

	T Get(int index)
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

	T GetFirst()
	{
		if (this->GetIsEmpty())
		{
			throw "Sequence is empty";
		}
		return this->first->element;
	}

	T GetLast()
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

	SortedListSequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		if (this->GetIsEmpty())
			throw "Sequence is empty";
		if ((startIndex < 0) || (startIndex > this->GetLength()) || (endIndex < 0) || (endIndex > this->GetLength()))
			throw "Wrong index";
		if (startIndex > endIndex)
			throw "Start index is more than last index";
		struct List<T>* List_cash = this->first;
		SortedListSequence<T> *new_sequence = new SortedListSequence<T>(endIndex - startIndex + 1);
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

	void Output()
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
			this->ShellSort();
		}
	}

	void Add(const T &element)
	{
		this->Prepend(element);
		this->ShellSort();
	}

	int IndexOf(const T &item)
	{
		if (this->GetIsEmpty())
			return -1;
		else
		{
			struct List<T>* cash = this->first;
			if (cash->element == item)
				return 0;
			for (int i = 1; i < this->GetLength(); i++)
			{
				cash = cash->next;
				if (cash->element == item)
					return i;
			}
			return -1;
		}
	}
};

template<typename T>
void fill_random(SortedSequence<T>* sequence, int range)
{
	srand(time(NULL));
	for (int i = 0; i < sequence->GetLength(); i++)
		sequence->Put(rand() % range, i);
}