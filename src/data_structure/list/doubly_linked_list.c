#include <ccore/data_structure/list/doubly_linked_list.h>
#include <stdlib.h>

struct DLLNode {
    int data;
    struct DLLNode* left;
    struct DLLNode* right;
};

struct DLLNode* dll_create(int value)
{
    struct DLLNode* new_node = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    if (new_node == NULL)
        return NULL; // malloc failure

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct DLLNode* dll_insert_left(struct DLLNode* root, int value)
{
    if (root == NULL)
        return dll_create(value);

    struct DLLNode* new_node = dll_create(value);
    if (new_node == NULL)
        return NULL; // malloc failure

    new_node->left = root->left;
    root->left = new_node;
    new_node->right = root;
    new_node->data = value;

    return new_node;
}

struct DLLNode* dll_insert_right(struct DLLNode* root, int value)
{
    if (root == NULL)
        return dll_create(value);

    struct DLLNode* new_node = dll_create(value);
    if (new_node == NULL)
        return NULL; // malloc failure

    new_node->right = root->right;
    new_node->left = root;
    root->right = new_node;

    return new_node;
}

// returns the leftmost node (right node if left node doesn't exist)
struct DLLNode* dll_delete(struct DLLNode* root)
{
    if (root == NULL)
        return NULL;

    if (root->right != NULL)
        root->right->left = root->left;

    if (root->left != NULL)
        root->left->right = root->right;

    free(root);

    if (root->left != NULL)
        return root->left;

    return root->right;
}
