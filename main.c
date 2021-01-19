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
    initTree(newNode(50, 'a'));
    insert(tree->root, newNode(30, 'b'));
    insert(tree->root, newNode(10, 'c'));
    insert(tree->root, newNode(80, 'f'));
    insert(tree->root, newNode(60, 'e'));
    insert(tree->root, newNode(90, 'g'));
    insert(tree->root, newNode(55, 'z'));
    insert(tree->root, newNode(61, 'y'));
    dfs_middleorder(tree->root, print_node);
    int result2 = search3(tree->root, 80);
    printf("the seach result is %c\n", result2);
    int d = delete (tree->root, 80);
    printf("the delete result is %d\n", d);
    int result3 = search3(tree->root, 50);
    printf("the seach result3 is %c\n", result3);
    dfs_middleorder(tree->root, print_node);
    // search(tree->root, 8, print_node, print_not_found);
    // search(tree->root, 7, print_node, print_not_found);
    return 0;
}