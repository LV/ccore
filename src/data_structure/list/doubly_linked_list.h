#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DLLNode;

struct DLLNode* dll_create(int value);
struct DLLNode* dll_insert_left(struct DLLNode* root, int value);
struct DLLNode* dll_insert_right(struct DLLNode* root, int value);
struct DLLNode* dll_delete(struct DLLNode* root);

#endif // DOUBLY_LINKED_LIST_H
