//
// Created by gerko on 18.09.2019.
//

#pragma once
#include "Header.h"
#include <iostream>
using namespace std;


template <typename T>
class SequenceArray : public Sequence<T>

{


public:

    Iterator<T>* getIterator()
    {
        auto it = new Iterator<T>(this);
        return it;
    }



    int getMemoryLength() const
    {
        return memoryLength_;
    }



    explicit SequenceArray<T>(int N = 0)
    {
        this->length_ = N;
        memoryLength_ = N;
        if (N == 0)
            return;
        else
        {
            elementsArray_ = new T[N];
        }
    }



    ~SequenceArray<T>()
    {
        delete [] elementsArray_;
    }



    T get(int index) const override
    {
        if ((index < 0) || (index >= this->getLength()))
        {
            throw "Wrong index";
        }
        return elementsArray_[index];
    }



    T getFirst() const override
    {
        if (this->isEmpty())
        {
            throw "Sequence is empty";
        }
        return elementsArray_[0];
    }



    T getLast() const override
    {
        if (this->isEmpty())
        {
            throw "Sequence is empty";
        }
        return elementsArray_[this->getLength() - 1];
    }



    SequenceArray<T>* getSubsequence(int startIndex, int endIndex)
    {
        if (this->isEmpty())
            throw "Sequence is empty";
        if ((startIndex < 0) || (startIndex > this->getLength()) || (endIndex < 0) || (endIndex > this->getLength()))
            throw "Wrong index";
        if (startIndex > endIndex)
            throw "Start index is more than last index";
        auto newSequence = new SequenceArray<T>(endIndex - startIndex + 1);
        for (int i = startIndex; i < endIndex + 1; i++)
            newSequence->elementsArray_[i - startIndex] = this->get(i);
        return newSequence;
    }



    void swap(int i, int j)
    {
        T element = this->get(i);
        this->set(this->get(j), i);
        this->set(element, j);
    }



    void append(const T& item) override
    {
        if (this->getLength() == this->getMemoryLength())
        {
            this->memoryLength_ = this->getLength() * 2 + 1;
            auto temporaryArray = new T[this->getMemoryLength()];
            for (int i = 0; i < this->getLength(); i++)
            {
                temporaryArray[i] = this->get(i);
            }
            temporaryArray[this->getLength()] = item;
            this->elementsArray_ = temporaryArray;
            this->length_ += 1;
        }
        else
        {
            this->elementsArray_[this->getLength()] = item;
            this->length_ += 1;
        }
    }

    void prepend(const T& item) override
    {
        if (this->getLength() == this->getMemoryLength())
        {
            this->memoryLength_ = this->getLength() * 2 + 1;
            T* temporaryArray = new T[this->getMemoryLength()];
            temporaryArray[0] = item;
            for (int i = 0; i < this->getLength(); i++)
            {
                temporaryArray[i+1] = this->get(i);
            }
            this->elementsArray_ = temporaryArray;
            this->length_ += 1;
        }
        else
        {
            this->elementsArray_[this->getLength()] = item;
            this->length_ += 1;
            for (int i = this->getLength()-1; i > 0; i--)
            {
                swap(i, i - 1);
            }

        }
    }

    void insertArt(int index, const T& item) override
    {
        if ((index < 0) || (index >= this->getLength()))
        {
            throw "Wrong index";
        }
        if (this->getLength() == this->getMemoryLength())
        {
            this->memoryLength_ = this->getLength() * 2 + 1;
            T* temporaryArray = new T[this->getMemoryLength()];
            for (int i = 0; i < index; i++)
            {
                temporaryArray[i] = this->get(i);
            }
            temporaryArray[index] = item;
            for (int i = index; i < this->getLength(); i++)
            {
                temporaryArray[i + 1] = this->get(i);
            }
            this->elementsArray_ = temporaryArray;
            this->length_ += 1;
        }
        else
        {
            this->elementsArray_[this->getLength()] = item;
            this->length_ += 1;
            for (int i = this->getLength() - 1; i > index; i--)
            {
                swap(i, i - 1);
            }
        }
    }



    void remove(const T& item) override
    {
        int position = this->findItem(item);
        if (position)
        {
            auto newSequence = new SequenceArray<T>(this->getLength() - 1);
            for (int i = 0; i < position - 1; i++)
                newSequence->elementsArray_[i] = this->get(i);
            for (int i = position - 1; i < newSequence->getLength(); i++)
                newSequence->elementsArray_[i] = this->get(i + 1);
            this->elementsArray_ = newSequence->elementsArray_;
            this->length_ = newSequence->getLength();
        }
    }



    void output() const override
    {
        if (this->isEmpty())
            cout << "This sequence is empty" << endl;
        else
        {
            cout << "Your sequence:" << endl;
            for (int i = 0; i < this->getLength(); i++)
            {
                cout << this->get(i) << '\t';
            }
            cout << endl << endl;
        }
    }



    void inputElements() override
    {
        if (this->isEmpty() == 0)
        {
            cout << "Enter the items" << endl;
            for (int i = 0; i < this->getLength(); i++)
            {
                cout << "Enter the " << i + 1 << " item" << endl;
                cin >> this->elementsArray_[i];
            }
        }
    }

    // Методы для 1 л/р:

    void set(T item, int index) override
    {
        this->elementsArray_[index] = item;
    }

private:

    int memoryLength_;
    T* elementsArray_;

    int findItem(const T& item) const override
    {
        for (int i = 0; i < this->getLength(); i++)
        {
            if (this->elementsArray_[i] == item)
                return i + 1;
        }
        return 0;
    }
};

void test_iterator()
{
    auto sequence = new SequenceArray<int>();
    sequence->append(0);
    sequence->append(1);
    sequence->append(3);
    sequence->append(2);
    Iterator<int>* it = sequence->getIterator();
    int i = 0;
    for (it; it->HasNext(); it->Next())
    {
        if (it->CurrentItem() != sequence->get(i))
        {
            cout << "Test.iterator isn't passed" << endl;
            break;
        }
        i += 1;
    }
    cout << "Test.iterator is passed" << endl;
}