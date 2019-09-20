//
// Created by gerko on 18.09.2019.
//

#pragma once
#include "Header.h"
#include <iostream>



template <typename T>
class SequenceArray : public Sequence<T>
{
public:

    using SizeType = typename Sequence<T>::SizeType;
    
    Iterator<T>* getIterator()
    {
        auto it = new Iterator<T>(this);
        return it;
    }



    SizeType getMemoryLength() const
    {
        return memoryLength_;
    }



    explicit SequenceArray()
    {
        this->length_ = 0;
        memoryLength_ = 1;
        elements_ = new T[1];
    }



    ~SequenceArray()
    {
        delete [] elements_;
    }



    T get(SizeType index) const override
    {
        if (index < 0)
            throw std::invalid_argument("Invalid argument");
        if (index >= this->length_)
            throw std::out_of_range("Argument is out of range");

        return elements_[index];
    }



    T getFirst() const override
    {
        if (this->isEmpty())
            throw std::out_of_range("Sequence is empty");
        return elements_[0];
    }



    T getLast() const override
    {
        if (this->isEmpty())
            throw std::out_of_range("Sequence is empty");

        return elements_[this->length_ - 1];
    }



    SequenceArray<T>* getSubsequence(SizeType startIndex, SizeType endIndex)
    {
        if (this->isEmpty())
            throw std::out_of_range("Sequence is empty");
        if ((startIndex < 0) || (startIndex > this->length_) || (endIndex < 0) || (endIndex > this->length_))
            throw std::invalid_argument("Invalid index");
        if (startIndex > endIndex)
            throw std::invalid_argument("Start index is more than last index");
        if ((startIndex > this->length_) || (endIndex > this->length_))
            throw std::out_of_range("Indices is out of range");

        auto newSequence = new SequenceArray<T>(endIndex - startIndex + 1);
        for (auto i = startIndex; i < endIndex + 1; i++)
            newSequence->elements_[i - startIndex] = this->get(i);
        return newSequence;
    }



    void swap(SizeType i, SizeType j) noexcept
    {
        T element = this->get(i);
        this->set(this->get(j), i);
        this->set(element, j);
    }



    void append(const T& item) override
    {
        if (this->length_ == this->getMemoryLength())
            resize(this->length_ * 2);
        this->elements_[this->length_++] = item;
    }



    void prepend(const T& item) override        //too expensive to use in practice
    {
        if (this->length_ == this->getMemoryLength())

            resize(this->length_ * 2);
        elements_[this->length_++] = item;
        for (auto i = this->length_-1; i > 0; i--)
        {
            swap(i, i - 1);
        }


    }



    void insertArt(SizeType index, const T& item) override
    {
        if (index < 0)
            throw std::invalid_argument("Invalid argument");
        if (index >= this->length_)
            throw std::out_of_range("Argument is out of range");

        if (this->length_ == this->getMemoryLength())
            resize(this->length_ * 2);
        this->elements_[this->length_++] = item;
        for (auto i = this->length_ - 1; i > index; i--)
        {
            swap(i, i - 1);
        }
        
    }



    void remove(const T& item) override
    {
        SizeType position = this->findItem(item);
        if (position != 0) {
            if (this->length_ == this->memoryLength_ / 4)
                resize(this->memoryLength_ / 2);
            for (auto i = position - 1; i < this->length_ - 1; i++)
                swap(i, i + 1);
            this->length_--;
        }
    }



    void output() const override
    {
        if (this->isEmpty())
            std::cout << "This sequence is empty" << std::endl;
        else
        {
            std::cout << "Your sequence:" << std::endl;
            for (auto i = 0; i < this->length_; i++)
            {
                std::cout << this->get(i) << '\t';
            }
            std::cout << std::endl << std::endl;
        }
    }



    void inputElements(SizeType numberOfElements) override
    {
        T item;
        std::cout << "Enter the items" << std::endl;
        for (auto i = 0; i < numberOfElements; i++)
        {
            std::cout << "Enter the " << i + 1 << " item" << std::endl;
            std::cin >> item;
            this->append(item);
        }

    }

    // Методы для 1 л/р:

    void set(T item, SizeType index) override
    {
        this->elements_[index] = item;
    }

private:

    SizeType memoryLength_;
    T* elements_;

    SizeType findItem(const T& item) const override
    {
        for (auto i = 0; i < this->length_; i++)
        {
            if (this->elements_[i] == item)
                return i + 1;
        }
        return 0;
    }


    
    void resize(size_t capacity)
    {
        this->memoryLength_ = capacity;
        auto temporaryArray = new T[this->getMemoryLength()];
        for (auto i = 0; i < this->length_; i++)
        {
            temporaryArray[i] = this->get(i);
        }
        this->elements_ = temporaryArray;
    }



    SequenceArray(const SequenceArray&) {};

    void operator=(const SequenceArray&) {};
};




void test_iterator()
{
    auto sequence = new SequenceArray<int>();
    sequence->append(0);
    sequence->append(1);
    sequence->append(3);
    sequence->append(2);
    Iterator<int>* it = sequence->getIterator();
    for (int i = 0; it->HasNext(); it->Next())
    {
        if (it->CurrentItem() != sequence->get(i))
        {
            std::cout << "Test.iterator isn't passed" << std::endl;
            break;
        }
        i += 1;
    }
    std::cout << "Test.iterator is passed" << std::endl;
}