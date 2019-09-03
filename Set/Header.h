#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
typedef struct complex
{
	double re, im;
}; complex;

typedef struct spisok
{
	void* data;
	spisok* next;
}; spisok;



typedef struct List
{
	int size_element;
	int N;
	spisok* first;
}; List;

int test_occurence(List* L, void* element, int(*comparison)(void*, void*));
List* list_alloc(int N, int size_element, void(*input)(void*), int(*comparison)(void*, void*));
void List_free(List* L);
int double_comparison(void* d1, void* d2);
int int_comparison(void* i1, void* i2);
int complex_comparison(void* c1, void* c2);
void double_input(void* d);
void complex_input(void* c);
void int_input(void* i);
void double_output(void* d);
void int_output(void* i);
void complex_output(void* c);
void list_input(List* L, void(*input)(void*));
int test_subset(List* L1, List* L2, int(*comparison)(void*, void*));
void add_element(List* L, void* element);
void delete_element(List* L, int k);
void mapf(List* L, void*(*map)(void*));
void* map1_double(void* d);
void* map1_int(void* i);
void* map1_complex(void* c);
void* map2_double(void*d);
void* map2_int(void* i);
void* map2_complex(void* c);
void sets_addition(List* L1, List* L2, int(*comparison)(void*, void*));
int search_element(List* L, void* element, int(*comparison)(void*, void*));
void sets_substraction(List* L1, List* L2, int(*comparison)(void*, void*));
void list_output(List* L, void(*output)(void*));
int List_comparison(List* L1, List* L2, int(*comparison)(void*, void*));
void test_function1_int();
void test_function1_real();
void test_function1_complex();
void test_function2_int();
void test_function2_real();
void test_function2_complex();
void test_function3_int();
void test_function3_real();
void test_function3_complex();
void test_function4_int();
void test_function4_real();
void test_function4_complex();