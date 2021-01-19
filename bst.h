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

void initTree(Node* root);
void insert(Node *root, Node *node);
void dfs_preorder(Node* root, visit v);
void dfs_middleorder(Node *root, visit v);
void dfs_postorder(Node *root, visit v);
void search(Node *node, int key, visit v, not_found not);
int search2(Node *node, int key);
int search3(Node *node, int key);
int delete (Node *root, int key);
Node* newNode(int key, int value);

#endif