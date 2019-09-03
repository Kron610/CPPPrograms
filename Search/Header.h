#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;
template<typename T> class Sequence
{
protected:
	int Length, IsEmpty;
public:
	int GetLength() const 
	{
		return Length;
	}

	int GetIsEmpty() const
	{
		return IsEmpty;
	}



	virtual T Get(int index) const  = 0;
	virtual T GetFirst() const  = 0;
	virtual T GetLast() const = 0;
	virtual void Append(const T &item) = 0;
	virtual void Prepend(const T &item) = 0;
	virtual void InsertArt(int index, const T &item) = 0;
	virtual void Remove(const T &item) = 0;
	virtual void Output() const = 0;
	virtual void InputElements() = 0;
	virtual int SearchItem(const T &item) const  = 0;
	virtual void Put(T item, int index) = 0;
};

template <typename T>
class Iterator
{
private:
	Sequence<T>* sequence;
	int index;
public:
	Iterator<T>(Sequence<T>* sequence1)
	{
		sequence = sequence1;
		index = 0;
	}

	bool HasNext()
	{
		if (index == sequence->GetLength())
			return false;
		return true;
	}

	T CurrentItem()
	{
		if (HasNext())
			return sequence->Get(index);
		else
			throw "The iterator is on the outside of the collection.";
	}

	bool Next()
	{
		if (HasNext())
		{
			index += 1;
			return true;
		}
		return false;
	}

	bool Add(T& element)
	{
		try
		{
			element = CurrentItem();
			return true;
		}
		catch (const char* string)
		{
			cout << string;
			return false;
		}
	}


};