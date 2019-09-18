﻿
#include "Header.h"
#include "Sequence_array.h"
#include "Sequence_list.h"
#include "Test_sequence.h"
#include <iostream>
#include <complex>
using namespace std;
int main()
{
	if (test_sequence())
		cout << "test is passed" << endl;
	else
		cout << "test isn't passed" << endl;
	while (1)
		{
			cout << endl << "Type of data:\n  1: Integer numbers\n  2: Real numbers\n  3: Complex numbers\n  4: Exit the program\n\nSelect the data type from the list to work with or finish the work: ";
			char mode_choise;
			do
			{
				cin >> mode_choise;
			} while (mode_choise != '1' && mode_choise != '2' && mode_choise != '3' && mode_choise != '4');

			switch (mode_choise) {
			case '1':
			{
				cout << "You have chosen integer numbers. Enter the initial number of items.\n " << endl;
				int N = -1;
				while (N < 0)
					cin >> N;
				cout << "Type of storage of data:\n 1: Array\n 2: List\n";
				char mode_choise1;
				do
				{
					cin >> mode_choise1;
				} while (mode_choise1 != '1' && mode_choise1 != '2');
				if (mode_choise1 == '1')
				{
					Array_Sequence<int> *sequence = new Array_Sequence<int>(N);
					sequence->InputElements();
					int q = 1;
					while (q)
					{
						cout << "Choose the action:\n 1: Append\n 2: Prepend\n 3: Get\n 4: GetFirst\n 5: GetLast\n 6: GetSubsequence\n 7: InsertArt\n 8: Remove \n 9: Output\n 0: Stop \n";
						char action;
						do
						{
							cin >> action;
						} while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
						switch (action)
						{
						case '1':
						{
							int item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Append(item);
							break;
						}
						case '2':
						{
							int item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Prepend(item);
							break;
						}
						case '3':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '4':
						{
							try
							{
								cout << sequence->GetFirst() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '5':
						{
							try 
							{
								cout << sequence->GetLast() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '6':
						{
							cout << "Enter first and last indexes" << endl;
							int startIndex, endIndex;
							cin >> startIndex >> endIndex;
							try
							{
								sequence->GetSubsequence(startIndex, endIndex)->Output();
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '7':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							int item;
							cout << "Enter the item" << endl;
							cin >> item;
							try
							{
								sequence->InsertArt(index, item);
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '8':
						{
							int item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Remove(item);
							break;
						}
						case '9':
						{
							sequence->Output();
							break;
						}
						case '0':
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
				}
				else
				{
					List_Sequence<int> *sequence = new List_Sequence<int>(N);
					sequence->InputElements();
					int q = 1;
					while (q)
					{
						cout << "Choose the action:\n 1: Append\n 2: Prepend\n 3: Get\n 4: GetFirst\n 5: GetLast\n 6: GetSubsequence\n 7: InsertArt\n 8: Remove \n 9: Output\n 0: Stop \n";
						char action;
						do
						{
							cin >> action;
						} while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
						switch (action)
						{
						case '1':
						{
							int item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Append(item);
							break;
						}
						case '2':
						{
							int item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Prepend(item);
							break;
						}
						case '3':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '4':
						{
							try
							{
								cout << sequence->GetFirst() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '5':
						{
							try
							{
								cout << sequence->GetLast() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '6':
						{
							cout << "Enter first and last indexes" << endl;
							int startIndex, endIndex;
							cin >> startIndex >> endIndex;
							try
							{
								sequence->GetSubsequence(startIndex, endIndex)->Output();
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '7':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							int item;
							cout << "Enter the item" << endl;
							cin >> item;
							try
							{
								sequence->InsertArt(index, item);
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '8':
						{
							int item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Remove(item);
							break;
						}
						case '9':
						{
							sequence->Output();
							break;
						}
						case '0':
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
				}
				break;
			}
			case '2':
			{
				cout << "You have chosen real numbers. Enter the initial number of items.\n " << endl;
				int N = -1;
				while (N < 0)
					cin >> N;
				cout << "Type of storage of data:\n 1: Array\n 2: List\n";
				char mode_choise1;
				do
				{
					cin >> mode_choise1;
				} while (mode_choise1 != '1' && mode_choise1 != '2');
				if (mode_choise1 == '1')
				{
					Array_Sequence<float> *sequence = new Array_Sequence<float>(N);
					sequence->InputElements();
					int q = 1;
					while (q)
					{
						cout << "Choose the action:\n 1: Append\n 2: Prepend\n 3: Get\n 4: GetFirst\n 5: GetLast\n 6: GetSubsequence\n 7: InsertArt\n 8: Remove \n 9: Output\n 0: Stop \n";
						char action;
						do
						{
							cin >> action;
						} while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
						switch (action)
						{
						case '1':
						{
							float item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Append(item);
							break;
						}
						case '2':
						{
							float item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Prepend(item);
							break;
						}
						case '3':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '4':
						{
							try
							{
								cout << sequence->GetFirst() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '5':
						{
							try
							{
								cout << sequence->GetLast() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '6':
						{
							cout << "Enter first and last indexes" << endl;
							int startIndex, endIndex;
							cin >> startIndex >> endIndex;
							try
							{
								sequence->GetSubsequence(startIndex, endIndex)->Output();
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '7':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							float item;
							cout << "Enter the item" << endl;
							cin >> item;
							try
							{
								sequence->InsertArt(index, item);
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '8':
						{
							float item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Remove(item);
							break;
						}
						case '9':
						{
							sequence->Output();
							break;
						}
						case '0':
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
				}
				else
				{
					List_Sequence<float> *sequence = new List_Sequence<float>(N);
					sequence->InputElements();
					int q = 1;
					while (q)
					{
						cout << "Choose the action:\n 1: Append\n 2: Prepend\n 3: Get\n 4: GetFirst\n 5: GetLast\n 6: GetSubsequence\n 7: InsertArt\n 8: Remove \n 9: Output\n 0: Stop \n";
						char action;
						do
						{
							cin >> action;
						} while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
						switch (action)
						{
						case '1':
						{
							float item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Append(item);
							break;
						}
						case '2':
						{
							float item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Prepend(item);
							break;
						}
						case '3':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '4':
						{
							try
							{
								cout << sequence->GetFirst() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '5':
						{
							try
							{
								cout << sequence->GetLast() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '6':
						{
							cout << "Enter first and last indexes" << endl;
							int startIndex, endIndex;
							cin >> startIndex >> endIndex;
							try
							{
								sequence->GetSubsequence(startIndex, endIndex)->Output();
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '7':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							float item;
							cout << "Enter the item" << endl;
							cin >> item;
							try
							{
								sequence->InsertArt(index, item);
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '8':
						{
							float item;
							cout << "Enter the item" << endl;
							cin >> item;
							sequence->Remove(item);
							break;
						}
						case '9':
						{
							sequence->Output();
							break;
						}
						case '0':
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
				}
				break;
			}
			case '3':
			{
				cout << "You have chosen complex numbers.\n " << endl;
				int N = 0;
				cout << "Type of storage of data:\n 1: Array\n 2: List\n";
				char mode_choise1;
				do
				{
					cin >> mode_choise1;
				} while (mode_choise1 != '1' && mode_choise1 != '2');
				if (mode_choise1 == '1')
				{
					Array_Sequence<complex<double>> *sequence = new Array_Sequence<complex<double>>(N);
					sequence->InputElements();
					int q = 1;
					while (q)
					{
						cout << "Choose the action:\n 1: Append\n 2: Prepend\n 3: Get\n 4: GetFirst\n 5: GetLast\n 6: GetSubsequence\n 7: InsertArt\n 8: Remove \n 9: Output\n 0: Stop \n";
						char action;
						do
						{
							cin >> action;
						} while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
						switch (action)
						{
						case '1':
						{
							double real, imag;
							cout << "Real: ";
							cin >> real;
							cout << "                           Imaginary: ";
							cin >> imag;
							complex<double> item(real, imag);
							sequence->Append(item);
							break;
						}
						case '2':
						{
							double real, imag;
							cout << "Real: ";
							cin >> real;
							cout << "                           Imaginary: ";
							cin >> imag;
							complex<double> item(real, imag);
							sequence->Prepend(item);
							break;
						}
						case '3':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '4':
						{
							try
							{
								cout << sequence->GetFirst() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '5':
						{
							try
							{
								cout << sequence->GetLast() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '6':
						{
							cout << "Enter first and last indexes" << endl;
							int startIndex, endIndex;
							cin >> startIndex >> endIndex;
							try
							{
								sequence->GetSubsequence(startIndex, endIndex)->Output();
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '7':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							double real, imag;
							cout << "Real: ";
							cin >> real;
							cout << "                           Imaginary: ";
							cin >> imag;
							complex<double> item(real, imag);
							try
							{
								sequence->InsertArt(index, item);
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '8':
						{
							double real, imag;
							cout << "Real: ";
							cin >> real;
							cout << "                           Imaginary: ";
							cin >> imag;
							complex<double> item(real, imag);
							sequence->Remove(item);
							break;
						}
						case '9':
						{
							sequence->Output();
							break;
						}
						case '0':
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
				}
				else
				{
					List_Sequence<complex<double>> *sequence = new List_Sequence<complex<double>>(N);
					sequence->InputElements();
					int q = 1;
					while (q)
					{
						cout << "Choose the action:\n 1: Append\n 2: Prepend\n 3: Get\n 4: GetFirst\n 5: GetLast\n 6: GetSubsequence\n 7: InsertArt\n 8: Remove \n 9: Output\n 0: Stop \n";
						char action;
						do
						{
							cin >> action;
						} while (action != '1' && action != '2' && action != '3' && action != '4' && action != '5' && action != '6' && action != '7' && action != '8' && action != '9' && action != '0');
						switch (action)
						{
						case '1':
						{
							double real, imag;
							cout << "Real: ";
							cin >> real;
							cout << "                           Imaginary: ";
							cin >> imag;
							complex<double> item(real, imag);
							sequence->Append(item);
							break;
						}
						case '2':
						{
							double real, imag;
							cout << "Real: ";
							cin >> real;
							cout << "                           Imaginary: ";
							cin >> imag;
							complex<double> item(real, imag);
							sequence->Prepend(item);
							break;
						}
						case '3':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							try
							{
								cout << sequence->Get(index) << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '4':
						{
							try
							{
								cout << sequence->GetFirst() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '5':
						{
							try
							{
								cout << sequence->GetLast() << endl;
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '6':
						{
							cout << "Enter first and last indexes" << endl;
							int startIndex, endIndex;
							cin >> startIndex >> endIndex;
							try
							{
								sequence->GetSubsequence(startIndex, endIndex)->Output();
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '7':
						{
							int index;
							cout << "Enter the index" << endl;
							cin >> index;
							double real, imag;
							cout << "Real: ";
							cin >> real;
							cout << "                           Imaginary: ";
							cin >> imag;
							complex<double> item(real, imag);
							try
							{
								sequence->InsertArt(index, item);
							}
							catch (const char* str)
							{
								cout << str << endl;
							}
							break;
						}
						case '8':
						{
							double real, imag;
							cout << "Real: ";
							cin >> real;
							cout << "                           Imaginary: ";
							cin >> imag;
							complex<double> item(real, imag);
							sequence->Remove(item);
							break;
						}
						case '9':
						{
							sequence->Output();
							break;
						}
						case '0':
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
				}
				break;
			}
			case '4':
			{
				return 1;
			}
			default:
			{
				break;
			}
			}
		}

		return 0;
}

