#include "Header.h" 

Matrix* matrix_alloc(int N, int size_element)
{
	Matrix* m = (Matrix*)malloc(sizeof(Matrix));
	m->size_element = size_element;
	m->N = N;
	m->data = (void*)malloc(N*N*size_element);
	return m;
}

void matrix_set(Matrix * m, int i, int j, void * element)
{
	int byte_index = (i * m->N + j) * m->size_element;
	char * cptr_destination = (char*)m->data;
	cptr_destination = &cptr_destination[byte_index];
	char * cptr_source = (char*)element;
	for (int k = 0; k < m->size_element; k++)
	{
		cptr_destination[k] = cptr_source[k];
	}
}

void* matrix_get(Matrix * m, int i, int j, void * element)
{
	int byte_index = (i * m->N + j) * m->size_element;
	char * cptr_source = (char*)m->data;
	cptr_source = &cptr_source[byte_index];
	char * cptr_destination = (char*)element;
	for (int k = 0; k < m->size_element; k++) {
		cptr_destination[k] = cptr_source[k];
	}
	return element;
}



void* Complex_sum(void* c1, void* c2, void* result_sum)
{
	Complex* C1 = (Complex*)c1;
	Complex* C2 = (Complex*)c2;
	Complex* Result_sum = (Complex*)result_sum;
	Result_sum->re = C1->re + C2->re;
	Result_sum->im = C1->im + C2->im;
	result_sum = (void*)Result_sum;
	return result_sum;
}

void* Complex_multiply(void* c1, void* c2, void* result_multiply)
{
	Complex* C1 = (Complex*)c1;
	Complex* C2 = (Complex*)c2;
	Complex* Result_multiply = (Complex*)result_multiply;
	Result_multiply->re = C1->re*C2->re - C1->im*C2->im;
	Result_multiply->im = C1->re*C2->im + C1->im*C2->re;
	result_multiply = (void*)Result_multiply;
	return result_multiply;
}

void* Complex_increase(void* complex, double k)
{
	Complex* Compl;
	Compl = (Complex*)complex;
	Compl->re = k * Compl->re;
	Compl->im = k * Compl->im;
	complex = (void*)Compl;
	return complex;
}

void* double_multiply(void* d1, void* d2, void* result_multiply)
{
	double* D1 = (double*)d1;
	double* D2 = (double*)d2;
	double* Result_multiply = (double*)result_multiply;
	*Result_multiply = (*D1)*(*D2);
	result_multiply = (void*)Result_multiply;
	return result_multiply;
}

void* double_sum(void* d1, void* d2, void* result_sum)
{
	double* D1 = (double*)d1;
	double* D2 = (double*)d2;
	double* Result_sum = (double*)result_sum;
	*Result_sum = (*D1) + (*D2);
	result_sum = (void*)Result_sum;
	return result_sum;
}

void* double_increase(void* doub, double k)
{
	double* Doub = (double*)doub;
	*Doub = *Doub*k;
	doub = (void*)Doub;
	return doub;
}

void* set_d_null(void* doub)
{
	double* Doub = (double*)doub;
	*Doub = 0;
	doub = (void*)Doub;
	return doub;
}

void* set_c_null(void* complex)
{
	Complex* Compl = (Complex*)complex;
	Compl->re = 0;
	Compl->im = 0;
	complex = (void*)Compl;
	return complex;
}

Matrix* matrix_sum(Matrix* m1, Matrix* m2, void* (*sum)(void*, void*, void*))
{
	Matrix* result_m = matrix_alloc(m1->N, m1->size_element);
	for (int i = 0; i < m1->N; i++)
	{
		for (int j = 0; j < m1->N; j++)
		{
			void* el1 = (void*)malloc(m1->size_element);
			void* el2 = (void*)malloc(m1->size_element);
			void* el_r = (void*)malloc(m1->size_element);
			matrix_set(result_m, i, j, sum(matrix_get(m1, i, j, el1), matrix_get(m2, i, j, el2), el_r));
			free(el1);
			free(el2);
			free(el_r);
		}
	}
	return result_m;
}

Matrix* matrix_multiply(Matrix* m1, Matrix* m2, void* (*multiply)(void*, void*, void*), void* (*set_null)(void*), void* (*sum)(void*, void*, void*))
{
	Matrix* result_m = matrix_alloc(m1->N, m1->size_element);
	void* el_result = malloc(m1->size_element);
	for (int i = 0; i < m1->N; i++)
	{
		for (int j = 0; j < m1->N; j++)
		{
			set_null(el_result);
			for (int k = 0; k < m1->N; k++)
			{
				void* el1 = malloc(m1->size_element);
				void* el2 = malloc(m1->size_element);
				void* el_middle = malloc(m1->size_element);
				sum(el_result, multiply(matrix_get(m1, i, k, el1), matrix_get(m2, k, j, el2), el_middle), el_result);
				free(el1);
				free(el2);
				free(el_middle);
			}
			matrix_set(result_m, i, j, el_result);
		}
	}
	free(el_result);
	return result_m;
}

Matrix* matrix_increase(Matrix* m, void* (*increase)(void*, double), double k)
{
	void* el_middle = (void*)malloc(m->size_element);
	for (int i = 0; i < m->N; i++)
	{
		for (int j = 0; j < m->N; j++)
		{
			matrix_set(m, i, j, increase(matrix_get(m, i, j, el_middle), k));
		}
	}
	free(el_middle);
	return m;
}

void matrix_input(Matrix* m, void(*enter)(void*))
{
	void* x = (void*)malloc(m->size_element);
	for (int i = 0; i < m->N; i++)
	{
		for (int j = 0; j < m->N; j++)
		{
			enter(x);
			matrix_set(m, i, j, x);
		}
	}
	free(x);
}

void enter_double(void* doub)
{
	double* Doub = (double*)doub;
	printf("Enter the real number\n");
	scanf("%lf", Doub);
	doub = (void*)Doub;
}

void enter_complex(void* complex)
{
	Complex* Compl = (Complex*)complex;
	printf("Enter the real part of the number\n");
	scanf("%lf", &(Compl->re));
	printf("Enter the imagine part of the number\n");
	scanf("%lf", &(Compl->im));
	complex = (void*)Compl;
}

void matrix_output(Matrix* m, void(*output)(void*))
{
	void* elem = malloc(m->size_element);
	for (int i = 0; i < m->N; i++)
	{
		for (int j = 0; j < m->N; j++)
		{
			output(matrix_get(m, i, j, elem));
			printf("\t");
		}
		printf("\n");
	}
	free(elem);
}

void double_output(void* doub)
{
	double* Doub = (double*)doub;
	printf("%lf", *Doub);
}

void complex_output(void* complex)
{
	Complex* Compl = (Complex*)complex;
	if (((Compl->im)>0)&((Compl->re) != 0))
		printf("%lf+%lfi", Compl->re, Compl->im);
	if (((Compl->im)<0)&((Compl->re) != 0))
		printf("%lf%lfi", Compl->re, Compl->im);
	if ((Compl->im) == 0)
		printf("%lf", Compl->re);
	if (((Compl->re) == 0)&((Compl->im) != 0))
		printf("%lfi", Compl->im);
	if (((Compl->re) == 0)&((Compl->im) == 0))
		printf("%lf", Compl->re);
}

void matrix_free(Matrix* m)
{
	free(m->data);
	free(m);
}

int double_comparison(void* d1, void* d2)
{
	double* D1 = (double*)d1;
	double* D2 = (double*)d2;
	if ((*D1) == (*D2))
		return 0;
	else return 1;
}

int Complex_comparison(void* c1, void* c2)
{
	Complex* C1 = (Complex*)c1;
	Complex* C2 = (Complex*)c2;
	if ((C1->re == C2->re) & (C1->im == C2->im))
		return 0;
	else return 1;
}

int matrix_comparison(Matrix* m1, Matrix* m2, int(*comparison)(void*, void*))
{
	int key = 0;
	void* el1 = malloc(m1->size_element);
	void* el2 = malloc(m1->size_element);
	for (int k = 0; k < m1->N; k++)
	{
		if (comparison(matrix_get(m1, (int)k / (m1->N), k % (m1->N), el1), matrix_get(m2, (int)k / (m1->N), k % (m1->N), el2)))
		{
			key = 1;
			break;
		}
	}
	free(el1);
	free(el2);
	if (key)
	{
		printf("Matrixes don't coinside");
		return 1;
	}
	else
	{
		printf("Matrixes coinside\n");
		return 0;
	}
}

void test_matrix()
{
	double k = 2;
	double M[8];
	M[0] = 1.5;
	M[1] = 2;
	M[2] = 2;
	M[3] = 2.5;
	M[4] = 1;
	M[5] = 3;
	M[6] = 2;
	M[7] = 1.5;
	double R[12];
	R[0] = 2.5;
	R[1] = 5;
	R[2] = 4;
	R[3] = 4;
	R[4] = 5.5;
	R[5] = 7.5;
	R[6] = 7;
	R[7] = 9.75;
	R[8] = 3;
	R[9] = 4;
	R[10] = 4;
	R[11] = 5;
	int size_element = 8;
	Matrix* m1 = matrix_alloc(2, size_element);
	Matrix* m2 = matrix_alloc(2, size_element);
	Matrix* mr = matrix_alloc(2, size_element);
	void(*enter)(void*);
	void* (*increase)(void*, double);
	void* (*sum)(void*, void*, void*);
	void* (*multiply)(void*, void*, void*);
	void* (*set_null)(void*);
	void(*output)(void*);
	int(*comparison)(void*, void*);
	size_element = 8;
	increase = double_increase;
	sum = double_sum;
	multiply = double_multiply;
	set_null = set_d_null;
	comparison = double_comparison;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matrix_set(m1, i, j, (void*)&M[2 * i + j]);
			matrix_set(m2, i, j, (void*)&M[4 + 2 * i + j]);
			matrix_set(mr, i, j, (void*)&R[2 * i + j]);
		}
	}
	if (matrix_comparison(matrix_sum(m1, m2, sum), mr, comparison))
		printf("The first test isn't completed\n");
	else printf("The first test is completed\n");
	for (int i = 0; i < 2;
		i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matrix_set(mr, i, j, (void*)&R[4 + 2 * i + j]);
		}
	}
	if (matrix_comparison(matrix_multiply(m1, m2, multiply, set_null, sum), mr, comparison))
		printf("The second test isn't completed\n");
	else printf("The second test is completed\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matrix_set(mr, i, j, (void*)&R[8 + 2 * i + j]);
		}
	}
	if (matrix_comparison(matrix_increase(m1, increase, k), mr, comparison))
		printf("The third test isn't completed");
	else printf("The third test is completed\n");
}