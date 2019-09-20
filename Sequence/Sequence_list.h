//
// Created by gerko on 18.09.2019.
//

#pragma once
#include "Header.h"
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    Node* next;
    Node* previous;
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
        if (!(this->isEmpty()))
        {
            Node<T>* temporaryNode;
            for (SizeType i = 0; i < this->length_ - 1; i++)
            {
                temporaryNode = first_;
                if (first_->next != nullptr)
                    first_ = first_->next;
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
        Node<T>* temporaryNode;
        if (index < this->length_ / 2)
        {
            temporaryNode = first_;
            for (SizeType i = 0; i < index; i++)
                temporaryNode = temporaryNode->next;

        }
        else {
            temporaryNode = last_;
            for (int i = this->length_ - 1; i > index; i--)
                temporaryNode = temporaryNode->previous;
        }
        return temporaryNode->data;
    }

    T getFirst() const override
    {
        if (this->isEmpty())
            throw std::out_of_range("Sequence is empty");

        return first_->data;
    }



    T getLast() const override
    {
        if (this->isEmpty())
            throw std::out_of_range("Sequence is empty");

        return last_->data;
    }



    SequenceList<T>* getSubsequence(SizeType startIndex, SizeType endIndex)
    {
        if (this->isEmpty())
            throw std::out_of_range("Sequence is empty");
        if ((startIndex < 0) || (startIndex > this->length_) || (endIndex < 0) || (endIndex > this->length_))
            throw std::invalid_argument("Invalid index");
        if (startIndex > endIndex)
            throw std::invalid_argument("Start index is more than last index");
        if ((startIndex > this->length_) || (endIndex > this->length_))
            throw std::out_of_range("Indices is out of range");

        auto newSequence = new SequenceList();
        for (auto i = startIndex; i < endIndex + 1; i++)
            newSequence->append(this->get(i));
        return newSequence;
    }



    void append(const T& item) override
    {
        if (this->isEmpty())
        {
            last_ = new Node<T>;
            last_->data = item;
            last_->next = 0;
            last_->previous = 0;
            first_ = last_;
        }
        else
        {
            Node<T>* oldLast = last_;
            last_ = new Node<T>;
            last_->data = item;
            last_->previous = oldLast;
            last_->next = 0;
            oldLast->next = last_;
        }
        this->length_ += 1;
    }



    void prepend(const T& item) override
    {
        if (this->isEmpty())
        {
            first_ = new Node<T>;
            first_->data = item;
            first_->next = 0;
            first_->previous = 0;
            last_ = first_;
        }
        else
        {
            Node<T>* oldFirst = first_;
            first_ = new Node<T>;
            first_->data = item;
            first_->next = oldFirst;
            first_->previous = 0;
            oldFirst->previous = first_;
        }
        this->length_ += 1;
    }



    void insertArt(SizeType index, const T& item) override
    {
        if (index < 0)
            throw std::invalid_argument("Invalid argument");
        if (index >= this->length_)
            throw std::out_of_range("Argument is out of range");

        Node<T>* temporaryNode;
        if (index == 0)
        {
            prepend(item);
            this->length_ += 1;
            return;
        }
        if (index == this->length_ - 1)
        {
            append(item);
            this->length_ += 1;
            return;
        }

        if (index < this->length_ / 2)
        {
            temporaryNode = first_;
            for (SizeType i = 1; i < index; i++)
                temporaryNode = temporaryNode->next;
            auto temporaryNode2 = new Node<T>;
            temporaryNode2->data = item;
            temporaryNode2->next = temporaryNode->next;
            temporaryNode->next->previous = temporaryNode2;
            temporaryNode->next = temporaryNode2;
            temporaryNode2->previous = temporaryNode;
            this->length_ += 1;
        }
        else {
            temporaryNode = last_;
            for (SizeType i = this->length_ - 1; i > index; i--)
                temporaryNode = temporaryNode->previous;
            auto temporaryNode2 = new Node<T>;
            temporaryNode2->data = item;
            temporaryNode2->previous = temporaryNode->previous;
            temporaryNode->previous->next = temporaryNode2;
            temporaryNode->previous = temporaryNode2;
            temporaryNode2->next = temporaryNode;
            this->length_ += 1;
        }
    }



    SizeType findItem(const T& item) const override
    {
        if (this->isEmpty())
            return 0;
        else
        {
            Node<T>* temporaryNode = first_;
            if (temporaryNode->data == item)
                return 1;
            for (SizeType i = 1; i < this->length_; i++)
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
        SizeType position = findItem(item);
        if (position)
        {
            auto temporaryNode = first_;
            if (position == 1)
            {
                first_ = first_->next;
                first_->previous = 0;
                delete temporaryNode;
            }
            else
            {
                if (position - 1 < this->length_ / 2)
                {
                    for (auto i = 0; i < position - 2; i++)
                        temporaryNode = temporaryNode->next;
                    auto temporaryNode2 = temporaryNode->next;
                    temporaryNode->next = temporaryNode2->next;
                    temporaryNode->next->previous = temporaryNode;
                    delete temporaryNode2;
                }
                else {
                    temporaryNode = last_;
                    for (auto i = this->length_ - 1; i > position - 1; i--)
                        temporaryNode = temporaryNode->previous;
                    auto temporaryNode2 = temporaryNode->previous;
                    temporaryNode->previous = temporaryNode2->previous;
                    temporaryNode->previous->next = temporaryNode;
                    delete temporaryNode2;
                }
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
                this->append(item);
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
    Node<T>* first_;
    Node<T>* last_;
};
