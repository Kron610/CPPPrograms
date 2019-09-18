#pragma once
#include "SortedSequence.h"
#include <time.h>
#include <chrono>

template <typename T>
class TreeNode
{
public:
	TreeNode(const T &a)
	{
		data = a;
		left = 0;
		right = 0;
		height = 1;
	}

	T GetData()
	{
		return data;
	}
	
	unsigned char GetHeight()
	{
		return this ? this->height : 0;
	}

	TreeNode* left;
	TreeNode* right;
	T data;
	unsigned char height;
};

template <typename T>
class Tree
{
private:
	TreeNode<T> *root;

	TreeNode<T>* Insert(T &x, TreeNode<T>* &node)
	{
		if (node == 0)
		{
			return new TreeNode<T>(x);
		}
		else
		{
			if (x < node->GetData())
				node->left = Insert(x, node->left);
			else
				node->right = Insert(x, node->right);
			return balance(node);
		}
	}

	void OutputRoot(TreeNode<T>* root)
	{
		if (root != 0)
		{
			cout << "(" << root->data << ")";
			cout << "{";
			OutputRoot(root->left);
			cout << "}";
			cout << "[";
			OutputRoot(root->right);
			cout << "]";
		}
	}

	unsigned char GetHeight(TreeNode<T>* node)
	{
		return node ? node->height : 0;
	}

	int bfactor(TreeNode<T>* p)
	{
		return GetHeight(p->right) - GetHeight(p->left);
	}

	void fixheight(TreeNode<T>* p)
	{
		unsigned char hl = GetHeight(p->left);
		unsigned char hr = GetHeight(p->right);
		p->height = (hl > hr ? hl : hr) + 1;
	}

	TreeNode<T>* rotateright(TreeNode<T>* &p) // правый поворот вокруг p
	{
		TreeNode<T>* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}

	TreeNode<T>* rotateleft(TreeNode<T>* &q) // левый поворот вокруг q
	{
		TreeNode<T>* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}

	TreeNode<T>* balance(TreeNode<T>* &p) // балансировка узла p
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}
	void destroy(TreeNode<T>* node)
	{
		if (node != 0)
		{
			destroy(left);
			destroy(right);
			delete node;
		}
	}

public:
	Tree(TreeNode<T>* node = 0)
	{
		root = node;
	}

	~Tree()
	{
		destroy(root);
	}
	void InsertNode(T &x)
	{
		this->root = Insert(x, this->root);
	}

	int SearchElement(const T &key)
	{
		int index = 0;
		TreeNode<T>* node = this->root;
		while (1)
		{
			if (node == 0)
				return -1;
			if (node->GetData() == key)
				return index;
			if (node->GetData() < key)
			{
				node = node->right;
				index = 2 * index + 2;
			}
			else
			{
				node = node->left;
				index = 2 * index + 1;
			}
		}
	}

	T GetMin()
	{
		TreeNode<T>* node = this->root;
		while (node->left != 0)
			node = node->left;
		return node->GetData();
	}

	T GetMax()
	{
		TreeNode<T>* node = this->root;
		while (node->right != 0)
			node = node->right;
		return node->GetData();
	}

	void Output()
	{
		OutputRoot(root);
	}
};

template <typename T>
class TreeBuilder
{
public:
	Tree<T>* GetTree(SortedSequence<T>* sequence)
	{
		TreeNode<T>* node = _createBalancedTree(sequence, 0, sequence->GetLength() - 1);
		Tree<T>* NewTree = new Tree<T>(node);
		return NewTree;
	}
private:
	TreeNode<T>* _createBalancedTree(SortedSequence<T>* sequence, int start, int  end) {
		if (end < start)
			return 0;
		int mid = ((start + end) / 2);
		TreeNode<T>* node = new TreeNode<T>(sequence->Get(mid));

		node->left = _createBalancedTree(sequence, start, mid - 1);
		node->right = _createBalancedTree(sequence, mid + 1, end);
		unsigned char hl = node->left->GetHeight();
		unsigned char hr = node->right->GetHeight();
		node->height = (hl > hr ? hl : hr) + 1;
		return node;
	}
};

template <typename T>
auto time_function2(SortedSequence<T>* sequence, T key)
{
	auto t = chrono::high_resolution_clock::now();
	TreeBuilder<T>* builder = new TreeBuilder<T>();
	Tree<T>* tree = builder->GetTree(sequence);
	int find = tree->SearchElement(key);
	auto t2 = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::nanoseconds>(t2 - t).count();
}

void test_tree_search()
{
	SortedArraySequence<int>* sequence = new SortedArraySequence<int>();
	sequence->Add(0);
	sequence->Add(3);
	sequence->Add(5);
	sequence->Add(9);
	sequence->Add(2);
	sequence->Add(4);
	sequence->Add(1);
	TreeBuilder<int>* builder = new TreeBuilder<int>();
	Tree<int>* tree = builder->GetTree(sequence);
	if ((tree->SearchElement(6) == -1)&&(tree->SearchElement(9)!=-1))
		cout << "Test.tree_search passed" << endl;
	else
		cout << "Test.tree_search isn't passed" << endl;
}

void test_tree_min()
{
	SortedArraySequence<int>* sequence = new SortedArraySequence<int>();
	sequence->Add(0);
	sequence->Add(3);
	sequence->Add(5);
	sequence->Add(9);
	sequence->Add(2);
	sequence->Add(4);
	sequence->Add(1);
	TreeBuilder<int>* builder = new TreeBuilder<int>();
	Tree<int>* tree = builder->GetTree(sequence);
	if (tree->GetMin() == 0)
		cout << "Test.tree_min passed" << endl;
	else
		cout << "Test.tree_min isn't passed" << endl;
}

void test_tree_max()
{
	SortedArraySequence<int>* sequence = new SortedArraySequence<int>();
	sequence->Add(0);
	sequence->Add(3);
	sequence->Add(5);
	sequence->Add(9);
	sequence->Add(2);
	sequence->Add(4);
	sequence->Add(1);
	TreeBuilder<int>* builder = new TreeBuilder<int>();
	Tree<int>* tree = builder->GetTree(sequence);
	if (tree->GetMax() == 9)
		cout << "Test.tree_max passed" << endl;
	else
		cout << "Test.tree_max isn't passed" << endl;
}