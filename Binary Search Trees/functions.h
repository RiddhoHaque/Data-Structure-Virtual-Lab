#include <bits/stdc++.h>
using namespace std;

/**
    The following structure will be used to represent all the nodes
    in the binary trees in all the functions that you have to
    implement today.

    Each challenge is worth 10 points.
*/
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
};

/**
    The following function takes the pointer to the root of a tree
    as its argument. An initially empty array values[], and an
    integer variable valueSize (initially 0) are provided as global
    variables. Implement the function so that the values array is
    filled up with the values of the nodes in the tree. The order of
    the entries in the values array should correspond with the order
    of the values of the nodes as they would appear if the tree is
    traversed in an inorder manner.
*/

int values[100105];
int valueSize;

void inorderTraversal(Node* root){

}

/**
    The following function takes a pointer to the root of a Binary
    Search Tree (BST) as its argument, and a value v to insert into
    the tree. If the value v is not already in the tree, create a new
    node in the tree with value v, while keeping the property of the
    Binary search tree intact (i.e. all values contained in the nodes
    in the left subtree will be smaller than the value in the node,
    and all values in the right subtree will be larger than it.)

    If v already exists in the tree, do not insert any new node.
    Note: The root may be null.
*/

void addToBST(Node* root, int v){

}

/**
    The following function takes a pointer to the root of a Binary
    Search Tree (BST) as its argument, and a value v to search in
    the tree. If the value v is not in the tree, return 0 and
    return 1 otherwise.

    Note: The root may be null.
*/

int searchInBST(Node* root, int v){
    return 0;
}


/**
    The following function takes a pointer to the root of a Binary
    Search Tree (BST) as its argument. Return the maximum value in
    the tree. You can assume the tree is non-empty.
*/

int maxInTree(Node* root){
    return 0;
}

/**
    The following function takes a pointer to the root of a Binary
    Tree as its argument.  Return 1 if the tree is a valid binary
    search tree, and 0 otherwise. You can assume the tree is
    non-empty.
*/


int isBST(Node* root){
    return 0;
}

/**
    The following function takes a pointer to the root of a Binary
    Search Tree (BST) as its argument, and a value v. Find the
    smallest entry in the binary search tree that is greater than
    v.

    You can assume there will at least be one number in the BST
    greater than v and that v will exist in the BST.
*/

int upperBoundBST(Node* root, int v){
    return 0;
}
