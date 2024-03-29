﻿// LabSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Sortr.h"
#include <stdio.h>
#include <iostream>
#define ARR_SIZE 100000
#define RANGE 10000
using namespace std;

int main()
{
	cout << "Heap Sort" << endl;
	automatic_test(HeapSort);
	cout << "Shell's Sort" << endl;
	automatic_test(ShellSort);
	cout << "Quick Sort" << endl;
	automatic_test(QuickSort);
	int q = 1;
	while (q)
	{
		cout << "There are three types of sort in program. 1: Quick sort, 2: Heap sort, 3: Shell's sort. \n Choose the action:\n 1 - compare two sorts\n 2 - test the sort\n 3 - measure the sorting time\n 4 - exit\n";
		int key = -1;
		while ((key != 1) & (key != 2) & (key != 3) & (key != 4))
			cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
		{
			compare_sorts();
			break;
		}
		case 2:
		{
			test_sorts();
			break;
		}
		case 3:
		{
			check_time();
			break;
		}
		case 4:
		{
			q = 0;
			break;
		}
		default:
			break;
		}
	}
}
