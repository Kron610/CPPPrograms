﻿#include <iostream>
#include <math.h>
#include <complex>
#include "Class.h"
#include "Tests.h"
using namespace std;


int main()
{
	map_test();
	where_test();
	merge_test();
	subtree_test();
	contain_el_test();
	contain_tree_test();
	while (1) 
	{
		cout << endl << "Type of data:\n  1: Integer numbers\n  2: Complex numbers\n  3: Real numbers\n  4: Exit the program\n\nSelect the data type from the list to work with or finish the work: ";
		char mode_choise;
		do 
		{ 
			cin >> mode_choise;
		} 
		while (mode_choise != '1' && mode_choise != '2' && mode_choise != '3' && mode_choise != '4');

		switch (mode_choise) {
		case '1':
		{
			cout << "You have chosen integer numbers " << endl;
			tree<int> *mytree = new tree<int>;
			mytree->set_tree();
			mytree->output_by_levels();
			cout << "Choose the function: " << endl;
			cout << "  1: Map\n  2: Where\n  3: Merger\n  4: Extracting a subtree by a given element\n  5: Searching for the occurrence of a subtree\n  6: Finding an element for an entry\n  7: Saving to a string in accordance with the specified bypass" << endl;
			char mode;
			do 
			{ 
				cin >> mode;
			}
			while (mode != '1' && mode != '2' && mode != '3' && mode != '4' && mode != '5' && mode != '6' && mode != '7');
			switch (mode) 
			{
			case '1':
			{ // map
				cout << "Enter the number for the transformations: ";
				int for_map;
				cin >> for_map;
				mytree->map(for_map);
				mytree->output_by_levels();
				delete mytree;
				break;
			}
			case '2':
			{ // where
				tree<int> *int_tree = new tree<int>;
				mytree->where(int_tree);
				if (int_tree->getroot() == nullptr) cout << "Elements that satisfy the condition are not found" << endl;
				else 
				{
					int_tree->output_by_levels();
				}
				delete mytree;
				delete int_tree;
				break;

			}
			case '3':
			{ // слияние
				cout << "Enter the tree to merge:" << endl;
				tree<int> *second_tree = new tree<int>;
				second_tree->set_tree();
				second_tree->merge(mytree);
				cout << "The result of the merger: " << endl;
				mytree->output_by_levels();
				delete mytree;
				delete second_tree;
				break;
			}
			case '4':
			{ // извлечение поддерева
				tree<int> *res_tree = new tree<int>;
				cout << "Enter the integer number: ";
				int k;
				cin >> k;
				mytree->subtree_extraction(k, res_tree);
				if (res_tree->getroot() == nullptr) cout << "Elements that satisfy the condition are not found" << endl;
				else 
				{
					cout << "The result of extracting a subtree for a given element:" << endl;
					res_tree->output_by_levels();
				}
				delete mytree;
				break;
			}
			case '5':
			{ // поиск на вхождение поддерева
				tree<int> *subtree = new tree<int>;
				cout << "Enter the subtree:" << endl;
				subtree->set_tree();
				if (mytree->check_contain_subtree(subtree)) cout << "The subtree is contained in the tree" << endl;
				else cout << "Subtree not found in tree" << endl;
				delete mytree;
				delete subtree;
				break;
			}
			case '6':
			{ // поиск на вхождение элемента
				cout << "Enter the element: ";
				int k;
				cin >> k;
				if (mytree->check_contain_element(k)) cout << "The number is contained in the tree" << endl;
				else cout << "The number isn't contained in the tree" << endl;
				delete mytree;
				break;
			}
			case '7':
			{
				mytree->output_circumvention();
				delete mytree;
				break;
			}
			break;
			}
			break;
		}
		case '2':
		{
			cout << "You have chosen complex numbers " << endl;
			tree<complex<double>> *mytree = new tree<complex<double>>;
			mytree->set_tree_complex();
			cout << "Choose the function: " << endl;
			cout << "  1: Map\n  2: Where\n  3: Merger\n  4: Extracting a subtree by a given element\n  5: Searching for the occurrence of a subtree\n  6: Finding an element for an entry\n  7: Saving to a string in accordance with the specified bypass" << endl;
			char double_mode_choise;
			do 
			{ 
				cin >> double_mode_choise;
			}
			while (double_mode_choise != '1' && double_mode_choise != '2' && double_mode_choise != '3' && double_mode_choise != '4' && double_mode_choise != '5' && double_mode_choise != '6' && double_mode_choise != '7');
			switch (double_mode_choise)
			{
			case '1':
			{ // map
				cout << "Enter a complex number for the transformations: ";
				double real, imag;
				cout << "Real: ";
				cin >> real;
				cout << "                                              Imaginary: ";
				cin >> imag;
				complex<double> k(real, imag);
				mytree->map(k);
				mytree->output_by_levels();
				delete mytree;
				break;
			}
			case '2':
			{ // where
				tree<complex<double>> *res_tree = new tree<complex<double>>;
				mytree->where(res_tree);
				if (res_tree->getroot() == nullptr) cout << "Elements that satisfy the condition are not found" << endl;
				else {
					res_tree->output_by_levels();
				}
				delete mytree;
				delete res_tree;
				break;

			}
			case '3':
			{ // слияние
				cout << "Enter the tree to merge:" << endl;
				tree<complex<double>> *second_tree = new tree<complex<double>>;
				second_tree->set_tree_complex();
				second_tree->merge(mytree);
				cout << "Result:" << endl;
				mytree->output_by_levels();
				delete mytree;
				delete second_tree;
				break;
			}
			case '4':
			{ // извлечение поддерева
				tree<complex<double>> *res_tree = new tree<complex<double>>;
				cout << "Enter the complex number: ";
				double real, imag;
				cout << "Real: ";
				cin >> real;
				cout << "                           Imaginary: ";
				cin >> imag;
				complex<double> k(real, imag);
				mytree->subtree_extraction(k, res_tree);
				if (res_tree->getroot() == nullptr) cout << "Elements that satisfy the condition are not found" << endl;
				else {
					cout << "The result of extracting a subtree for a given element: " << endl;
					res_tree->output_by_levels();
				}
				delete mytree;
				break;
			}
			case '5':
			{ // поиск на вхождение поддерева
				tree<complex<double>> *subtree = new tree<complex<double>>;
				cout << "Enter the subtree: " << endl;
				subtree->set_tree_complex();
				if (mytree->check_contain_subtree(subtree)) cout << "The subtree is contained in the tree" << endl;
				else cout << "The subtree isn't contained in the tree" << endl;
				delete mytree;
				delete subtree;
				break;
			}
			case '6':
			{ // поиск на вхождение элемента
				cout << "Enter the complex number: ";
				double real, imag;
				cout << "Real: ";
				cin >> real;
				cout << "                           Imaginary: ";
				cin >> imag;
				complex<double> k(real, imag);
				if (mytree->check_contain_element(k)) cout << "The number is in the tree" << endl;
				else cout << "The number isn't in the tree" << endl;
				delete mytree;
				break;
			}
			case '7':
			{
				mytree->output_circumvention();
				delete mytree;
				break;
			}
			break;
			}
			break;
		}
		case '3':
		{
			cout << "You have chosen real numbers " << endl;
			tree<double> *mytree = new tree<double>;
			mytree->set_tree();
			mytree->output_by_levels();
			cout << "Choose the function: " << endl;
			cout << "  1: Map\n  2: Where\n  3: Merger\n  4: Extracting a subtree by a given element\n  5: Searching for the occurrence of a subtree\n  6: Finding an element for an entry\n  7: Saving to a string in accordance with the specified bypass" << endl;
			char mode;
			do 
			{ 
				cin >> mode; 
			}
			while (mode != '1' && mode != '2' && mode != '3' && mode != '4' && mode != '5' && mode != '6' && mode != '7');
			switch (mode) 
			{
			case '1':
			{ // map
				cout << "Enter the number for the transformations: ";
				double for_map;
				cin >> for_map;
				mytree->map(for_map);
				mytree->output_by_levels();
				delete mytree;
				break;
			}
			case '2':
			{ // where
				tree<double> *real_tree = new tree<double>;
				mytree->where(real_tree);
				if (real_tree->getroot() == nullptr) cout << "Elements that satisfy the condition are not found" << endl;
				else
				{
					real_tree->output_by_levels();
				}
				delete mytree;
				delete real_tree;
				break;

			}
			case '3':
			{ // слияние
				cout << "Enter the tree to merge:" << endl;
				tree<double> *second_tree = new tree<double>;
				second_tree->set_tree();
				second_tree->merge(mytree);
				cout << "The result of the merger: " << endl;
				mytree->output_by_levels();
				delete mytree;
				delete second_tree;
				break;
			}
			case '4':
			{ // извлечение поддерева
				tree<double> *res_tree = new tree<double>;
				cout << "Enter an real number: ";
				double k;
				cin >> k;
				mytree->subtree_extraction(k, res_tree);
				if (res_tree->getroot() == nullptr) cout << "Elements that satisfy the condition are not found" << endl;
				else
				{
					cout << "The result of extracting a subtree for a given element:" << endl;
					res_tree->output_by_levels();
				}
				delete mytree;
				break;
			}
			case '5':
			{ // поиск на вхождение поддерева
				tree<double> *subtree = new tree<double>;
				cout << "Enter the subtree:" << endl;
				subtree->set_tree();
				if (mytree->check_contain_subtree(subtree)) cout << "The subtree is contained in the tree" << endl;
				else cout << "The subtree isn't contained in the tree" << endl;
				delete mytree;
				delete subtree;
				break;
			}
			case '6':
			{ // поиск на вхождение элемента
				cout << "Enter the element: ";
				double k;
				cin >> k;
				if (mytree->check_contain_element(k)) cout << "The number is in the tree" << endl;
				else cout << "The number isn't in the tree" << endl;
				delete mytree;
				break;
			}
			case '7':
			{
				mytree->output_circumvention();
				delete mytree;
				break;
			}
			break;
			}
			break;
		}
		case '4':
		{
			return 1;
		}
		}
	}
}
