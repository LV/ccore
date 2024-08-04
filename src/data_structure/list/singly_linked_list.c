#include "singly_linked_list.h"
#include <stdlib.h>

struct SLLNode* sll_create(int value)
{
    struct SLLNode* new_node = (struct SLLNode*)malloc(sizeof(struct SLLNode));
    if (new_node == NULL)
        return NULL; // memalloc failure

    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// inserts before `root`
// e.g:
// sll_node = [3, 2, 5]
// value = 4
// sll_insert(sll_node, 4) == [4, 3, 2, 5]
struct SLLNode* sll_insert(struct SLLNode* root, int value)
{
    if (root == NULL)
        return sll_create(value);

    struct SLLNode* new_node = sll_create(value);
    if (new_node == NULL)
        return root; // memalloc failure

    new_node->next = root;
    return new_node;
}

struct SLLNode* sll_delete(struct SLLNode* root)
{
    if (root == NULL)
        return NULL;

    struct SLLNode* next = root->next;
    free(root);
    return next;
}
