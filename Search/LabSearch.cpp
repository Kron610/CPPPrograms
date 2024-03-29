﻿
#include <iostream>
#include "Student.h"
#include "BinarySearch.h"
#include "Sequence_array.h"

using namespace std;

int main()
{
	test_Search_Binary();
	test_fib();
	test_tree_max();
	test_tree_min();
	test_tree_search();
	test_iterator();
	int key = -1;
	int q1 = 1;
	while (q1)
	{
		cout << "Enter the type of data:\n 1 - integer numbers, 2 - students, 3 - exit" << endl;
		key = -1;
		while ((key != 1) && (key != 2) && (key != 3))
			cin >> key;
		switch (key)
		{
		case 1:
		{
			int N = -1;
			cout << "Enter the number of elements" << endl;
			while (N < 0)
				cin >> N;
			int key1 = -1;
			cout << "Enter the type of storage:\n 1 - array, 2 - list" << endl;
			while ((key1 != 1) && (key1 != 2))
				cin >> key1;
			switch (key1)
			{
			case 1:
			{
				SortedArraySequence<int>* sequence = new SortedArraySequence<int>(N);
				cout << "Do you want to enter elements or use random sequence?\n 1 - My sequence\n 2 - Random sequence" << endl;
				int keyr = -1;
				while ((keyr != 2) && (keyr != 1))
					cin >> keyr;
				cout << endl;
				if (keyr == 1)
					sequence->InputElements();
				else
				{
					cout << "Enter the range\n";
					int range;
					cin >> range;
					cout << endl;
					fill_random<int>(sequence, range);
					ShellSort<int>(sequence);
				}
				int element;
				cout << "Enter the type of searching:\n 1 - Binary searching in sorted sequence, 2 - Searching in binary tree" << endl;
				int key2 = -1;
				while ((key2 != 1) && (key2 != 2))
					cin >> key2;
				switch (key2)
				{
				case 1:
				{
					cout << "Binary searching." << endl;
					int action = -1;
					int q = 1;
					while (q)
					{
						cout << "Enter the next action:\n 1 - Add new element\n 2 - Get element\n 3 - Get first element\n 4 - Get last element\n 5 - Find element in sequence\n 6 - Get Subsequence\n 7 - Print sequence\n 8 - exit\n" << endl;
						action = -1;
						while ((action != 1) && (action != 2) && (action != 3) && (action != 4) && (action != 5) && (action != 6) && (action != 7) && (action != 8))
							cin >> action;
						switch (action)
						{
						case 1:
						{
							cout << "Enter the item\n";
							cin >> element;
							sequence->Add(element);
							break;
						}
						case 2:
						{
							cout << "Enter the index" << endl;
							int index;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* string)
							{
								cout << string << endl;
							}
							break;
						}
						case 3:
						{
							cout << sequence->GetFirst() << endl;
							break;
						}
						case 4:
						{
							cout << sequence->GetLast() << endl;
							break;
						}
						case 5:
						{
							cout << "Enter the list splitting options.\n 0 - Dividing the segment in half. \n 1 - The division of the segment by the golden section. \n 2 - The division of the segment in a given proportion. \n 3 - The division of the segment in the proportion given by Fibonacci numbers." << endl;
							int flag = -1;
							while ((flag != 0) && (flag != 1) && (flag != 2) && (flag != 3))
								cin >> flag;
							cout << "Enter the item you want to find." << endl;
							cin >> element;
							int find = time_function1<int>(sequence, element, flag);
							find != -1 ? cout << "Index of element: " << find << endl : cout << "Element isn't found" << endl;
							break;
						}
						case 6:
						{
							cout << "Enter the first and the second indexes" << endl;
							int first, last;
							cin >> first >> last;
							try
							{
								sequence->GetSubsequence(first, last)->Output();
								cout << endl;
							}
							catch (const char* string)
							{
								cout << string << endl;
							}
							break;
						}
						case 7:
						{
							sequence->Output();
							break;
						}
						case 8:
						{
							q = 0;
							break;
						}
						default:
						{
							break;
						}
						}
					}
					break;
				}
				case 2:
				{
					cout << "Tree searching" << endl;
					TreeBuilder<int>* builder = new TreeBuilder<int>();
					Tree<int>* tree = builder->GetTree(sequence);
					int action = -1;
					int q = 1;
					while (q)
					{
						cout << "Enter the next action:\n 1 - Add new element\n 2 - Find max element\n 3 - Find min element\n 4 - Print tree\n 5 - Find element in tree\n 6 - exit" << endl;
						action = -1;
						while ((action != 1) && (action != 2) && (action != 3) && (action != 4) && (action != 5) && (action != 6))
							cin >> action;
						switch (action)
						{
						case 1:
						{
							cout << "Enter the item\n";
							cin >> element;
							tree->InsertNode(element);
							break;
						}
						case 2:
						{
							cout << tree->GetMax() << endl;
							break;
						}
						case 3:
						{
							cout << tree->GetMin() << endl;
							break;
						}
						case 4:
						{
							tree->Output();
							cout << endl;
							break;
						}
						case 5:
						{
							cout << "Enter the item\n";
							cin >> element;
							int find = tree->SearchElement(element);
							find != -1 ? cout << "Index of element: " << find << endl : cout << "Element isn't found" << endl;
							cout << "Time of searching: " << time_function2<int>(sequence, element) << endl;
							break;
						}
						case 6:
						{
							q = 0;
							break;
						}
						default:
						{
							break;
						}
						}
					}
					break;
				}
				default:
				{
					break;
				}
				}
				break;
			}
			case 2:
			{
				SortedListSequence<int>* sequence = new SortedListSequence<int>(N);
				cout << "Do you want to enter elements or use random sequence?\n 1 - My sequence\n 2 - Random sequence" << endl;
				int keyr = -1;
				while ((keyr != 2) && (keyr != 1))
					cin >> keyr;
				cout << endl;
				if (keyr == 1)
					sequence->InputElements();
				else
				{
					cout << "Enter the range\n";
					int range;
					cin >> range;
					cout << endl;
					fill_random<int>(sequence, range);
					ShellSort<int>(sequence);
				}
				int element;
				cout << "Enter the type of searching:\n 1 - Binary searching in sorted sequence, 2 - Searching in binary tree" << endl;
				int key2 = -1;
				while ((key2 != 1) && (key2 != 2))
					cin >> key2;
				switch (key2)
				{
				case 1:
				{
					cout << "Binary searching." <<endl;
					int action = -1;
					int q = 1;
					while (q)
					{
						cout << "Enter the next action:\n 1 - Add new element\n 2 - Get element\n 3 - Get first element\n 4 - Get last element\n 5 - Find element in sequence\n 6 - Get Subsequence\n 7 - Print sequence\n 8 - exit\n" << endl;
						action = -1;
						while ((action != 1) && (action != 2) && (action != 3) && (action != 4) && (action != 5) && (action != 6) && (action != 7) && (action != 8))
							cin >> action;
						switch (action)
						{
						case 1:
						{
							cout << "Enter the item\n";
							cin >> element;
							sequence->Add(element);
							break;
						}
						case 2:
						{
							cout << "Enter the index" << endl;
							int index;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* string)
							{
								cout << string << endl;
							}
							break;
						}
						case 3:
						{
							cout << sequence->GetFirst() << endl;
							break;
						}
						case 4:
						{
							cout << sequence->GetLast() << endl;
							break;
						}
						case 5:
						{
							cout << "Enter the list splitting options.\n 0 - Dividing the segment in half. \n 1 - The division of the segment by the golden section. \n 2 - The division of the segment in a given proportion. \n 3 - The division of the segment in the proportion given by Fibonacci numbers." << endl;
							int flag = -1;
							while ((flag != 0) && (flag != 1) && (flag != 2) && (flag != 3))
								cin >> flag;
							cout << "Enter the item you want to find." << endl;
							cin >> element;
							int find = time_function1<int>(sequence, element, flag);
							find != -1 ? cout << "Index of element: " << find << endl : cout << "Element isn't found" << endl;
							break;
						}
						case 6:
						{
							cout << "Enter the first and the second indexes" << endl;
							int first, last;
							cin >> first >> last;
							try
							{
								sequence->GetSubsequence(first, last)->Output();
								cout << endl;
							}
							catch (const char* string)
							{
								cout << string << endl;
							}
							break;
						}
						case 7:
						{
							sequence->Output();
							break;
						}
						case 8:
						{
							q = 0;
							break;
						}
						default:
						{
							break;
						}
						}
					}
					break;
				}
				case 2:
				{
					cout << "Tree searching" << endl;
					TreeBuilder<int>* builder = new TreeBuilder<int>();
					Tree<int>* tree = builder->GetTree(sequence);
					int action = -1;
					int q = 1;
					while (q)
					{
						cout << "Enter the next action:\n 1 - Add new element\n 2 - Find max element\n 3 - Find min element\n 4 - Print tree\n 5 - Find element in tree\n 6 - exit" << endl;
						action = -1;
						while ((action != 1) && (action != 2) && (action != 3) && (action != 4) && (action != 5) && (action != 6))
							cin >> action;
						switch (action)
						{
						case 1:
						{
							cout << "Enter the item\n";
							cin >> element;
							tree->InsertNode(element);
							break;
						}
						case 2:
						{
							cout << tree->GetMax() << endl;
							break;
						}
						case 3:
						{
							cout << tree->GetMin() << endl;
							break;
						}
						case 4:
						{
							tree->Output();
							cout << endl;
							break;
						}
						case 5:
						{
							cout << "Enter the item\n";
							cin >> element;
							int find = tree->SearchElement(element);
							find != -1 ? cout << "Index of element: " << find << endl : cout << "Element isn't found" << endl;
							cout << "Time of searching: " << time_function2<int>(sequence, element) << endl;
							break;
						}
						case 6:
						{
							q = 0;
							break;
						}
						default:
						{
							break;
						}
						}
					}
					break;
				}
				default:
				{
					break;
				}
				}
				break;
			}
			default:
			{
				break;
			}
			}

			break;
		}
		case 2:
		{
			int N = 0;
			int key1 = -1;
			cout << "Enter the type of storage:\n 1 - array, 2 - list" << endl;
			while ((key1 != 1) && (key1 != 2))
				cin >> key1;
			switch (key1)
			{
			case 1:
			{
				SortedArraySequence<Student>* sequence = new SortedArraySequence<Student>(N);
				cout << "Enter the type of searching:\n 1 - Binary searching in sorted sequence, 2 - Searching in binary tree" << endl;
				int key2 = -1;
				while ((key2 != 1) && (key2 != 2))
					cin >> key2;
				switch (key2)
				{
				case 1:
				{
					cout << "Binary searching.\n Enter the parameters by which the elements will be compared:\n 0 - Name\n 1 - Second Name\n 2 - Patronymic\n 3 - Number of group\n 4 - Date of birth " << endl;
					int flag = -1;
					while ((flag != 0) && (flag != 1) && (flag != 2) && (flag != 3) && (flag != 4))
						cin >> flag;
					int action = -1;
					int q = 1;
					while (q)
					{
						cout << "Enter the next action:\n 1 - Add new element\n 2 - Get element\n 3 - Get first element\n 4 - Get last element\n 5 - Find element in sequence\n 6 - Get Subsequence\n 7 - Print sequence\n 8 - exit\n" << endl;
						action = -1;
						while ((action != 1) && (action != 2) && (action != 3) && (action != 4) && (action != 5) && (action != 6) && (action != 7) && (action != 8))
							cin >> action;
						switch (action)
						{
						case 1:
						{
							Student element;
							cout << "Enter the item\n";
							cin >> element;
							element.Put_Flag(flag);
							sequence->Add(element);
							break;
						}
						case 2:
						{
							cout << "Enter the index" << endl;
							int index;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* string)
							{
								cout << string << endl;
							}
							break;
						}
						case 3:
						{
							cout << sequence->GetFirst() << endl;
							break;
						}
						case 4:
						{
							cout << sequence->GetLast() << endl;
							break;
						}
						case 5:
						{
							Student element;
							cout << "Enter the list splitting options.\n 0 - Dividing the segment in half. \n 1 - The division of the segment by the golden section. \n 2 - The division of the segment in a given proportion. \n 3 - The division of the segment in the proportion given by Fibonacci numbers." << endl;
							int flag1 = -1;
							while ((flag1 != 0) && (flag1 != 1) && (flag1 != 2) && (flag1 != 3))
								cin >> flag1;
							element.Put_Flag(flag);
							if (flag == 0)
							{
								string name;
								cout << "Enter the name" << endl;
								cin >> name;
								element.Put_Name(name);
							}
							if (flag == 1)
							{
								string sename;
								cout << "Enter the sename" << endl;
								cin >> sename;
								element.Put_SeName(sename);
							}
							if (flag == 2)
							{
								string patronymic;
								cout << "Enter the patronymic" << endl;
								cin >> patronymic;
								element.Put_Patronymic(patronymic);
							}
							if (flag == 3)
							{
								string group;
								cout << "Enter the group" << endl;
								cin >> group;
								element.Put_GroupNumber(group);
							}
							if (flag == 4)
							{
								Date date;
								cout << "Enter the date of birth" << endl;
								cin >> date;
								element.Put_Date(date);
							}
							int find = time_function1<Student>(sequence, element, flag1);
							find != -1 ? cout << "Index of element: " << find << endl : cout << "Element isn't found" << endl;
							break;
						}
						case 6:
						{
							cout << "Enter the first and the second indexes" << endl;
							int first, last;
							cin >> first >> last;
							try
							{
								sequence->GetSubsequence(first, last)->Output();
								cout << endl;
							}
							catch (const char* string)
							{
								cout << string << endl;
							}
							break;
						}
						case 7:
						{
							sequence->Output();
							break;
						}
						case 8:
						{
							q = 0;
						}
						default:
						{
							break;
						}
						}
					}
					break;
				}
				case 2:
				{
					cout << "Tree searching.\n Enter the parameters by which the elements will be compared:\n 0 - Name\n 1 - Second Name\n 2 - Patronymic\n 3 - Number of group\n 4 - Date of birth " << endl;
					int flag = -1;
					while ((flag != 0) && (flag != 1) && (flag != 2) && (flag != 3) && (flag != 4))
						cin >> flag;
					TreeBuilder<Student>* builder = new TreeBuilder<Student>();
					Tree<Student>* tree = builder->GetTree(sequence);
					int action = -1;
					int q = 1;
					while (q)
					{
						cout << "Enter the next action:\n 1 - Add new element\n 2 - Find max element\n 3 - Find min element\n 4 - Print tree\n 5 - Find element in tree\n 6 - exit" << endl;
						action = -1;
						while ((action != 1) && (action != 2) && (action != 3) && (action != 4) && (action != 5) && (action != 6))
							cin >> action;
						switch (action)
						{
						case 1:
						{
							Student element;
							cout << "Enter the item\n";
							cin >> element;
							element.Put_Flag(flag);
							tree->InsertNode(element);
							break;
						}
						case 2:
						{
							cout << tree->GetMax() << endl;
							break;
						}
						case 3:
						{
							cout << tree->GetMin() << endl;
							break;
						}
						case 4:
						{
							tree->Output();
							cout << endl;
							break;
						}
						case 5:
						{
							Student element;
							element.Put_Flag(flag);
							if (flag == 0)
							{
								string name;
								cout << "Enter the name" << endl;
								cin >> name;
								element.Put_Name(name);
							}
							if (flag == 1)
							{
								string sename;
								cout << "Enter the sename" << endl;
								cin >> sename;
								element.Put_SeName(sename);
							}
							if (flag == 2)
							{
								string patronymic;
								cout << "Enter the patronymic" << endl;
								cin >> patronymic;
								element.Put_Patronymic(patronymic);
							}
							if (flag == 3)
							{
								string group;
								cout << "Enter the group" << endl;
								cin >> group;
								element.Put_GroupNumber(group);
							}
							if (flag == 4)
							{
								Date date;
								cout << "Enter the date of birth" << endl;
								cin >> date;
								element.Put_Date(date);
							}
							int find = tree->SearchElement(element);
							find != -1 ? cout << "Index of element: " << find << endl : cout << "Element isn't found" << endl;
							cout << "Time of searching: " << time_function2<Student>(sequence, element) << endl;
							break;
						}
						case 6:
						{
							q = 0;
							break;
						}
						default:
						{
							break;
						}
						}
					}
					break;
				}
				default:
				{
					break;
				}
				}
				break;
			}
			case 2:
			{
				SortedListSequence<Student>* sequence = new SortedListSequence<Student>(N);
				Student element;
				cout << "Enter the type of searching:\n 1 - Binary searching in sorted sequence, 2 - Searching in binary tree" << endl;
				int key2 = -1;
				while ((key2 != 1) && (key2 != 2))
					cin >> key2;
				switch (key2)
				{
				case 1:
				{
					cout << "Binary searching.\n Enter the parameters by which the elements will be compared:\n 0 - Name\n 1 - Second Name\n 2 - Patronymic\n 3 - Number of group\n 4 - Date of birth " << endl;
					int flag = -1;
					while ((flag != 0) && (flag != 1) && (flag != 2) && (flag != 3) && (flag != 4))
						cin >> flag;
					int action = -1;
					int q = 1;
					while (q)
					{
						cout << "Enter the next action:\n 1 - Add new element\n 2 - Get element\n 3 - Get first element\n 4 - Get last element\n 5 - Find element in sequence\n 6 - Get Subsequence\n 7 - Print sequence\n 8 - exit\n" << endl;
						action = -1;
						while ((action != 1) && (action != 2) && (action != 3) && (action != 4) && (action != 5) && (action != 6) && (action != 7) && (action != 8))
							cin >> action;
						switch (action)
						{
						case 1:
						{
							cout << "Enter the item\n";
							cin >> element;
							element.Put_Flag(flag);
							sequence->Add(element);
							break;
						}
						case 2:
						{
							cout << "Enter the index" << endl;
							int index;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* string)
							{
								cout << string << endl;
							}
							break;
						}
						case 3:
						{
							cout << sequence->GetFirst() << endl;
							break;
						}
						case 4:
						{
							cout << sequence->GetLast() << endl;
							break;
						}
						case 5:
						{
							Student element;
							cout << "Enter the list splitting options.\n 0 - Dividing the segment in half. \n 1 - The division of the segment by the golden section. \n 2 - The division of the segment in a given proportion. \n 3 - The division of the segment in the proportion given by Fibonacci numbers." << endl;
							int flag1 = -1;
							while ((flag1 != 0) && (flag1 != 1) && (flag1 != 2) && (flag1 != 3))
								cin >> flag1;
							element.Put_Flag(flag);
							if (flag == 0)
							{
								string name;
								cout << "Enter the name" << endl;
								cin >> name;
								element.Put_Name(name);
							}
							if (flag == 1)
							{
								string sename;
								cout << "Enter the sename" << endl;
								cin >> sename;
								element.Put_SeName(sename);
							}
							if (flag == 2)
							{
								string patronymic;
								cout << "Enter the patronymic" << endl;
								cin >> patronymic;
								element.Put_Patronymic(patronymic);
							}
							if (flag == 3)
							{
								string group;
								cout << "Enter the group" << endl;
								cin >> group;
								element.Put_GroupNumber(group);
							}
							if (flag == 4)
							{
								Date date;
								cout << "Enter the date of birth" << endl;
								cin >> date;
								element.Put_Date(date);
							}
							int find = time_function1<Student>(sequence, element, flag1);
							find != -1 ? cout << "Index of element: " << find << endl : cout << "Element isn't found" << endl;
							break;
						}
						case 6:
						{
							cout << "Enter the first and the second indexes" << endl;
							int first, last;
							cin >> first >> last;
							try
							{
								sequence->GetSubsequence(first, last)->Output();
								cout << endl;
							}
							catch (const char* string)
							{
								cout << string << endl;
							}
							break;
						}
						case 7:
						{
							sequence->Output();
							break;
						}
						case 8:
						{
							q = 0;
							break;
						}
						default:
						{
							break;
						}
						}
					}
					break;
				}
				case 2:
				{
					cout << "Tree searching.\n Enter the parameters by which the elements will be compared:\n 0 - Name\n 1 - Second Name\n 2 - Patronymic\n 3 - Number of group\n 4 - Date of birth " << endl;
					int flag = -1;
					while ((flag != 0) && (flag != 1) && (flag != 2) && (flag != 3) && (flag != 4))
						cin >> flag;
					TreeBuilder<Student>* builder = new TreeBuilder<Student>();
					Tree<Student>* tree = builder->GetTree(sequence);
					int action = -1;
					int q = 1;
					while (q)
					{
						cout << "Enter the next action:\n 1 - Add new element\n 2 - Find max element\n 3 - Find min element\n 4 - Print tree\n 5 - Find element in tree\n 6 - exit" << endl;
						action = -1;
						while ((action != 1) && (action != 2) && (action != 3) && (action != 4) && (action != 5) && (action != 6))
							cin >> action;
						switch (action)
						{
						case 1:
						{
							cout << "Enter the item\n";
							cin >> element;
							element.Put_Flag(flag);
							tree->InsertNode(element);
							break;
						}
						case 2:
						{
							cout << tree->GetMax() << endl;
							break;
						}
						case 3:
						{
							cout << tree->GetMin() << endl;
							break;
						}
						case 4:
						{
							tree->Output();
							cout << endl;
							break;
						}
						case 5:
						{
							Student element;
							element.Put_Flag(flag);
							if (flag == 0)
							{
								string name;
								cout << "Enter the name" << endl;
								cin >> name;
								element.Put_Name(name);
							}
							if (flag == 1)
							{
								string sename;
								cout << "Enter the sename" << endl;
								cin >> sename;
								element.Put_SeName(sename);
							}
							if (flag == 2)
							{
								string patronymic;
								cout << "Enter the patronymic" << endl;
								cin >> patronymic;
								element.Put_Patronymic(patronymic);
							}
							if (flag == 3)
							{
								string group;
								cout << "Enter the group" << endl;
								cin >> group;
								element.Put_GroupNumber(group);
							}
							if (flag == 4)
							{
								Date date;
								cout << "Enter the date of birth" << endl;
								cin >> date;
								element.Put_Date(date);
							}
							int find = tree->SearchElement(element);
							find != -1 ? cout << "Index of element: " << find << endl : cout << "Element isn't found" << endl;
							cout << "Time of searching: " << time_function2<Student>(sequence, element) << endl;
							break;
						}
						case 6:
						{
							q = 0;
							break;
						}
						default:
						{
							break;
						}
						}
					}
					break;
				}
				default:
				{
					break;
				}
				}
				break;
			}
			default:
			{
				break;
			}
			}

			break;
		}
		case 3:
		{
			q1 = 0;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
