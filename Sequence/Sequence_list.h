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
    List* next;
    T data;
};

template <typename T>
class SequenceList : public Sequence<T>
{

public:

    using SizeType = typename Sequence<T>::SizeType;

    Iterator<T>* getIterator()
    {
        auto it = new Iterator<T>(this);
        return it;
    }



    explicit SequenceList()
    {
        first_ = 0;
        this->length_ = 0;
    }



    ~SequenceList()
    {
        if (this->isEmpty() == 0)
        {
            struct List<T>* temporaryNode;
            for (SizeType i = 0; i < this->getLength() - 1; i++)
            {
                temporaryNode = this->first_;
                if (this->first_->next != nullptr)
                    this->first_ = this->first_->next;
                delete temporaryNode;
            }
        }
    }



    T get(SizeType index) const override
    {

        if (index < 0)
            throw std::invalid_argument("Invalid argument");
        if (index >= this->length_)
            throw std::out_of_range("Argument is out of range");
        auto temporaryNode = this->first_;
        for (SizeType i = 0; i < index; i++)
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
        return this->first_->data;
    }



    T getLast() const override
    {
        if (this->isEmpty())
        {
            throw "Sequence is empty";
        }
        auto temporaryNode = this->first_;
        for (SizeType i = 0; i < this->getLength() - 1; i++)
        {
            temporaryNode = temporaryNode->next;
        }
        return temporaryNode->data;
    }



    SequenceList<T>* getSubsequence(SizeType startIndex, SizeType endIndex)
    {
        if (this->isEmpty())
            throw "Sequence is empty";
        if ((startIndex < 0) || (startIndex > this->getLength()) || (endIndex < 0) || (endIndex > this->getLength()))
            throw "Wrong index";
        if (startIndex > endIndex)
            throw "Start index is more than last index";
        auto temporaryNode = this->first_;
        auto newSequence = new SequenceList<T>(endIndex - startIndex + 1);
        for (SizeType i = 0; i < startIndex; i++)
        {
            temporaryNode = temporaryNode->next;
        }
        newSequence->first_->data = temporaryNode->data;
        auto temporaryNode2 = newSequence->first_;
        for (SizeType i = startIndex; i < endIndex; i++)
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
            this->first_ = new List<T>;
            this->first_->data = item;
        }
        else
        {
            auto temporaryNode = this->first_;
            for (SizeType i = 0; i < this->getLength() - 1; i++)
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
            this->first_ = temporaryNode;
        }
        else
        {
            temporaryNode->next = this->first_;
            this->first_ = temporaryNode;
        }
    }



    void insertArt(SizeType index, const T& item) override
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
            temporaryNode->next = this->first_;
            this->first_ = temporaryNode;
        }
        else
        {
            temporaryNode = this->first_;
            for (SizeType i = 1; i < index; i++)
                temporaryNode = temporaryNode->next;
            auto temporaryNode2 = new List<T>;
            temporaryNode2->data = item;
            temporaryNode2->next = temporaryNode->next;
            temporaryNode->next = temporaryNode2;
        }
        this->length_ += 1;
    }



    SizeType findItem(const T& item) const override
    {
        if (this->isEmpty())
            return 0;
        else
        {
            List<T>* temporaryNode = this->first_;
            if (temporaryNode->data == item)
                return 1;
            for (SizeType i = 1; i < this->getLength(); i++)
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
        SizeType position = this->findItem(item);
        if (position)
        {
            auto temporaryNode = this->first_;
            if (position == 1)
            {
                this->first_ = this->first_->next;
                delete temporaryNode;
            }
            else
            {
                for (SizeType i = 0; i < position - 2; i++)
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
            std::cout << "This sequence is empty" << std::endl;
        else
        {
            std::cout << "Your sequence:" << std::endl;
            auto temporaryNode = this->first_;
            std::cout << temporaryNode->data << '\t';
            for (SizeType i = 0; i < this->getLength() - 1; i++)
            {
                temporaryNode = temporaryNode->next;
                std::cout << temporaryNode->data << '\t';
            }
            std::cout << std::endl << std::endl;
        }
    }



    void inputElements(SizeType numberOfElements) override
    {
            std::cout << "Enter the items" << std::endl;
            std::cout << "Enter the first_ item" << std::endl;
            T item;
            for (SizeType i = 0; i < numberOfElements; i++)
            {
                std::cout << "Enter the " << i + 1 << " item" << std::endl;
                std::cin >> item;
                this->prepend(item);
            }
    }

    // Методы для 1 л/р:

    void set(T item, SizeType index) override
    {
        auto temporaryNode = this->first_;
        if (index == 0)
        {
            this->first_->data = item;
        }
        for (SizeType i = 0; i < index; i++)
            temporaryNode = temporaryNode->next;
        temporaryNode->data = item;
    }

private:
    List<T>* first_;
};
