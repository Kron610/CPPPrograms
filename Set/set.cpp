#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include "header.h"

int test_occurence(List* L, void* element, int(*comparison)(void*, void*))
{
	if (comparison(L->first->data, element))
	{
		spisok* cash = L->first;
		for (int i = 0; i < (L->N) - 1;i++)
		{
			cash = cash->next;
			if (comparison(cash->data, element) == 0) return 0;
		}
		return 1;
	}
	else return 0;
}

List* list_alloc(int N, int size_element, void(*input)(void*), int(*comparison)(void*, void*))
{
	List* L = (List*)malloc(sizeof(List));
	L->first = (spisok*)malloc(sizeof(spisok));
	L->size_element = size_element;
	L->N = 1;
	spisok* cash = L->first;
	printf("Enter first element\n");
	cash->data = malloc(size_element);
	input(cash->data);
	for (int i = 0; i < N - 1;i++)
	{
		cash->next = (spisok*)malloc(sizeof(spisok));
		cash = cash->next;
		printf("Enter %d element\n", i + 2);
		cash->data = malloc(size_element);
		input(cash->data);
		while (test_occurence(L, cash->data, comparison) == 0)
		{
			printf("Enter %d element\n", i + 2);
			input(cash->data);
		}
		L->N += 1;


	}
	cash->next = NULL;
	return L;
}

void List_free(List* L)
{
	if (L->N != 0)
	{
		spisok* cash;
		for (int i = 0; i < L->N - 2;i++)
		{
			cash = L->first;
			L->first = L->first->next;
			free(cash->data);
			free(cash);
		}
		cash = L->first;
		free(cash->data);
		free(cash->next->data);
		free(cash->next);
		free(cash);
		L->N = 0;
	}
}

int double_comparison(void* d1, void* d2)
{
	double* D1 = (double*)d1;
	double* D2 = (double*)d2;
	if ((*D1) == (*D2)) return 0;
	else return 1;
}

int int_comparison(void* i1, void* i2)
{
	int* I1 = (int*)i1;
	int* I2 = (int*)i2;
	if ((*I1) == (*I2)) return 0;
	else return 1;
}

int complex_comparison(void* c1, void* c2)
{
	complex* C1 = (complex*)c1;
	complex* C2 = (complex*)c2;
	if (((C1->re) == (C2->re)) && ((C1->im) == (C2->im))) return 0;
	else return 1;
}

void double_input(void* d)
{
	double* D = (double*)d;
	printf("Enter the number\n");
	scanf("%lf", D);
}

void complex_input(void* c)
{
	complex* C = (complex*)c;
	printf("Enter real part of the number\n");
	scanf("%lf", &(C->re));
	printf("Enter imagine part of the number\n");
	scanf("%lf", &(C->im));
}

void int_input(void* i)
{
	int* I = (int*)i;
	printf("Enter the number\n");
	scanf("%d", I);
}

void double_output(void* d)
{
	double* D = (double*)d;
	printf("%lf ", *D);
}

void int_output(void* i)
{
	int* I = (int*)i;
	printf("%d ", *I);
}

void complex_output(void* c)
{
	complex* C = (complex*)c;
	printf("%lf+%lfi ", C->re, C->im);
}

int test_subset(List* L1, List* L2, int(*comparison)(void*, void*))//€вл€етс€ ли первый список подмножеством второго?
{
	spisok* element1 = L1->first;
	if (test_occurence(L2, element1->data, comparison)) return 1;
	for (int i = 0; i < (L1->N) - 1;i++)
	{
		element1 = element1->next;
		if (test_occurence(L2, element1->data, comparison)) return 1;
	}
	return 0;
}

void add_element(List* L, void* element)
{
	spisok* newsp = (spisok*)malloc(sizeof(spisok));
	newsp->data = element;
	if (L->N == 0)
	{
		L->first = newsp;
		L->first->next = NULL;
	}
	else
		newsp->next = L->first;
	L->first = newsp;
	L->N += 1;

}

void delete_element(List* L, int k)
{
	if (L->N == 1)
	{
		free(L->first);
	}
	else {
		if (k == -1)
		{
			spisok* cash = L->first;
			L->first = L->first->next;
			free(cash);
		}
		if ((k != -1) && (k < (L->N) - 2))
		{
			spisok* cash = L->first;
			for (int i = 0; i < k;i++)
			{
				cash = cash->next;
			}
			spisok* cash1 = cash->next;
			cash->next = cash->next->next;
			free(cash1);
		}
		if (k = (L->N) - 2)
		{
			spisok* cash = L->first;
			for (int i = 0; i < k;i++)
			{
				cash = cash->next;
			}
			spisok* cash1 = cash->next;
			cash->next = NULL;
			free(cash1);
		}
	}
	L->N -= 1;
}

void mapf(List* L, void*(*map)(void*))
{
	L->first->data = map(L->first->data);
	spisok* cash = L->first;
	for (int i = 0; i < (L->N) - 1;i++)
	{
		cash = cash->next;
		cash->data = map(cash->data);
	}
}

void* map1_double(void* d)
{
	double* D = (double*)d;
	(*D) = (*D) * 2;
	d = (void*)D;
	return d;
}

void* map1_int(void* i)
{
	int* I = (int*)i;
	(*I) = (*I) * 2;
	i = (void*)I;
	return i;
}

void* map1_complex(void* c)
{
	complex* C = (complex*)c;
	C->re = (C->re) * 2;
	C->im = (C->im) * 2;
	c = (void*)C;
	return c;
}

void* map2_double(void*d)
{
	double* D = (double*)d;
	(*D) = (*D) * (*D);
	d = (void*)D;
	return d;
}

void* map2_int(void* i)
{
	int* I = (int*)i;
	(*I) = (*I) * (*I);
	i = (void*)I;
	return i;
}

void* map2_complex(void* c)
{
	complex* C = (complex*)c;
	double r = C->re;
	double i = C->im;
	C->re = r * r - i * i;
	C->im = 2 * r*i;
	c = (void*)C;
	return c;
}

void sets_addition(List* L1, List* L2, int(*comparison)(void*, void*))
{
	spisok* element = L1->first;
	if (test_occurence(L2, element->data, comparison))
		add_element(L2, element->data);
	for (int i = 0; i < (L1->N) - 1;i++)
	{
		element = element->next;
		if (test_occurence(L2, element->data, comparison))
			add_element(L2, element->data);
	}
}

int search_element(List* L, void* element, int(*comparison)(void*, void*))
{
	int k = -2;
	spisok* cash = L->first;
	if (comparison(cash->data, element) == 0)
		k = -1;
	else
		for (int i = 0; i < (L->N) - 1;i++)
		{
			cash = cash->next;
			if (comparison(cash->data, element) == 0)
			{
				k = i;
				break;
			}
		}
	return k;
}

void sets_substraction(List* L1, List* L2, int(*comparison)(void*, void*))
{
	spisok* element = L2->first;
	if (test_occurence(L1, element->data, comparison) == 0)
		delete_element(L1, search_element(L1, element->data, comparison));
	for (int i = 0; i < (L2->N) - 1;i++)
	{
		if (L1->N == 0) break;
		element = element->next;
		if (test_occurence(L1, element->data, comparison) == 0)
			delete_element(L1, search_element(L1, element->data, comparison));
	}
}

void list_output(List* L, void(*output)(void*))
{
	if ((L->N)> 0)
	{
		spisok* cash = L->first;
		output(cash->data);
		for (int i = 0;i < (L->N) - 1;i++)
		{
			cash = cash->next;
			output(cash->data);
		}
	}
	else printf("The set is empty");
	printf("\n");
}
int List_comparison(List* L1, List* L2, int(*comparison)(void*, void*))
{
	if ((test_subset(L1, L2, comparison) == 0) && (L1->N == L2->N))
		return 0;
	else
		return 1;
}

void test_function1_int()
{
	void(*output)(void*);
	int(*comparison)(void*, void*);
	output = int_output;
	comparison = int_comparison;
	int int_numbers[5];
	int_numbers[0] = 1;
	int_numbers[1] = 2;
	int_numbers[2] = 14;
	int_numbers[3] = 7;
	int_numbers[4] = 5;
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	L1->size_element = 4;
	L1->N = 0;
	L2->size_element = 4;
	L2->N = 0;
	L3->size_element = 4;
	L3->N = 0;
	add_element(L1, &int_numbers[0]);
	add_element(L1, &int_numbers[1]);
	add_element(L1, &int_numbers[2]);
	add_element(L2, &int_numbers[2]);
	add_element(L2, &int_numbers[3]);
	add_element(L2, &int_numbers[4]);
	add_element(L3, &int_numbers[0]);
	add_element(L3, &int_numbers[1]);
	add_element(L3, &int_numbers[2]);
	add_element(L3, &int_numbers[3]);
	add_element(L3, &int_numbers[4]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	sets_addition(L1, L2, comparison);
	if (List_comparison(L3, L2, comparison) == 0)
	{
		list_output(L3, output);
		printf("The first function test for integers is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L2, output);
		printf("The first function test for integers isn't passed.\n\n");
	}

	free(L1);
	free(L2);
	free(L3);
}

void test_function1_real()
{
	void(*output)(void*);
	int(*comparison)(void*, void*);
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	double real_numbers[5];
	L1->size_element = 8;
	L1->N = 0;
	L2->size_element = 8;
	L2->N = 0;
	L3->size_element = 8;
	L3->N = 0;
	real_numbers[0] = 1.5;
	real_numbers[1] = 2.6;
	real_numbers[2] = 14.1;
	real_numbers[3] = 7;
	real_numbers[4] = 5.34;
	output = double_output;
	comparison = double_comparison;
	add_element(L1, &real_numbers[0]);
	add_element(L1, &real_numbers[1]);
	add_element(L1, &real_numbers[2]);
	add_element(L2, &real_numbers[2]);
	add_element(L2, &real_numbers[3]);
	add_element(L2, &real_numbers[4]);
	add_element(L3, &real_numbers[0]);
	add_element(L3, &real_numbers[1]);
	add_element(L3, &real_numbers[2]);
	add_element(L3, &real_numbers[3]);
	add_element(L3, &real_numbers[4]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	sets_addition(L1, L2, comparison);
	if (List_comparison(L3, L2, comparison) == 0)
	{
		list_output(L3, output);
		printf("The first function test for real is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L2, output);
		printf("The first function test for real isn't passed.\n\n");
	}
	free(L1);
	free(L2);
	free(L3);

}

void test_function1_complex()
{
	void(*output)(void*);
	int(*comparison)(void*, void*);
	complex complex_numbers[5];
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	complex_numbers[0].re = 1.5;
	complex_numbers[0].im = 2.4;
	complex_numbers[1].re = 2.6;
	complex_numbers[1].im = 2.1;
	complex_numbers[2].re = 14.1;
	complex_numbers[2].im = 4.3;
	complex_numbers[3].re = 7;
	complex_numbers[3].im = 2;
	complex_numbers[4].re = 5.34;
	complex_numbers[4].im = 5.34;
	output = complex_output;
	comparison = complex_comparison;
	L1->size_element = 16;
	L1->N = 0;
	L2->size_element = 16;
	L2->N = 0;
	L3->size_element = 16;
	L3->N = 0;
	add_element(L1, &complex_numbers[0]);
	add_element(L1, &complex_numbers[1]);
	add_element(L1, &complex_numbers[2]);
	add_element(L2, &complex_numbers[2]);
	add_element(L2, &complex_numbers[3]);
	add_element(L2, &complex_numbers[4]);
	add_element(L3, &complex_numbers[0]);
	add_element(L3, &complex_numbers[1]);
	add_element(L3, &complex_numbers[2]);
	add_element(L3, &complex_numbers[3]);
	add_element(L3, &complex_numbers[4]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	sets_addition(L1, L2, comparison);
	if (List_comparison(L3, L2, comparison) == 0)
	{
		list_output(L3, output);
		printf("The first function test for complex is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L2, output);
		printf("The first function test for complex isn't passed.\n\n");
	}
	free(L1);
	free(L2);
	free(L3);
}

void test_function2_int()
{
	void(*output)(void*);
	int(*comparison)(void*, void*);
	output = int_output;
	comparison = int_comparison;
	int int_numbers[5];
	int_numbers[0] = 1;
	int_numbers[1] = 2;
	int_numbers[2] = 14;
	int_numbers[3] = 7;
	int_numbers[4] = 5;
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	L1->size_element = 4;
	L1->N = 0;
	L2->size_element = 4;
	L2->N = 0;
	L3->size_element = 4;
	L3->N = 0;
	add_element(L1, &int_numbers[0]);
	add_element(L1, &int_numbers[1]);
	add_element(L1, &int_numbers[2]);
	add_element(L2, &int_numbers[2]);
	add_element(L2, &int_numbers[3]);
	add_element(L2, &int_numbers[4]);
	add_element(L3, &int_numbers[0]);
	add_element(L3, &int_numbers[1]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	sets_substraction(L1, L2, comparison);
	if (List_comparison(L3, L1, comparison) == 0)
	{
		list_output(L3, output);
		printf("The second function test for integers is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L2, output);
		printf("The second function test for integers isn't passed.\n\n");
	}

	free(L1);
	free(L2);
	free(L3);
}

void test_function2_real()
{
	void(*output)(void*);
	int(*comparison)(void*, void*);
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	double real_numbers[5];
	L1->size_element = 8;
	L1->N = 0;
	L2->size_element = 8;
	L2->N = 0;
	L3->size_element = 8;
	L3->N = 0;
	real_numbers[0] = 1.5;
	real_numbers[1] = 2.6;
	real_numbers[2] = 14.1;
	real_numbers[3] = 7;
	real_numbers[4] = 5.34;
	output = double_output;
	comparison = double_comparison;
	add_element(L1, &real_numbers[0]);
	add_element(L1, &real_numbers[1]);
	add_element(L1, &real_numbers[2]);
	add_element(L2, &real_numbers[2]);
	add_element(L2, &real_numbers[3]);
	add_element(L2, &real_numbers[4]);
	add_element(L3, &real_numbers[0]);
	add_element(L3, &real_numbers[1]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	sets_substraction(L1, L2, comparison);
	if (List_comparison(L3, L1, comparison) == 0)
	{
		list_output(L3, output);
		printf("The second function test for real is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L2, output);
		printf("The second function test for real isn't passed.\n\n");
	}
	free(L1);
	free(L2);
	free(L3);
}

void test_function2_complex()
{
	void(*output)(void*);
	int(*comparison)(void*, void*);
	complex complex_numbers[5];
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	complex_numbers[0].re = 1.5;
	complex_numbers[0].im = 2.4;
	complex_numbers[1].re = 2.6;
	complex_numbers[1].im = 2.1;
	complex_numbers[2].re = 14.1;
	complex_numbers[2].im = 4.3;
	complex_numbers[3].re = 7;
	complex_numbers[3].im = 2;
	complex_numbers[4].re = 5.34;
	complex_numbers[4].im = 5.34;
	output = complex_output;
	comparison = complex_comparison;
	L1->size_element = 16;
	L1->N = 0;
	L2->size_element = 16;
	L2->N = 0;
	L3->size_element = 16;
	L3->N = 0;
	add_element(L1, &complex_numbers[0]);
	add_element(L1, &complex_numbers[1]);
	add_element(L1, &complex_numbers[2]);
	add_element(L2, &complex_numbers[2]);
	add_element(L2, &complex_numbers[3]);
	add_element(L2, &complex_numbers[4]);
	add_element(L3, &complex_numbers[0]);
	add_element(L3, &complex_numbers[1]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	sets_substraction(L1, L2, comparison);
	if (List_comparison(L3, L1, comparison) == 0)
	{
		list_output(L3, output);
		printf("The second function test for complex is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L2, output);
		printf("The second function test for complex isn't passed.\n\n");
	}
	free(L1);
	free(L2);
	free(L3);
}

void test_function3_int()
{
	void*(*map1)(void*);
	void*(*map2)(void*);
	void*(*map)(void*);
	void(*output)(void*);
	int(*comparison)(void*, void*);
	output = int_output;
	comparison = int_comparison;
	map1 = map1_int;
	map2 = map2_int;
	int int_numbers[15];
	int_numbers[0] = 1;
	int_numbers[1] = 2;
	int_numbers[2] = 14;
	int_numbers[3] = 7;
	int_numbers[4] = 5;
	int_numbers[5] = 2;
	int_numbers[6] = 4;
	int_numbers[7] = 28;
	int_numbers[8] = 14;
	int_numbers[9] = 10;
	int_numbers[10] = 4;
	int_numbers[11] = 16;
	int_numbers[12] = 784;
	int_numbers[13] = 196;
	int_numbers[14] = 100;
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	L1->size_element = 4;
	L1->N = 0;
	L2->size_element = 4;
	L2->N = 0;
	L3->size_element = 4;
	L3->N = 0;
	add_element(L1, &int_numbers[0]);
	add_element(L1, &int_numbers[1]);
	add_element(L1, &int_numbers[2]);
	add_element(L1, &int_numbers[3]);
	add_element(L1, &int_numbers[4]);
	add_element(L2, &int_numbers[5]);
	add_element(L2, &int_numbers[6]);
	add_element(L2, &int_numbers[7]);
	add_element(L2, &int_numbers[8]);
	add_element(L2, &int_numbers[9]);
	add_element(L3, &int_numbers[10]);
	add_element(L3, &int_numbers[11]);
	add_element(L3, &int_numbers[12]);
	add_element(L3, &int_numbers[13]);
	add_element(L3, &int_numbers[14]);
	printf("The list:\n");
	list_output(L1, output);
	map = map1;
	printf("f(x)=2*x\n");
	mapf(L1, map);
	if (List_comparison(L2, L1, comparison) == 0)
	{
		printf("The result of function:\n");
		list_output(L2, output);
		printf("The first function map test for integers is passed.\n\n");
	}
	else
	{
		list_output(L2, output);
		list_output(L1, output);
		printf("The first function map test for integers isn't passed.\n\n");
	}
	map = map2;
	printf("f(x)=x^2\n");
	mapf(L1, map);
	if (List_comparison(L3, L1, comparison) == 0)
	{
		printf("The result of function:\n");
		list_output(L3, output);
		printf("The second function map test for integers is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L1, output);
		printf("The second function map test for integers isn't passed.\n\n");
	}
	free(L1);
	free(L2);
	free(L3);
}

void test_function3_real()
{
	void*(*map1)(void*);
	void*(*map2)(void*);
	void*(*map)(void*);
	void(*output)(void*);
	int(*comparison)(void*, void*);
	output = double_output;
	comparison = double_comparison;
	map1 = map1_double;
	map2 = map2_double;
	double real_numbers[15];
	real_numbers[0] = 1.5;
	real_numbers[1] = 2.5;
	real_numbers[2] = 3.5;
	real_numbers[3] = 4.5;
	real_numbers[4] = 5.5;
	real_numbers[5] = 3;
	real_numbers[6] = 5;
	real_numbers[7] = 7;
	real_numbers[8] = 9;
	real_numbers[9] = 11;
	real_numbers[10] = 9;
	real_numbers[11] = 25;
	real_numbers[12] = 49;
	real_numbers[13] = 81;
	real_numbers[14] = 121;
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	L1->size_element = 8;
	L1->N = 0;
	L2->size_element = 8;
	L2->N = 0;
	L3->size_element = 8;
	L3->N = 0;
	add_element(L1, &real_numbers[0]);
	add_element(L1, &real_numbers[1]);
	add_element(L1, &real_numbers[2]);
	add_element(L1, &real_numbers[3]);
	add_element(L1, &real_numbers[4]);
	add_element(L2, &real_numbers[5]);
	add_element(L2, &real_numbers[6]);
	add_element(L2, &real_numbers[7]);
	add_element(L2, &real_numbers[8]);
	add_element(L2, &real_numbers[9]);
	add_element(L3, &real_numbers[10]);
	add_element(L3, &real_numbers[11]);
	add_element(L3, &real_numbers[12]);
	add_element(L3, &real_numbers[13]);
	add_element(L3, &real_numbers[14]);
	printf("The list:\n");
	list_output(L1, output);
	map = map1;
	printf("f(x)=2*x\n");
	mapf(L1, map);
	if (List_comparison(L2, L1, comparison) == 0)
	{
		printf("The result of function:\n");
		list_output(L2, output);
		printf("The first function map test for real is passed.\n\n");
	}
	else
	{
		list_output(L2, output);
		list_output(L1, output);
		printf("The first function map test for real isn't passed.\n\n");
	}
	map = map2;
	printf("f(x)=x^2\n");
	mapf(L1, map);
	if (List_comparison(L3, L1, comparison) == 0)
	{
		printf("The result of function:\n");
		list_output(L3, output);
		printf("The second function map test for real is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L1, output);
		printf("The second function map test for real isn't passed.\n\n");
	}
	free(L1);
	free(L2);
	free(L3);
}

void test_function3_complex()
{
	void*(*map1)(void*);
	void*(*map2)(void*);
	void*(*map)(void*);
	void(*output)(void*);
	int(*comparison)(void*, void*);
	output = complex_output;
	comparison = complex_comparison;
	map1 = map1_complex;
	map2 = map2_complex;
	complex complex_numbers[15];
	complex_numbers[0].re = 1.5;
	complex_numbers[0].im = 2.5;
	complex_numbers[1].re = 2.5;
	complex_numbers[1].im = 2;
	complex_numbers[2].re = 4;
	complex_numbers[2].im = 4.5;
	complex_numbers[3].re = 7;
	complex_numbers[3].im = 2;
	complex_numbers[4].re = 5;
	complex_numbers[4].im = 5;
	complex_numbers[5].re = 3;
	complex_numbers[5].im = 5;
	complex_numbers[6].re = 5;
	complex_numbers[6].im = 4;
	complex_numbers[7].re = 8;
	complex_numbers[7].im = 9;
	complex_numbers[8].re = 14;
	complex_numbers[8].im = 4;
	complex_numbers[9].re = 10;
	complex_numbers[9].im = 10;
	complex_numbers[10].re = -16;
	complex_numbers[10].im = 30;
	complex_numbers[11].re = 9;
	complex_numbers[11].im = 40;
	complex_numbers[12].re = -17;
	complex_numbers[12].im = 144;
	complex_numbers[13].re = 180;
	complex_numbers[13].im = 112;
	complex_numbers[14].re = 0;
	complex_numbers[14].im = 200;
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	List* L3 = (List*)malloc(sizeof(List));
	L1->size_element = 16;
	L1->N = 0;
	L2->size_element = 16;
	L2->N = 0;
	L3->size_element = 16;
	L3->N = 0;
	add_element(L1, &complex_numbers[0]);
	add_element(L1, &complex_numbers[1]);
	add_element(L1, &complex_numbers[2]);
	add_element(L1, &complex_numbers[3]);
	add_element(L1, &complex_numbers[4]);
	add_element(L2, &complex_numbers[5]);
	add_element(L2, &complex_numbers[6]);
	add_element(L2, &complex_numbers[7]);
	add_element(L2, &complex_numbers[8]);
	add_element(L2, &complex_numbers[9]);
	add_element(L3, &complex_numbers[10]);
	add_element(L3, &complex_numbers[11]);
	add_element(L3, &complex_numbers[12]);
	add_element(L3, &complex_numbers[13]);
	add_element(L3, &complex_numbers[14]);
	printf("The list:\n");
	list_output(L1, output);
	map = map1;
	printf("f(x)=2*x\n");
	mapf(L1, map);
	if (List_comparison(L2, L1, comparison) == 0)
	{
		printf("The result of function:\n");
		list_output(L2, output);
		printf("The first function map test for complex is passed.\n\n");
	}
	else
	{
		list_output(L2, output);
		list_output(L1, output);
		printf("The first function map test for complex isn't passed.\n\n");
	}
	map = map2;
	printf("f(x)=x^2\n");
	mapf(L1, map);
	if (List_comparison(L3, L1, comparison) == 0)
	{
		printf("The result of function:\n");
		list_output(L3, output);
		printf("The second function map test for complex is passed.\n\n");
	}
	else
	{
		list_output(L3, output);
		list_output(L1, output);
		printf("The second function map test for complex isn't passed.\n\n");
	}
	free(L1);
	free(L2);
	free(L3);
}

void test_function4_int()
{

	void(*output)(void*);
	int(*comparison)(void*, void*);
	output = int_output;
	comparison = int_comparison;
	int int_numbers[5];
	int_numbers[0] = 1;
	int_numbers[1] = 2;
	int_numbers[2] = 14;
	int_numbers[3] = 7;
	int_numbers[4] = 5;
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	L1->size_element = 4;
	L1->N = 0;
	L2->size_element = 4;
	L2->N = 0;
	add_element(L1, &int_numbers[0]);
	add_element(L1, &int_numbers[1]);
	add_element(L1, &int_numbers[2]);
	add_element(L2, &int_numbers[0]);
	add_element(L2, &int_numbers[1]);
	add_element(L2, &int_numbers[2]);
	add_element(L2, &int_numbers[3]);
	add_element(L2, &int_numbers[4]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	if (test_subset(L1, L2, comparison) == 0)
	{
		printf("The fourth function test for integers is passed.\n\n");
	}
	else
	{
		printf("The fourth function test for integers isn't passed.\n\n");
	}

	free(L1);
	free(L2);
}

void test_function4_real()
{
	void(*output)(void*);
	int(*comparison)(void*, void*);
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	double real_numbers[5];
	L1->size_element = 8;
	L1->N = 0;
	L2->size_element = 8;
	L2->N = 0;
	real_numbers[0] = 1.5;
	real_numbers[1] = 2.6;
	real_numbers[2] = 14.1;
	real_numbers[3] = 7;
	real_numbers[4] = 5.34;
	output = double_output;
	comparison = double_comparison;
	add_element(L1, &real_numbers[0]);
	add_element(L1, &real_numbers[1]);
	add_element(L1, &real_numbers[2]);
	add_element(L2, &real_numbers[0]);
	add_element(L2, &real_numbers[1]);
	add_element(L2, &real_numbers[2]);
	add_element(L2, &real_numbers[3]);
	add_element(L2, &real_numbers[4]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	if (test_subset(L1, L2, comparison) == 0)
	{
		printf("The fourth function test for real is passed.\n\n");
	}
	else
	{
		printf("The fourth function test for real isn't passed.\n\n");
	}

	free(L1);
	free(L2);
}

void test_function4_complex()
{
	void(*output)(void*);
	int(*comparison)(void*, void*);
	complex complex_numbers[5];
	List* L1 = (List*)malloc(sizeof(List));
	List* L2 = (List*)malloc(sizeof(List));
	complex_numbers[0].re = 1.5;
	complex_numbers[0].im = 2.4;
	complex_numbers[1].re = 2.6;
	complex_numbers[1].im = 2.1;
	complex_numbers[2].re = 14.1;
	complex_numbers[2].im = 4.3;
	complex_numbers[3].re = 7;
	complex_numbers[3].im = 2;
	complex_numbers[4].re = 5.34;
	complex_numbers[4].im = 5.34;
	output = complex_output;
	comparison = complex_comparison;
	L1->size_element = 16;
	L1->N = 0;
	L2->size_element = 16;
	L2->N = 0;
	add_element(L1, &complex_numbers[0]);
	add_element(L1, &complex_numbers[1]);
	add_element(L1, &complex_numbers[2]);
	add_element(L2, &complex_numbers[0]);
	add_element(L2, &complex_numbers[1]);
	add_element(L2, &complex_numbers[2]);
	add_element(L2, &complex_numbers[3]);
	add_element(L2, &complex_numbers[4]);
	printf("The first list:\n");
	list_output(L1, output);
	printf("The second list:\n");
	list_output(L2, output);
	if (test_subset(L1, L2, comparison) == 0)
	{
		printf("The fourth function test for complex is passed.\n\n");
	}
	else
	{
		printf("The fourth function test for complex isn't passed.\n\n");
	}

	free(L1);
	free(L2);
}
