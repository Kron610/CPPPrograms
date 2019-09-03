#ifndef _CLASS__C__
#define _CLASS__C__
#include <complex>
using namespace std;


template <typename T>
struct node {
	T data;
	int branches;
	node *left;
	node *right;
	node *middle;
};


template <typename T>
class tree
{

	node<T> *root;


	void destroy(node<T> *node);

	void output_mentioned_level(node<T> *node, int level);

	void treeprintstring(node<T> *root);

	// Map
	void map(node<T> *node, T value);


    // Where
	void where(node<T> *node, tree<T> *new_tree);

	bool check(node<double> *node);

	bool check(node<int> *node);

	bool check(node<complex<double>> *node);


	// Cлияние
	void merge(node<T> *node_of_1st_tree, tree<T> *second_tree);


	// Извлечение поддерева по заданному элементу
	void subtree_extraction(node<T> *node, T value, tree<T> *res_tree, int *flag);


	// Поиск элемента на вхождение
	void check_contain_element(node<T> *node, T value, bool* check_ptr);


	// Поиск поддерева на вхождение
	void check_contain_subtree(node<T> *big_node, node<T> *small_node, bool *check_ptr, bool *if_same);


	public:

	
	// Конструктор и деструктор
	tree( );

	~tree( );

	node<T> *getroot( );

	int getbranches( );

	void add_element(T data);

	void set_tree( );

	void set_tree_complex( );

    void output_by_levels( );

	// Для main

	void map(T value);

	void where(tree<T> *new_tree);

	void merge(tree<T> *second_tree);

	bool check_contain_element(T value);

    void comparison_trees(node<T> *first, node<T> *second, bool* if_same);

	bool check_contain_subtree(tree<T> *smallTree);

	void subtree_extraction(T value, tree<T> *res_tree);

	void output_circumvention();
	
};

#include "Method.h"

#endif //!_CLASS__C__