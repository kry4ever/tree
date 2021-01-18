#ifndef BST
#define BST

#include <stdlib.h>

typedef struct Node
{
    /* data */
    struct Node *left;
    struct Node *right;
    int key;
    int value;
} Node;

typedef struct Tree
{
    /* data */
    Node *root;
    int height;
} Tree;

Tree* tree;

typedef void visit(Node *);
typedef void not_found();

void initTree();
void insert(Node *root, Node *node);
void dfs_preorder(Node* root, visit v);
void search(Node *node, int key, visit v, not_found not);
Node* newNode(int key, int value);

#endif