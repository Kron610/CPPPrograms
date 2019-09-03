#ifndef _TEST__T__
#define _TEST__T__
#include "Class.h"
#include <iostream>
#include <math.h>


tree<double> *test_tree( )
{
	tree <double> *maintree=new tree<double>;
	maintree->add_element(2.5);
	maintree->add_element(1.3);
	maintree->add_element(1.0);
	maintree->add_element(3.7);
	return maintree;
}

void map_test( )
{
	tree<double> *maintree=new tree<double>;
	maintree=test_tree( );
	maintree->map(2.0);
	tree<double> *map_tree=new tree<double>;
	map_tree->add_element(2);
	map_tree->add_element(2);
	map_tree->add_element(2);
	map_tree->add_element(2);
	bool *check=new bool;
	*check=1;
	maintree->comparison_trees(maintree->getroot( ), map_tree->getroot( ), check);
	if(*check) cout<<"maptest: success"<<endl;
	else cout<<"maptest: fall"<<endl;
	delete maintree;
	delete map_tree;
}

void where_test( ) 
{
	tree<double> *maintree=new tree<double>;
	maintree=test_tree( );
	tree<double> *maintree$=new tree<double>;
	maintree->where(maintree$);
	tree<double> *where_tree=new tree<double>;
	where_tree->add_element(2.5);
	where_tree->add_element(1.3);
	where_tree->add_element(1.0);
	where_tree->add_element(3.7);
	bool *check=new bool;
	*check=1;
	maintree->comparison_trees(maintree$->getroot( ), where_tree->getroot( ), check);
	if(*check) cout<<"wheretest: success"<<endl;
	else cout<<"wheretest: fall"<<endl;
	delete maintree;
	delete maintree$;
	delete where_tree;
}
void merge_test( )
{
	tree<double> *maintree=new tree<double>;
	maintree=test_tree( );
	tree<double> *maintree2=new tree<double>;
	maintree2=test_tree( );
	maintree->merge(maintree2);
	if(maintree2->getbranches( )==7) cout<<"mergetest: success"<<endl;
	else cout<<"mergetest: fall"<<endl;
	delete maintree;
	delete maintree2;
}

void subtree_test( )
{
	tree<double> *maintree=new tree<double>;
	maintree=test_tree( );
	tree<double> *smalltree1=new tree<double>;
	maintree->subtree_extraction(1.3, smalltree1);
	tree<double> *smalltree2=new tree<double>;
	maintree->subtree_extraction(2.5, smalltree2);
	if(smalltree1->getbranches( )==0 && smalltree2->getbranches( )==3) cout<<"subtree_test: success"<<endl;
	else cout<<"subtree_test: fall"<<endl;
	delete maintree;
}

void contain_el_test( ) 
{
	tree<double> *maintree=new tree<double>;
	maintree=test_tree( );
	if(maintree->check_contain_element(2.5) && maintree->check_contain_element(1.3) && !maintree->check_contain_element(7.0)) cout<<"el_contain_test: success"<<endl;
	else cout<<"el_contain_test: fall"<<endl;
	delete maintree;
}
void contain_tree_test( )
{
	tree<double> *maintree=new tree<double>;
	maintree=test_tree( );
	tree<double> *tr1=new tree<double>;
	tr1->add_element(2.5);
	tr1->add_element(1.3);
	tree<double> *tr2=new tree<double>;
	tr2->add_element(1.3);
	tr2->add_element(4.3);
	if(maintree->check_contain_subtree(tr1) && !maintree->check_contain_subtree(tr2)) cout<<"if_tree_contain_test: success"<<endl;
	else cout<<"if_tree_contain_test: fall"<<endl;
	delete maintree;
	delete tr1;
	delete tr2;
};



#endif // !_TEST__T__