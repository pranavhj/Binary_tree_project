# Binary_tree_project
node* CreateLeaf(int key);                                         //Function creates new leaf and returns pointer to it
    void add_leaf(int key);                                           // function adds leaf to the binary tree
    int traverse_node_vector(std::vector <node> *p,node *n);                  
    void Traverse_tree();                                               //Traverse the binary tree
    void print_in_order();                                              //print all elements od tree in ascending order
    node* Find_node(int key);                                           // Find node with value key in tree. Return pointer to it
    int Return_root_key();                                               //retrun the root key 
    void print_children(int key);                                        //Print children of the node with key key
    int Find_smallest_key();                                             //find smallest key in the tree
    void Remove_node(int key);                                          //remove node with key value key
