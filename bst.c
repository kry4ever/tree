#include "bst.h"

Tree *tree = NULL;

void initTree(Node *root)
{
    if (tree == NULL)
    {
        tree = (Tree *)malloc(sizeof(Tree));
        tree->root = root;
    }
}

Node *newNode(int key, int value)
{
    Node *result = (Node *)malloc(sizeof(Node));
    result->key = key;
    result->value = value;
    result->left = NULL;
    result->right = NULL;
    return result;
}

void _replace_current_with_max_in_left(Node *cur)
{
    Node *finder = cur->left;
    Node *maxInLeft = finder;
    Node *parent = cur;
    while (finder != NULL)
    {
        if (maxInLeft != finder)
        {
            parent = maxInLeft;
        }
        maxInLeft = finder;
        finder = finder->right;
    }
    cur->key = maxInLeft->key;
    cur->value = maxInLeft->value;
    if (parent->right == maxInLeft)
    {
        parent->right = NULL;
    }
    else if (parent->left == maxInLeft)
    {
        parent->left = maxInLeft->left;
    }
    free(maxInLeft);
}

int delete (Node *root, int key)
{
    Node *cur = root;
    Node *parent = cur;
    while (cur != NULL)
    {
        if (cur->key == key)
        {
            break;
        }
        else if (cur->key < key)
        {
            parent = cur;
            cur = cur->right;
        }
        else
        {
            parent = cur;
            cur = cur->left;
        }
    }

    if (cur == NULL)
    {
        return -1;
    }

    if (cur == root)
    {
        if (cur->left == NULL && cur->right == NULL)
        {
            tree->root = NULL;
        }
        else if (cur->left == NULL)
        {
            tree->root = cur->right;
            free(cur);
        }
        else if (cur->right == NULL)
        {
            tree->root = cur->left;
            free(cur);
        }
        else
        {
            _replace_current_with_max_in_left(cur);
        }
    }
    else if (cur->left == NULL && cur->right == NULL)
    {
        if (parent->left == cur)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }

        free(cur);
    }
    else if (cur->left == NULL)
    {
        parent->right = cur->right;
        free(cur);
    }
    else
    {
        _replace_current_with_max_in_left(cur);
    }

    return 0;
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

void dfs_middleorder(Node *root, visit v)
{
    if (root == NULL)
    {
        return;
    }

    dfs_middleorder(root->left, v);
    v(root);
    dfs_middleorder(root->right, v);
}

void dfs_postorder(Node *root, visit v)
{
    if (root == NULL)
    {
        return;
    }

    dfs_postorder(root->left, v);
    dfs_postorder(root->right, v);
    v(root);
}

void search(Node *node, int key, visit v, not_found not )
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
        search(node->left, key, v, not );
    }
    else
    {
        search(node->right, key, v, not );
    }
}

int search2(Node *node, int key)
{
    if (node == NULL)
    {
        return -1;
    }

    if (node->key == key)
    {
        return node->value;
    }
    else if (key < node->key)
    {
        return search2(node->left, key);
    }
    else
    {
        return search2(node->right, key);
    }
}

int search3(Node *node, int key)
{
    Node *p = node;
    while (p != NULL)
    {
        if (p->key == key)
        {
            return p->value;
        }
        else if (p->key < key)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }

    return -1;
}
