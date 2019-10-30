#include "Binary_tree.h"
#include <iostream>
#include<string.h>
#include<vector>
 Binary_tree::Binary_tree()
 {root=NULL;
 }
   
    Binary_tree::node* Binary_tree::CreateLeaf(int key)             //2 scope res bcs node is a data struct of class binary search tree, hence it needs to be defined
    {node *ptr=new node;
    ptr->key=key;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
    }
 
 void Binary_tree::add_leaf(int key)
 {if(root==NULL)                                                                      //if tree empty then create new node
 {root=CreateLeaf(key);}
 else {
     node *ptr=Binary_tree::CreateLeaf(key);                                           //create new node
     
     node* r=root;                                                                      //temp pointer to iterate in loop
     while((r->left!=NULL  ||   r->right!=NULL) )                          //if both values of node are empty and node is pointing to no other node
     {if(r->key<key   && r->right!=NULL)                              //go right only if key value is greater than node and right of node is not pointing to null
        {r=r->right;}                                           //right should not be null as we want to go down only if a node is present;
      if(r->key>key   && r->left!=NULL) 
        {r=r->left;}
      if(r->key<key   && r->right==NULL)                          //break if key is greater than nodeval and node of right points to null that means we found the node and we want to place it
          break;                                                //in the right order
      if(r->key>key   && r->left==NULL)
          break;
     }
    
    
    {if(key>r->key)
    {r->right=ptr;}
    else
    {r->left=ptr;}
 } }
 }
 
 void Binary_tree::print_in_order()
 {print_in_order_private(root);
 }
 
 void Binary_tree::print_in_order_private(node *ptr)
 {if(root==NULL)
     {std::cout<<"tree is empty"<<std::endl;}
 else
     {if(ptr->left!=NULL)
         {print_in_order_private(ptr->left);}
         std::cout<<"element is "<<ptr->key<<" left addr is "<<ptr->left<<" right addr is "<<ptr->right<<std::endl;
     if(ptr->right!=NULL)
        {print_in_order_private(ptr->right);}
     
     }
 }
 

Binary_tree::node* Binary_tree::Find_node(int key)
{node* ptr=root;
if(ptr==NULL)
     {std::cout<<"tree is empty"<<std::endl;return NULL;}
 else
     {while(ptr!=NULL)
     {if(key==ptr->key)
         {
         return ptr;}
     if(key>ptr->key)
        {ptr=ptr->right;}
    else if(key<ptr->key)
        {ptr=ptr->left;}
      
     }
     }
    
    return NULL;
    }

int Binary_tree::Return_root_key()
{if(root==NULL)
        {std::cout<<"Tree is empty"<<std::endl;return -1000;}
else
        {return root->key;}
}
void Binary_tree::print_children(int key)
{
    
    node *n=Find_node(key);
    if(n==NULL)
        {std::cout<<"Node not present in tree"<<std::endl;}
    else
        {if(n->left==NULL  &&    n->right==NULL)
            {std::cout<<"Node has no children"<<std::endl;}
        if(n->left==NULL  &&    n->right!=NULL)
            {std::cout<<"Node has only right child which is "<<n->right->key<<std::endl;}
        if(n->left!=NULL  &&    n->right==NULL)
            {std::cout<<"Node has only left child which is "<<n->left->key<<std::endl;}
        if(n->left!=NULL  &&    n->right!=NULL)
            {std::cout<<"Node has both left and right children which are "<<n->left->key<<" "<<n->right->key<<std::endl;}
        
            
            }

       }
int Binary_tree:: Find_smallest_key()
{
    int b=Find_smallest_key_private(root);
return b;}


int Binary_tree:: Find_smallest_key_private(Binary_tree::node *ptr)
{ptr=root;
    while(ptr->left!=NULL )
    {
        {ptr=ptr->left;}
        
        
        }
        
        return ptr->key;
    }
    
void Binary_tree::Remove_node(int key)
{node *ptr=Find_node(key);
Remove_node_private(key,root);}


void Binary_tree::Remove_node_private(int key,node *parent)
{if(root!=NULL)
    {if(root->key==key)
        {Remove_root_match();}
    else
        {if(key<parent->key   &&   parent->left!=NULL)
            {if(parent->left->key==key)
                    {Remove_match(parent,parent->left,true);
                    Remove_node_private(key,parent->left);}
            
            else if(key>parent->key   &&   parent->left!=NULL)
            {if(parent->right->key==key)
                    {Remove_match(parent,parent->right,false);
                    Remove_node_private(key,parent->right);}
                    }
            else
            {std::cout<<"Key not found"<<std::endl;}
            
            }
        
          }
        }
    else
    {std::cout<<"Tree Empty"<<std::endl;}
    }

void Binary_tree::Remove_root_match()
{if(root!=NULL)
    {node *delptr=root;
    int rootKey=root->key;
    int smallest_in_right_subtree;
    if(root->left==NULL   &&   root->right==NULL)
        {root=NULL;
        delete delptr;}
        
    else if(root->left==NULL  &&   root->right!=NULL)
        {root=root->right;
        delptr->right=NULL;
        delete delptr;
        std::cout<<"root was deleted -"<<rootKey<<" New root is :"<<root->key<<std::endl;
            }
    else if(delptr->left!=NULL  &&  delptr->right==NULL)
        {root=root->left;
        delptr->left=NULL;
        delete delptr;
        std::cout<<"root was deleted -"<<rootKey<<" New root is :"<<root->key<<std::endl;
            }
    else
        {smallest_in_right_subtree= Find_smallest_key_private(root->right);
        Remove_node_private(smallest_in_right_subtree,root);
        root->key=smallest_in_right_subtree;
        std::cout<<"root was deleted -"<<rootKey<<" New root is :"<<root->key<<std::endl;
        
            }
    }
else
    {std::cout<<"cannot remove root tree is empty"<<std::endl;}
    
}


void Binary_tree::Remove_match(node *parent,node *match,bool left)
{if(root!=NULL)
    {node *delptr;
    int match_key=root->key;
    int smallest_in_right_subtree;
       if(match->left==NULL   &&   match->right==NULL)
            {delptr=match;
            if(left==true)
                {parent->left=NULL;}
            else
                {parent->right=NULL;}
            delete delptr; }
       else if(match->left==NULL   &&   match->right!=NULL) 
            {if(left==true)
                {parent->left=match->right;}
            else
                {parent->right=match->right;}
            match->right=NULL;
            delptr=match;
            delete delptr;
                }
        else if(match->left!=NULL   &&   match->right==NULL) 
            {if(left==true)
                {parent->left=match->left;}
            else
                {parent->right=match->left;}
            match->left=NULL;
            delptr=match;
            delete delptr;
                }
        else
            {smallest_in_right_subtree=Find_smallest_key_private(match->right);
            Remove_node_private(smallest_in_right_subtree,match);
            match->key=smallest_in_right_subtree;
            
                }
        }
else
    {std::cout<<"cannot remove root tree is empty"<<std::endl;}
    
    }
