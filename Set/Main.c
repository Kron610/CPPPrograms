
#include <stdio.h>
#include <malloc.h>
#include "header.h"







	int main()
	{
		printf("Do you want to test the program? 1 - yes, 2 - no\n");
		int key=0;
		while ((key<1) || (key>2))
			scanf("%d", &key);
		if (key == 1)
		{
			test_function1_int();
			test_function1_real();
			test_function1_complex();
			test_function2_int();
			test_function2_real();
			test_function2_complex();
			test_function3_int();
			test_function3_real();
			test_function3_complex();
			test_function4_int();
			test_function4_real();
			test_function4_complex();
		}
		printf("Enter the type of data. 1 - integer, 2 - real, 3 - complex\n");
		void(*input)(void*);
		void(*output)(void*);
		int(*comparison)(void*, void*);
		void*(*map1)(void*);
		void*(*map2)(void*);
		void*(*map)(void*);
		int size_element;
		input = int_input;
		output = int_output;
		comparison = int_comparison;
		map1 = map1_int;
		map2 = map2_int;
		size_element = 4;
		scanf("%d", &key);
		while ((key<1)||(key>3))
			scanf("%d", &key);
		switch (key)
		{
		case 1:
		{
			input = int_input;
			output = int_output;
			comparison = int_comparison;
			map1 = map1_int;
			map2 = map2_int;
			size_element = 4;
			break;
		}
		case 2:
		{
			input = double_input;
			output = double_output;
			comparison = double_comparison;
			map1 = map1_double;
			map2 = map2_double;
			size_element = 8;
			break;
		}
		case 3:
		{
			input = complex_input;
			output = complex_output;
			comparison = complex_comparison;
			map1 = map1_complex;
			map2 = map2_complex;
			size_element = 16;
			break;
		}
		default:
			break;
		}
		
		printf("Select an action:\n 1 - unification\n 2 - substraction(Subtraction of the second set from the first)\n 3 - map\n 4 - check for the inclusion of subset(Is the first set a subset of the second?)\n");
		scanf("%d", &key);
		while((key>4)||(key<1)) 
			scanf("%d", &key);
		switch (key)
		{
		case 1:
		{
			int N1;
			int N2;
			printf("Enter first List's number of elements\n");
			scanf("%d", &N1);
			printf("Enter the first List\n");
			List* L1 = list_alloc(N1, size_element, input, comparison);
			printf("Enter second List's number of elements\n");
			scanf("%d", &N2);
			printf("Enter the second List\n");
			List* L2 = list_alloc(N2, size_element, input, comparison);
			sets_addition(L1, L2, comparison);
			list_output(L2, output);
			List_free(L1);
			List_free(L2);
			free(L1);
			free(L2);
			break;
		}
		case 2:
		{
			int N1;
			int N2;
			printf("Enter first List's number of elements\n");
			scanf("%d", &N1);
			printf("Enter the first List\n");
			List* L1 = list_alloc(N1, size_element, input, comparison);
			printf("Enter second List's number of elements\n");
			scanf("%d", &N2);
			printf("Enter the second List\n");
			List* L2 = list_alloc(N2, size_element, input, comparison);
			sets_substraction(L1, L2, comparison);
			list_output(L1, output);
			List_free(L1);
			List_free(L2);
			free(L1);
			free(L2);
			break;
		}
		case 3: 
		{
			int N;
			printf("Enter number of elements\n");
			scanf("%d", &N);
			List* L = list_alloc(N, size_element, input, comparison);
			list_output(L, output);
			int key2;
			printf("Select function. 1: f(x)=2*x, 2: f(x)=x^2\n");
			scanf("%d", &key2);
			while ((key2<1)||(key2>2))
				scanf("%d", &key2);
			if (key2 == 1) map = map1;
			else map = map2;
			mapf(L, map);
			list_output(L, output);
			List_free(L);
			free(L);
			break;
		}
		case 4:
		{
			int N1;
			int N2;
			printf("Enter first List's number of elements\n");
			scanf("%d", &N1);
			printf("Enter second List's number of elements\n");
			scanf("%d", &N2);
			if (N1>N2)
				printf("The first set is not a subset of the second.\n");
			else
			{
				printf("Enter the first List\n");
				List* L1 = list_alloc(N1, size_element, input, comparison);
				printf("Enter the second List\n");
				List* L2 = list_alloc(N2, size_element, input, comparison);
				if (test_subset(L1, L2, comparison))
					printf("The first set is not a subset of the second.\n");
				else printf("The first set is a subset of the second.\n");
				List_free(L1);
				List_free(L2);
				free(L1);
				free(L2);
			}
			
			break;
		}
		default:
			break;
		}
		
		
    return 0;
}

