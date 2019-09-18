//
// Created by gerko on 18.09.2019.
//

#pragma once
#include "Header.h"
#include <iostream>
using namespace std;

template <typename T>
class List
{
public:
    struct List* next;
    T data;
};

template <typename T>
class SequenceList : public Sequence<T>
{

public:

    Iterator<T>* getIterator()
    {
        auto it = new Iterator<T>(this);
        return it;
    }



    explicit SequenceList<T>(int N = 0)
    {
        this->length_ = N;
        if (N == 0)
            return;
        else
        {
            this->first = new List<T>;
            auto temporaryNode = new List<T>;
            this->first->next = temporaryNode;
            for (int i = 0; i < N - 1; i++)
            {
                temporaryNode->next = new List<T>;
                temporaryNode = temporaryNode->next;
            }
            temporaryNode = nullptr;
        }
    }



    ~SequenceList<T>()
    {
        if (this->isEmpty() == 0)
        {
            struct List<T>* temporaryNode;
            for (int i = 0; i < this->getLength() - 1; i++)
            {
                temporaryNode = this->first;
                if (this->first->next != nullptr)
                    this->first = this->first->next;
                delete temporaryNode;
            }
        }
    }



    T get(int index) const override
    {
        if ((index < 0) || (index >= this->getLength()))
            throw "Wrong index";
        auto temporaryNode = this->first;
        for (int i = 0; i < index; i++)
        {
            temporaryNode = temporaryNode->next;
        }
        return temporaryNode->data;
    }

    T getFirst() const override
    {
        if (this->isEmpty())
        {
            throw "Sequence is empty";
        }
        return this->first->data;
    }



    T getLast() const override
    {
        if (this->isEmpty())
        {
            throw "Sequence is empty";
        }
        auto temporaryNode = this->first;
        for (int i = 0; i < this->getLength() - 1; i++)
        {
            temporaryNode = temporaryNode->next;
        }
        return temporaryNode->data;
    }



    SequenceList<T>* getSubsequence(int startIndex, int endIndex)
    {
        if (this->isEmpty())
            throw "Sequence is empty";
        if ((startIndex < 0) || (startIndex > this->getLength()) || (endIndex < 0) || (endIndex > this->getLength()))
            throw "Wrong index";
        if (startIndex > endIndex)
            throw "Start index is more than last index";
        auto temporaryNode = this->first;
        auto newSequence = new SequenceList<T>(endIndex - startIndex + 1);
        for (int i = 0; i < startIndex; i++)
        {
            temporaryNode = temporaryNode->next;
        }
        newSequence->first->data = temporaryNode->data;
        auto temporaryNode2 = newSequence->first;
        for (int i = startIndex; i < endIndex; i++)
        {
            temporaryNode2 = temporaryNode2->next;
            temporaryNode = temporaryNode->next;
            temporaryNode2->data = temporaryNode->data;
        }
        return newSequence;
    }



    void append(const T& item) override
    {
        if (this->isEmpty())
        {
            this->first = new List<T>;
            this->first->data = item;
        }
        else
        {
            auto temporaryNode = this->first;
            for (int i = 0; i < this->getLength() - 1; i++)
            {
                temporaryNode = temporaryNode->next;
            }
            temporaryNode->next = new List<T>;
            temporaryNode->next->data = item;
        }
        this->length_ += 1;
    }



    void prepend(const T& item) override
    {
        this->length_ += 1;
        auto temporaryNode = new List<T>;
        temporaryNode->data = item;
        if (this->isEmpty())
        {
            this->first = temporaryNode;
        }
        else
        {
            temporaryNode->next = this->first;
            this->first = temporaryNode;
        }
    }



    void insertArt(int index, const T& item) override
    {
        if ((index < 0) || (index >= this->getLength()))
        {
            throw "Wrong index";
        }
        List<T>* temporaryNode;
        if (index == 0)
        {
            temporaryNode = new List<T>;
            temporaryNode->data = item;
            temporaryNode->next = this->first;
            this->first = temporaryNode;
        }
        else
        {
            temporaryNode = this->first;
            for (int i = 1; i < index; i++)
                temporaryNode = temporaryNode->next;
            auto temporaryNode2 = new List<T>;
            temporaryNode2->data = item;
            temporaryNode2->next = temporaryNode->next;
            temporaryNode->next = temporaryNode2;
        }
        this->length_ += 1;
    }



    int findItem(const T& item) const override
    {
        if (this->isEmpty())
            return 0;
        else
        {
            List<T>* temporaryNode = this->first;
            if (temporaryNode->data == item)
                return 1;
            for (int i = 1; i < this->getLength(); i++)
            {
                temporaryNode = temporaryNode->next;
                if (temporaryNode->data == item)
                    return i + 1;
            }
            return 0;
        }
    }



    void remove(const T& item) override
    {
        int position = this->findItem(item);
        if (position)
        {
            auto temporaryNode = this->first;
            if (position == 1)
            {
                this->first = this->first->next;
                delete temporaryNode;
            }
            else
            {
                for (int i = 0; i < position - 2; i++)
                    temporaryNode = temporaryNode->next;
                auto temporaryNode2 = temporaryNode->next;
                temporaryNode->next = temporaryNode2->next;
                delete temporaryNode2;
            }
        }
        this->length_ -= 1;
    }



    void output() const override
    {

        if (this->isEmpty())
            cout << "This sequence is empty" << endl;
        else
        {
            cout << "Your sequence:" << endl;
            auto temporaryNode = this->first;
            cout << temporaryNode->data << '\t';
            for (int i = 0; i < this->getLength() - 1; i++)
            {
                temporaryNode = temporaryNode->next;
                cout << temporaryNode->data << '\t';
            }
            cout << endl << endl;
        }
    }



    void inputElements() override
    {
        if (!(this->isEmpty()))
        {
            auto temporaryNode = this->first;
            cout << "Enter the items" << endl;
            cout << "Enter the first item" << endl;
            cin >> temporaryNode->data;
            for (int i = 0; i < this->getLength() - 1; i++)
            {
                temporaryNode = temporaryNode->next;
                cout << "Enter the " << i + 2 << " item" << endl;
                cin >> temporaryNode->data;
            }
        }
    }

    // Методы для 1 л/р:

    void set(T item, int index) override
    {
        auto temporaryNode = this->first;
        if (index == 0)
        {
            this->first->data = item;
        }
        for (int i = 0; i < index; i++)
            temporaryNode = temporaryNode->next;
        temporaryNode->data = item;
    }

private:
    List<T>* first;
};
