#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct SLLNode;

struct SLLNode* sll_create(int value);
struct SLLNode* sll_insert(struct SLLNode* root, int value);
struct SLLNode* sll_delete(struct SLLNode* root);

#endif // SINGLY_LINKED_LIST_H
