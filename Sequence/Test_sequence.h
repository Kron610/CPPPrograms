//
// Created by gerko on 18.09.2019.
//

#pragma once
#include "Header.h"
#include "Sequence_list.h"
#include "Sequence_array.h"

bool testSequence()
{
    cout << "Test 6.1.1" << endl;
    auto sequence = new SequenceArray<int>();
    cout << "passed" << endl;
    cout << "Test 6.1.2" << endl;
    if (sequence->getLength() != 0)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.3" << endl;
    sequence->append(23);
    cout << "passed" << endl;
    cout << "Test 6.1.4" << endl;
    if (sequence->getLength() != 1)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.5" << endl;
    if (sequence->getFirst() != 23)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.6" << endl;
    if (sequence->getLast() != 23)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.7" << endl;
    if (sequence->get(0) != 23)
        return false;
    try
    {
        sequence->get(1);
        return false;
    }
    catch (std::exception& exception)
    {
        cout << exception.what() << endl;
    }
    try
    {
        sequence->get(-1);
        return false;
    }
    catch (std::exception& exception)
    {
        cout << exception.what() << endl;
    }
    cout << "passed" << endl;
    cout << "Test 6.1.8" << endl;
    sequence->append(43);
    cout << "passed" << endl;
    cout << "Test 6.1.9" << endl;
    if (sequence->getLength() != 2)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.10" << endl;
    if (sequence->getFirst() != 23)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.11" << endl;
    if (sequence->getLast() != 43)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.12" << endl;
    if (sequence->get(0) != 23)
        return false;
    try
    {
        sequence->get(-1);
        return false;
    }
    catch (std::exception& exception)
    {
        cout << exception.what() << endl;
    }
    try
    {
        sequence->get(2);
        return false;
    }
    catch (std::exception& exception)
    {
        cout << exception.what() << endl;
    }
    cout << "passed" << endl;
    cout << "Test 6.1.13" << endl;
    sequence->prepend(53);
    cout << "passed" << endl;
    cout << "Test 6.1.14" << endl;
    if (sequence->getLength() != 3)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.15" << endl;
    if (sequence->getFirst() != 53)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.16" << endl;
    if (sequence->getLast() != 43)
        return false;
    cout << "passed" << endl;
    cout << "Test 6.1.17" << endl;
    if (sequence->get(0) != 53)
        return false;
    if (sequence->get(1) != 23)
        return false;
    try
    {
        sequence->get(-1);
        return false;
    }
    catch (std::exception& exception)
    {
        cout << exception.what() << endl;
    }
    try
    {
        sequence->get(3);
        return false;
    }
    catch (std::exception& exception)
    {
        cout << exception.what() << endl;
    }
    cout << "passed" << endl;
    cout << "Test 6.1.18" << endl;
    SequenceArray<int> *new_sequence = sequence->getSubsequence(1, 1);
    if (new_sequence->getLength() != 1)
        return false;
    if (new_sequence->getFirst() != 23)
        return false;
    if (new_sequence->getLast() != 23)
        return false;
    cout << "passed" << endl;
    return true;
}