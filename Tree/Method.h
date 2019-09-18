#ifndef _METHOD__M__
#define _METHOD__M__

#define LEFT 0
#define MIDDLE 1
#define RIGHT 2

#include <complex>
#include "Class.h"
using namespace std;

template <typename T>
tree<T>::tree( )
{
	root=nullptr;
}

template <typename T>
tree<T>::~tree( ) 
{
	destroy(root);
}

template <typename T>
void tree<T>::add_element(T data) 
{
	if(root==nullptr)
	{
		root=new node<T>;
		root->left=nullptr;
		root->right=nullptr;
		root->middle=nullptr;
		root->data=data;
		root->branches=0;
	}
	else 
	{
		node<T> *current=root;
		int n(1), side(LEFT),  range(1), number=root->branches+2;

		while((3*n-1)<=number)
		{
			n=3*n-1;
			range=3*range;
		}
		int levelsize=n;

		while(1)
		{
			if(number < (levelsize+range/3)) 
			{
				current->branches++;
				if(range!=3) {
					current=current->left;
					range=range/3;
				}
				else
				{
					side=LEFT;
					break;
				}
			}
			else
				if((number>=(levelsize+range/3))&&(number<(levelsize+range*2/3))) 
				{
					current->branches++;
					if(range!=3) 
					{
						current=current->middle;
						range=range/3;
						levelsize+=range;
					}
					else 
					{
						side=MIDDLE;
						break;
					}
				}
				else 
				{
					current->branches++;
					if(range!=3) 
					{
						current=current->right;
						range=range/3;
						levelsize=levelsize+2*range;
					}
					else 
					{
						side=RIGHT;
						break;
					}
				}
		}
		node<T> *newnode=new node<T>;
		newnode->branches=0;
		newnode->left=nullptr;
		newnode->right=nullptr;
		newnode->middle=nullptr;
		newnode->data=data;
		if(side==LEFT) 
		{
			current->left=newnode;
		}
		else if(side==MIDDLE)
		{
			current->middle=newnode;
		}
		else
		{
			current->right=newnode;
		}
	}
}

template <typename T>
void tree<T>::destroy(node<T> *node)
{
	if(node!=nullptr)
	{
		destroy(node->left);
		destroy(node->right);
		destroy(node->middle);
		delete node;
	}
}

template <typename T>
void tree<T>::map(node<T> *node, T sample) 
{
	if(node!=nullptr) 
	{
		node->data=sample;
		map(node->left, sample);
		map(node->middle, sample);
		map(node->right, sample);
	}
}

template <typename T>
void tree<T>::where(node<T> *node, tree<T> *new_tree)
{
	if(node!=nullptr) 
	{
		if(check(node))
		{
			T key=node->data;
			new_tree->add_element(key);
		}
		where(node->left, new_tree);
		where(node->middle, new_tree);
		where(node->right, new_tree);
		
	}
}

template <typename T>
bool tree<T>::check(node<double> *node)
{
	if(node->data < 13.0) return true;
	else return false;
}

template <typename T>
bool tree<T>::check(node<int> *node)
{
	if(node->data < 13) return true;
	else return false;
}

template <typename T>
bool tree<T>::check(node<complex<double>> *node)
{
	if(abs(node->data) < 13.0) return true;
	else return false;
}

template <typename T>
void tree<T>::merge(node<T> *node_of_1st_tree, tree<T> *second_tree) 
{
	if(node_of_1st_tree!=nullptr) 
	{
		second_tree->add_element(node_of_1st_tree->data);
		merge(node_of_1st_tree->left, second_tree);
		merge(node_of_1st_tree->middle, second_tree);
		merge(node_of_1st_tree->right, second_tree);
	}
}

template <typename T>
void tree<T>::subtree_extraction(node<T> *node, T element, tree<T> *result_tree, int *flag)
{
	if(node!=nullptr && *flag==0) 
	{
		if(node->data==element)
		{
			result_tree->root=node;
			*flag=1;
		}
		subtree_extraction(node->left, element, result_tree, flag);
		subtree_extraction(node->middle, element, result_tree, flag);
		subtree_extraction(node->right, element, result_tree, flag);
	}
}

template <typename T>
void tree<T>::check_contain_element(node<T> *node, T element, bool* check_ptr) 
{
	if(node!=nullptr && *check_ptr==false) 
	{
		if(node->data==element) 
		{
			*check_ptr=true;
		}
		check_contain_element(node->left, element, check_ptr);
		check_contain_element(node->middle, element, check_ptr);
		check_contain_element(node->right, element, check_ptr);
	}
}

template <typename T>
void tree<T>::comparison_trees(node<T> *first_tree, node<T> *second_tree, bool* key_same)
{
	if(second_tree!=nullptr)
	{
		if((first_tree==nullptr)||(first_tree->data!=second_tree->data)) 
			*key_same=0;
		if((*key_same!=0)&&(first_tree!=nullptr)) 
		{
			comparison_trees(first_tree->left, second_tree->left, key_same);
			comparison_trees(first_tree->middle, second_tree->middle, key_same);
			comparison_trees(first_tree->right, second_tree->right, key_same);
		}
	}
}

template <typename T>
void tree<T>::check_contain_subtree(node<T> *big_node, node<T> *small_node, bool *check_ptr, bool *key_same) 
{
	if(big_node!=nullptr)
	{
		if((big_node->data==small_node->data)&&(!(*check_ptr)))
		{
			comparison_trees(big_node, small_node, key_same);
			if(*key_same) 
			{
				*check_ptr=1;
			}
		}
		if(!(*check_ptr)) 
		{
			check_contain_subtree(big_node->left, small_node, check_ptr, key_same);
			check_contain_subtree(big_node->middle, small_node, check_ptr, key_same);
			check_contain_subtree(big_node->right, small_node, check_ptr, key_same);
		}
	}
}

template <typename T>
void tree<T>::output_mentioned_level(node<T> *node, int level)
{
	if(node!=nullptr)
	{
		if(level==0)
			cout<<"<"<<node->data<<"> ";
		output_mentioned_level(node->left, level - 1);
		output_mentioned_level(node->middle, level-1);
		output_mentioned_level(node->right, level-1);
		
	}
}

template <typename T>
node<T>* tree<T>::getroot( ) 
{
	return root;
}

template <typename T>
int tree<T>::getbranches( )
{
	return root->branches;
}

template <typename T>
void tree<T>::set_tree( ) 
{
	cout<<"Enter the number of elements in the tree: ";
	int amount_of_elements;
	do
	{ 
		cin>>amount_of_elements;
	}
	while(amount_of_elements < 1);
	cout<<"Enter "<<amount_of_elements<<" elements: "<<endl;
	for(int i=0; i < amount_of_elements; i++)
	{
		cout<<"  Enter "<<i+1<<" element: ";
		T key;
		cin>>key;
		this->add_element(key);
	}
}

template <typename T>
void tree<T>::set_tree_complex( )
{
	cout<<"Enter the number of elements in the tree: ";
	int amount_of_elements;
	do 
	{
		cin>>amount_of_elements;
	}
	while(amount_of_elements < 1);
	cout<<"Enter "<<amount_of_elements<<" elements: "<<endl;
	for(int i=0; i < amount_of_elements; i++) 
	{
		cout<<"  Enter "<<i+1<<"element: ";
		double real, imag;
		cout<<"Real: ";
		cin>>real;
		cout<<"     Imaginary: ";
		cin>>imag;
		complex<double> key(real, imag);
		this->add_element(key);
	}
}

template <typename T>
void tree<T>::map(T value) 
{
	map(root, value);
}

template <typename T>
void tree<T>::where(tree<T> *new_tree)
{
	where(root, new_tree);
}

template <typename T>
void tree<T>::merge(tree<T> *second_tree)
{ 
	merge(root, second_tree);
}

template <typename T>
void tree<T>::subtree_extraction(T value, tree<T> *res_tree)
{
	int *flag=new int;
	*flag=0;
	subtree_extraction(root, value, res_tree, flag);
	delete flag;
}

template <typename T>
bool tree<T>::check_contain_element(T value)
{
	bool* check_ptr=new bool;
	*check_ptr=false;
	check_contain_element(root, value, check_ptr);
	bool check=*check_ptr;
	delete check_ptr;
	return check;
}

template <typename T>
bool tree<T>::check_contain_subtree(tree<T> *smallTree)
{
	bool *check_ptr=new bool; 
	*check_ptr=0;
	bool *if_same=new bool; 
	*if_same=1;
	check_contain_subtree(root, smallTree->root, check_ptr, if_same);
	delete if_same;
	bool to_return=*check_ptr;
	delete check_ptr;
	return to_return;
}

template <typename T>
void tree<T>::output_by_levels( )
{
	cout<<"\nTraversal by levels:"<<endl;
	int max_level=1, n=2;
	while(n-1<=root->branches)
	{ 
		max_level++; 
		n=3*n-1;
	}
	if(root!=nullptr)
	{
		cout<<root->data<<endl;
	}
	for(int i=1; i < max_level; i++)
	{
		output_mentioned_level(root, i);
		cout<<endl;
	}
}

template <typename T>
void tree<T>::treeprintstring(node<T> *root)
{
	if (root != NULL)
	{
		cout << "(" << root->data << ")";
		cout << "[" ;
		treeprintstring(root->middle);
		cout << "]";
		cout << "{" ;
		treeprintstring(root->left);
		cout << "}" ;
		cout << "{"  ;
		treeprintstring(root->right); 
		cout << "}"  ;
	}
}
template <typename T>
void tree<T>::output_circumvention() 
{
	treeprintstring(root);
}
#endif // !_METHOD__M__