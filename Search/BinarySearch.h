#pragma once
#include "SortedSequence.h"
#include "Treeh.h"
#include <chrono>
using namespace std;

int Fib(int n)
{
	if ((n == 0) || (n == 1))
	{
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}

template <typename T>
int Search_Binary(SortedSequence<T>* sequence, T key, int flag = 0)
{
	int left = 0;
	int right = sequence->GetLength() - 1;
	if (flag == 0)
	{
		int midd = 0;
		while (1)
		{
			midd = (left + right) / 2;
			if (key < (sequence->Get(midd)))       // если искомое меньше значени€ в €чейке
				right = midd - 1;      // смещаем правую границу поиска
			else if (key > (sequence->Get(midd)))  // если искомое больше значени€ в €чейке
				left = midd + 1;    // смещаем левую границу поиска
			else                       // иначе (значени€ равны)
				return midd;           // функци€ возвращает индекс €чейки
			if (left > right)          // если границы сомкнулись 
				return -1;
		}
	}
	if (flag == 1)
	{ 
		const float F = 1.618;
		int x1 = left - (left - right) / F;
		int x2 = right + (left - right) / F;
		while (1)
		{
			if (key == sequence->Get(x1))
				return x1;
			if (key == sequence->Get(x2))
				return x2;
			if (key < sequence->Get(x2))
			{
				right = x2 - 1;
				x2 = x1;
				x1 = left - (left - right) / F;
			}
			else
			{
				left = x1 + 1;
				x2 = x1;
				x1 = right + (left - right) / F;
			}
			if (left > right)        
				return -1;
		}
	}

	if (flag == 2)
	{
		int a, b;
		cout << "Enter integer numbers" << endl;
		cin >> a >> b;
		float F1 = a / (a + b);
		float F2 = b / (a + b);
		int midd;
		while (1)
		{
			midd = left + (right - left)*F1;
			if (midd > right)
				midd = right - (right - left)*F2;
			if (key < (sequence->Get(midd)))       // если искомое меньше значени€ в €чейке
				right = midd - 1;      // смещаем правую границу поиска
			else if (key > (sequence->Get(midd)))  // если искомое больше значени€ в €чейке
				left = midd + 1;    // смещаем левую границу поиска
			else                       // иначе (значени€ равны)
				return midd;           // функци€ возвращает индекс €чейки
			if (left > right)          // если границы сомкнулись 
				return -1;
		}
	}

	if (flag == 3)
	{
		int number;
		cout << "Enter the number" << endl;
		cin >> number;
		float F = Fib(number - 1);
		F = F / Fib(number);
		int midd;
		while (1)
		{
			midd = (left + right) *F;
			if (key < (sequence->Get(midd)))       // если искомое меньше значени€ в €чейке
				right = midd - 1;      // смещаем правую границу поиска
			else if (key > (sequence->Get(midd)))  // если искомое больше значени€ в €чейке
				left = midd + 1;    // смещаем левую границу поиска
			else                       // иначе (значени€ равны)
				return midd;           // функци€ возвращает индекс €чейки
			if (left > right)          // если границы сомкнулись 
				return -1;
		}
	}
	
	return -1;
}

template <typename T>
int time_function1(SortedSequence<T>* sequence, T key, int flag)
{
	auto t = chrono::high_resolution_clock::now();
	int find = Search_Binary<T>(sequence,key,flag);
	auto t2 = chrono::high_resolution_clock::now();
	cout << "Time of searching: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t).count() << endl;
	return find;
}

void test_fib()
{
	if (Fib(3) == 3)
		cout << "Test.Fib passed" << endl;
	else
		cout << "Test.Fib isn't passed" << endl;
}

void test_Search_Binary()
{
	SortedArraySequence<int>* sequence =new SortedArraySequence<int>();
	sequence->Add(1);
	sequence->Add(2);
	sequence->Add(3);
	if ((Search_Binary(sequence,1,0)==0)&&(Search_Binary(sequence,4,1)==-1))
		cout << "Test.search passed" << endl;
	else
		cout << "Test.search isn't passed" << endl;
}




