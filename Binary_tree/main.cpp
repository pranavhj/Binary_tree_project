#include <iostream>
#include<string.h>
#include"Binary_tree.h"
#include<vector>
using namespace std;
int main()
{   
    Binary_tree b;
    //b.Binary_tree::print_in_order();
    {b.Binary_tree::add_leaf(4);}
    b.Binary_tree::add_leaf(2);
    b.Binary_tree::add_leaf(3);
    b.Binary_tree::add_leaf(5);
    b.Binary_tree::add_leaf(6);
    b.Binary_tree::add_leaf(9);
    b.Binary_tree::print_in_order();
    
    //int h=b.Find_node(3);
    //cout<<h<<endl;
    
    b.print_children(4);
    
    int s=b.Find_smallest_key();
    cout<<s<<endl;
    
    
	return 0;
}
