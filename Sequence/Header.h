//
// Created by gerko on 18.09.2019.
//

#pragma once
#include <iostream>

using namespace std;
template<typename T> class Sequence
{

public:
    int getLength() const
    {
        return length_;
    }

    int isEmpty() const
    {
        return length_ == 0;
    }



    virtual T get(int index) const  = 0;
    virtual T getFirst() const  = 0;
    virtual T getLast() const = 0;
    virtual void append(const T& item) = 0;
    virtual void prepend(const T& item) = 0;
    virtual void insertArt(int index, const T &item) = 0;
    virtual void remove(const T& item) = 0;
    virtual void output() const = 0;
    virtual void inputElements() = 0;
    virtual void set(T item, int index) = 0;

protected:
    int length_;

    virtual int findItem(const T& item) const  = 0;

};

template <typename T>
class Iterator
{
private:
    Sequence<T>* sequence;
    int index;
public:
    explicit Iterator<T>(Sequence<T>* sequence1)
    {
        sequence = sequence1;
        index = 0;
    }

    bool HasNext()
    {
        if (index == sequence->getLength())
            return false;
        return true;
    }

    T CurrentItem()
    {
        if (HasNext())
            return sequence->get(index);
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