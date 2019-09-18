#pragma once
#include "Header.h"
#include "Sequence_array.h"
#include "Sequence_list.h"
#include <time.h>
#include <stdlib.h>



template <typename T>
void ShellSort(Sequence<T>* sequence)
{
	int i, j, step;
	T tmp;
	int n = sequence->GetLength();
	for (step = n / 2; step > 5; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = sequence->Get(i);
			for (j = i; j >= step; j -= step)
			{
				if (tmp < sequence->Get(j-step))
					sequence->Put(sequence->Get(j - step),j);
				else
					break;
			}
			sequence->Put(tmp,j);
		}
}



template <typename T>
void quickSortR(Sequence<T>* sequence, int first, int last)
{
	if (first < last)
	{
		int left = first, right = last, middle = sequence->Get((left + right) / 2);
		do
		{
			while (sequence->Get(left) < middle) left++;
			while (sequence->Get(right) > middle) right--;
			if (left <= right)
			{
				T tmp = sequence->Get(left);
				sequence->Put(sequence->Get(right),left);
				sequence->Put(tmp, right);
				left++;
				right--;
			}
		} while (left <= right);
		quickSortR(sequence, first, right);
		quickSortR(sequence, left, last);
	}
}



template <typename T>
void QuickSort(Sequence<T>* sequence)
{
	int left = 0;
	quickSortR(sequence, left, sequence->GetLength() - 1);
}



template<typename T>
void downHeap(Sequence<T>* sequence, int k, int n) {
	//  процедура просеивания следующего элемента 
	//  До процедуры: a[k+1]...a[n]  - пирамида 
	//  После:  a[k]...a[n]  - пирамида 
	T new_elem;
	long child;
	new_elem = sequence->Get(k);

	while (k <= n / 2) {  		// пока у a[k] есть дети 
		child = 2 * k;
		//  выбираем большего сына 
		if (child < n && sequence->Get(child) < sequence->Get(child+1))
			child++;
		if (new_elem >= sequence->Get(child)) break;
		// иначе 
		sequence->Put(sequence->Get(child),k); 	// переносим сына наверх 
		k = child;
	}
	sequence->Put(new_elem, k);
}



template<typename T>
void HeapSort(Sequence<T>* sequence) 
{
	int size = sequence->GetLength();
	int i;
	T temp;

	// строим пирамиду 
	for (i = size / 2 - 1; i >= 0; i--) downHeap(sequence, i, size - 1);

	// теперь a[0]...a[size-1] пирамида 

	for (i = size - 1; i > 0; i--) {
		// меняем первый с последним 
		temp = sequence->Get(i); sequence->Put(sequence->Get(0),i); sequence->Put(temp,0);

		// восстанавливаем пирамидальность a[0]...a[i-1] 
		downHeap(sequence, 0, i - 1);
	}
}



template<typename T>
clock_t time_function(void(*Sort)(Sequence<T>* sequence), Sequence<T>* sequence)
{
	clock_t t = clock();
	Sort(sequence);
	t = clock() - t;
	return t;
}



template<typename T>
void fill_random(Sequence<T>* sequence, int range)
{
	srand(time(NULL));
	for (int i = 0; i< sequence->GetLength(); i++)
		sequence->Put(rand() % range, i);
}

template<typename T>
void sort_comparison(void(*Sort1)(Sequence<T>* sequence), void(*Sort2)(Sequence<T>* sequence), int SIZE, int RANGE = 20000)
{
	Array_Sequence<T>* sequence_1 = new Array_Sequence<T>(SIZE);
	fill_random(sequence_1, RANGE);
	clock_t t1 = time_function(Sort1, sequence_1);
	fill_random(sequence_1, RANGE);
	clock_t t2 = time_function(Sort2, sequence_1);
	if (t1 > t2)
		cout << "The second sort is faster than the first on " << SIZE << " random items" << endl;
	else
		if (t1 == t2)
			cout << "Sort times are the same on " << SIZE << " items" << endl;
		else
			cout << "The first sort is faster than the second on " << SIZE << " random items" << endl;
	cout << "Time of the first: " <<t1 << '\t' << "Time of the second: " << t2 << endl;
	t1 = time_function(Sort1, sequence_1);
	t2 = time_function(Sort2, sequence_1);
	if (t1 > t2)
		cout << "The second sort is faster than the first on " << SIZE << " ordered random items" << endl;
	else
		if (t1 == t2)
			cout << "Sort times are the same on " << SIZE << " ordered random items" << endl;
		else
			cout << "The first sort is faster than the second on " << SIZE << " ordered random items" << endl;
	cout << "Time of the first: " << t1 << '\t' << "Time of the second: " << t2 << endl;
	change_order(sequence_1);
	t1 = time_function(Sort1, sequence_1);
	change_order(sequence_1);
	t2 = time_function(Sort2, sequence_1);
	if (t1 > t2)
		cout << "The second sort is faster than the first on " << SIZE << " inversely ordered random items" << endl;
	else
		if (t1 == t2)
			cout << "Sort times are the same on " << SIZE << " inversely ordered random items" << endl;
		else
			cout << "The first sort is faster than the second on " << SIZE << " inversely ordered random items" << endl;
	cout << "Time of the first: " << t1 << '\t' << "Time of the second: " << t2 << endl;
}



template <typename T>
void change_order(Sequence<T>* sequence)
{
	int i = 0;
	int j = sequence->GetLength() - 1;
	T element;
	while (i < j)
	{
		element = sequence->Get(i);
		sequence->Put(sequence->Get(j),i);
		sequence->Put(element, j);
		i++;
		j--;
	}
}



template <typename T>
int test_is_ordered(Sequence<T>* sequence)
{
	int check = 1;
	for (int i = 0; i < sequence->GetLength() - 1; i++)
	{
		if (sequence->Get(i) > sequence->Get(i + 1))
		{
			check = 0;
			break;
		}
	}
	if (check)
	{
		cout << "Sequence is ordered\n";
		return 1;
	}
	else
	{
		cout << "Sequence isn't ordered\n";
		return 0;
	}
}



void compare_sorts()
{
	void(*sort1)(Sequence<int>*) = QuickSort;
	void(*sort2)(Sequence<int>*) = QuickSort;
	cout << "Choose two sorts.\n 1 - Quick sort and Heap sort,\n 2 - Quick sort and Shell's sort,\n 3 - Heap sort and Shell's sort \n";
	int key = -1;
	while ((key != 1) & (key != 2) & (key != 3))
		cin >> key;
	cout << endl;
	switch (key)
	{
	case 1:
	{
		sort1 = QuickSort;
		sort2 = HeapSort;
		break;
	}
	case 2:
	{
		sort1 = QuickSort;
		sort2 = ShellSort;
		break;
	}
	case 3:
	{
		sort1 = HeapSort;
		sort2 = ShellSort;
		break;
	}
	default:
		break;
	}
	int Size = -1;
	cout << "Enter the number of elements for comparison" << endl;
	while (Size < 1)
		cin >> Size;
	cout << endl;
	sort_comparison<int>(sort1, sort2, Size);
}



void test_sorts()
{
	void(*sort1)(Sequence<int>*) = QuickSort;
	int Size = -1;
	cout << "Choose sort.\n 1 - Quick sort,\n 2 - Heap sort,\n 3 - Shell's sort \n";
	int key = -1;
	while ((key != 1) & (key != 2) & (key != 3))
		cin >> key;
	cout << endl;
	switch (key)
	{
	case 1:
	{
		sort1 = QuickSort;
		break;
	}
	case 2:
	{
		sort1 = HeapSort;
		break;
	}
	case 3:
	{
		sort1 = ShellSort;
		break;
	}
	default:
		break;
	}
	cout << "Enter number of elements to test" << endl;
	while (Size < 1)
		cin >> Size;
	Array_Sequence<int>* sequence = new Array_Sequence<int>(Size);
	cout << "Do you want to enter elements or use random sequence?\n 1 - My sequence\n 2 - Random sequence" << endl;
	key = -1;
	while ((key != 2) & (key != 1))
		cin >> key;
	cout << endl;
	if (key == 1)
		sequence->InputElements();
	else
	{
		cout << "Enter the range\n";
		int range;
		cin >> range;
		cout << endl;
		fill_random<int>(sequence, range);
	}
	cout << "Do you want to output elements?\n 1- yes, 0 - no\n";
	key = -1;
	while ((key != 0) & (key != 1))
		cin >> key;
	if (key)
		sequence->Output();
	cout << endl;
	sort1(sequence);
	test_is_ordered(sequence);
	cout << "Do you want to output elements?\n 1- yes, 0 - no\n";
	key = -1;
	while ((key != 0) & (key != 1))
		cin >> key;
	if (key)
		sequence->Output();
	cout << endl;
}



void check_time()
{
	void(*sort1)(Sequence<int>*) = QuickSort;
	int Size = -1;
	cout << "Choose sort.\n 1 - Quick sort,\n 2 - Heap sort,\n 3 - Shell's sort \n";
	int key = -1;
	while ((key != 1) & (key != 2) & (key != 3))
		cin >> key;
	cout << endl;
	switch (key)
	{
	case 1:
	{
		sort1 = QuickSort;
		break;
	}
	case 2:
	{
		sort1 = HeapSort;
		break;
	}
	case 3:
	{
		sort1 = ShellSort;
		break;
	}
	default:
		break;
	}
	cout << "Enter number of elements to test" << endl;
	while (Size < 1)
		cin >> Size;
	Array_Sequence<int>* sequence = new Array_Sequence<int>(Size);
	cout << "Do you want to enter elements or use random sequence?\n 1 - My sequence\n 2 - Random sequence" << endl;
	key = -1;
	while ((key != 2) & (key != 1))
		cin >> key;
	cout << endl;
	if (key == 1)
		sequence->InputElements();
	else
	{
		cout << "Enter the range\n";
		int range;
		cin >> range;
		cout << endl;
		fill_random<int>(sequence, range);
	}
	cout << " The time of sort:\n" << time_function<int>(sort1, sequence) << endl;
}



void automatic_test( void(*sort1)(Sequence<int>*) )
{
	int size = 10000;
	int range = 10000;
	Array_Sequence<int>* sequence = new Array_Sequence<int>(size);
	fill_random<int>(sequence, range);
	sort1(sequence);
	if (test_is_ordered<int>(sequence))
		cout << "Sort works correctly" << endl;
	else
		cout << "Sort does not work correctly" << endl;
}