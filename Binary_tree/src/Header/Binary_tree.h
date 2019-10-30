#pragma once
#include <iostream>
#include<string>
#include<vector>
class Binary_tree
{private:
        struct node{
            node *left;
            node *right;
            int key;};
        node *root=new node;
        void print_in_order_private(node *ptr);
        int Find_smallest_key_private(node *ptr);
        void Remove_node_private(int key,node *parent);
        void Remove_root_match();
        void Remove_match(node *parent,node *match,bool left);              //match contains node to be removed               if bool false then match is right child of parent
        
public:
    Binary_tree();
    //~Binary_tree();
    node* CreateLeaf(int key);
    void add_leaf(int key);
    int traverse_node_vector(std::vector <node> *p,node *n);
    void Traverse_tree();
    void print_in_order();
    node* Find_node(int key);
    int Return_root_key();
    void print_children(int key);
    int Find_smallest_key();
    void Remove_node(int key);
    

};

