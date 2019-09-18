
#include "Header.h" 

int main()
{
	printf("Do you want to test the program?\n1-yes, 0-no\n");
	int q;
	scanf("%d", &q);
	if (q)
		test_matrix();
	printf("Enter the type of the data:\n 1 - real number \n 2 - complex number \n");
	int type;
	scanf("%d", &type);
	int size_element;
	void(*enter)(void*);
	void* (*increase)(void*, double);
	void* (*sum)(void*, void*, void*);
	void* (*multiply)(void*, void*, void*);
	void* (*set_null)(void*);
	void(*output)(void*);
	if (type == 1)
	{
		size_element = 8;
		enter = enter_double;
		increase = double_increase;
		sum = double_sum;
		multiply = double_multiply;
		set_null = set_d_null;
		output = double_output;
	}
	else
	{
		size_element = 16;
		enter = enter_complex;
		increase = Complex_increase;
		sum = Complex_sum;
		multiply = Complex_multiply;
		set_null = set_c_null;
		output = complex_output;
	}

	printf("Enter a program action.\n 1: Multiplication of Matrixes \n 2: Addition of Matrixes \n 3: Multiplication of Matrix and real number \n");
	int key;
	scanf("%i", &key);
	switch (key)
	{
	case 1:
	{
		printf("Enter a dimention of matrixes\n");
		int N;
		scanf("%d", &N);
		printf("Enter a first matrix\n");
		Matrix* m1 = matrix_alloc(N, size_element);
		matrix_input(m1, enter);
		printf("Enter a second matrix\n");
		Matrix* m2 = matrix_alloc(N, size_element);
		matrix_input(m2, enter);
		matrix_output(matrix_multiply(m1, m2, multiply, set_null, sum), output);
		matrix_free(m1);
		matrix_free(m2);
		break;
	}
	case 2:
	{
		printf("Enter a dimention of matrixes\n");
		int N;
		scanf("%d", &N);
		printf("Enter a first matrix\n");
		Matrix* m1 = matrix_alloc(N, size_element);
		matrix_input(m1, enter);
		printf("Enter a second matrix\n");
		Matrix* m2 = matrix_alloc(N, size_element);
		matrix_input(m2, enter);
		matrix_output(matrix_sum(m1, m2, sum), output);
		matrix_free(m1);
		matrix_free(m2);
		break;
	}
	case 3:
	{
		printf("Enter a dimention of matrix\n");
		int N;
		scanf("%d", &N);
		printf("Enter a matrix\n");
		Matrix* m = matrix_alloc(N, size_element);
		matrix_input(m, enter);
		printf("Enter a real number\n");
		double u;
		scanf("%lf", &u);
		matrix_output(matrix_increase(m, increase, u), output);
		matrix_free(m);
		break;
	}
	default:
	{
		break;
	}
	}
	return 0;
}
