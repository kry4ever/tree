#include "bst.h"

Tree *tree = NULL;

void initTree()
{
    if (tree == NULL)
    {
        tree = (Tree *)malloc(sizeof(Tree));
        tree->root = NULL;
    }
}

Node* newNode(int key, int value){
    Node* result = (Node*)malloc(sizeof(Node));
    result->key = key;
    result->value = value;
    result->left = NULL;
    result->right = NULL;
    return result;
}

void insert(Node *root, Node *node)
{
    if (root == NULL || node == NULL)
    {
        return;
    }

    if (root->key == node->key)
    {
        return;
    }

    if (node->key < root->key)
    {
        if (root->left == NULL)
        {
            root->left = node;
        }
        else
        {
            insert(root->left, node);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = node;
        }
        else
        {
            insert(root->right, node);
        }
    }
}

void dfs_preorder(Node *root, visit v)
{
    if (root == NULL)
    {
        return;
    }

    v(root);
    dfs_preorder(root->left, v);
    dfs_preorder(root->right, v);
}

void search(Node *node, int key, visit v, not_found not)
{
    if (node == NULL)
    {
        not();
        return;
    }

    if (node->key == key)
    {
        v(node);
    }
    else if (key < node->key)
    {
        search(node->left, key, v, not);
    }
    else
    {
        search(node->right, key, v, not);
    }
}
