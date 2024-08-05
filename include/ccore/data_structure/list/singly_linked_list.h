#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    struct SinglyLinkedListNode* head;
    struct SinglyLinkedListNode* tail;
};

// Node functions
struct SinglyLinkedListNode* singly_linked_list_node_initialize(int value);
void singly_linked_list_node_destroy(struct SinglyLinkedListNode* node);

// List functions
struct SinglyLinkedList* singly_linked_list_initialize(void);
struct SinglyLinkedList* singly_linked_list_initialize_with_value(int value);
void singly_linked_list_destroy(struct SinglyLinkedList* list);
void singly_linked_list_insert_prepend(struct SinglyLinkedList* list, int value);
void singly_linked_list_insert_append(struct SinglyLinkedList* list, int value);
void singly_linked_list_remove_head(struct SinglyLinkedList* list);
void singly_linked_list_remove_tail(struct SinglyLinkedList* list);

#endif // SINGLY_LINKED_LIST_H
