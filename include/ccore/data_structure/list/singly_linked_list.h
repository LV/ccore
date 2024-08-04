#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct SLLNode {
    int data;
    struct SLLNode* next;
};

struct SLLNode* sll_create(int value);
struct SLLNode* sll_insert_before(struct SLLNode* root, int value);
struct SLLNode* sll_delete(struct SLLNode* root);

#endif // SINGLY_LINKED_LIST_H
