#pragma once 
#include <malloc.h> 
#include <stdio.h> 
typedef struct
{
	void* data;
	int size_element;
	int N;
}
Matrix;

typedef struct
{
	double re, im;
}
Complex;
Matrix* matrix_alloc(int N, int size_element);
void matrix_set(Matrix *m, int i, int j, void *element);
void* matrix_get(Matrix * m, int i, int j, void * element);
void* Complex_sum(void* c1, void* c2, void* result_sum);
void* Complex_multiply(void* c1, void* c2, void* result_multiply);
void* Complex_increase(void* complex, double k);
void* double_multiply(void* d1, void* d2, void* result_multiply);
void* double_sum(void* d1, void* d2, void* result_sum);
void* double_increase(void* doub, double k);
void* set_d_null(void* doub);
void* set_c_null(void* complex);
void enter_double(void* doub);
void enter_complex(void* complex);
void double_output(void* doub);
void complex_output(void* complex);
int double_comparison(void* d1, void* d2);
int Complex_comparison(void* c1, void* c2);
Matrix* matrix_sum(Matrix* m1, Matrix* m2, void* (*sum)(void*, void*, void*));
Matrix* matrix_multiply(Matrix* m1, Matrix* m2, void* (*multiply)(void*, void*, void*), void* (*set_null)(void*), void* (*sum)(void*, void*, void*));
Matrix* matrix_increase(Matrix* m, void* (*increase)(void*, double), double k);
void matrix_input(Matrix* m, void(*enter)(void*));
void matrix_output(Matrix* m, void(*output)(void*));
void matrix_free(Matrix* m);
int matrix_comparison(Matrix* m1, Matrix* m2, int(*comparison)(void*, void*));
void test_matrix();
