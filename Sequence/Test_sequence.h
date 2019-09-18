#pragma once
#include "Header.h"
#include "Sequence_list.h"
#include "Sequence_array.h"

bool test_sequence()
{
	cout << "Test 6.1.1" << endl;
	Array_Sequence<int> *sequence = new Array_Sequence<int>();
	cout << "passed" << endl;
	cout << "Test 6.1.2" << endl;
	if (sequence->GetLength() != 0)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.3" << endl;
	sequence->Append(23);
	cout << "passed" << endl;
	cout << "Test 6.1.4" << endl;
	if (sequence->GetLength() != 1)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.5" << endl;
	if (sequence->GetFirst() != 23)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.6" << endl;
	if (sequence->GetLast() != 23)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.7" << endl;
	if (sequence->Get(0) != 23)
		return false;
	try
	{
		sequence->Get(1);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	try
	{
		sequence->Get(-1);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "passed" << endl;
	cout << "Test 6.1.8" << endl;
	sequence->Append(43);
	cout << "passed" << endl;
	cout << "Test 6.1.9" << endl;
	if (sequence->GetLength() != 2)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.10" << endl;
	if (sequence->GetFirst() != 23)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.11" << endl;
	if (sequence->GetLast() != 43)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.12" << endl;
	if (sequence->Get(0) != 23)
		return false;
	try
	{
		sequence->Get(-1);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	try
	{
		sequence->Get(2);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "passed" << endl;
	cout << "Test 6.1.13" << endl;
	sequence->Prepend(53);
	cout << "passed" << endl;
	cout << "Test 6.1.14" << endl;
	if (sequence->GetLength() != 3)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.15" << endl;
	if (sequence->GetFirst() != 53)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.16" << endl;
	if (sequence->GetLast() != 43)
		return false;
	cout << "passed" << endl;
	cout << "Test 6.1.17" << endl;
	if (sequence->Get(0) != 53)
		return false;
	if (sequence->Get(1) != 23)
		return false;
	try
	{
		sequence->Get(-1);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	try 
	{
		sequence->Get(3);
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	cout << "passed" << endl;
	cout << "Test 6.1.18" << endl;
	Array_Sequence<int> *new_sequence = sequence->GetSubsequence(1, 1);
	if (new_sequence->GetLength() != 1)
		return false;
	if (new_sequence->GetFirst() != 23)
		return false;
	if (new_sequence->GetLast() != 23)
		return false;
	cout << "passed" << endl;
	return true;
}