#include <stdio.h>
#include "bst.h"

void print_node(Node *target)
{
    printf("(key = %d, value = %c)\n", target->key, target->value);
}

void print_not_found()
{
    printf("not found! \n");
}

int main()
{
    initTree();
    tree->root = newNode(5, 'a');
    insert(tree->root, newNode(3, 'b'));
    insert(tree->root, newNode(4, 'f'));
    insert(tree->root, newNode(2, 'c'));
    insert(tree->root, newNode(7, 'd'));
    insert(tree->root, newNode(6, 'e'));
    // dfs_preorder(tree->root, print_node);
    search(tree->root, 8, print_node, print_not_found);
    search(tree->root, 7, print_node, print_not_found);
    return 0;
}