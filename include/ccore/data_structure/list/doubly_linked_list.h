#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

struct DoublyLinkedListNode {
    int data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
};

struct DoublyLinkedList {
    struct DoublyLinkedListNode* head;
    struct DoublyLinkedListNode* tail;
    size_t size;
};

// Node functions
struct DoublyLinkedListNode* doubly_linked_list_node_initialize(int value);
void doubly_linked_list_node_destroy(struct DoublyLinkedListNode* node);

// List functions
struct DoublyLinkedList* doubly_linked_list_initialize(void);
struct DoublyLinkedList* doubly_linked_list_initialize_with_value(int value);
void doubly_linked_list_destroy(struct DoublyLinkedList* list);
void doubly_linked_list_insert_prepend(struct DoublyLinkedList* list, int value);
void doubly_linked_list_insert_append(struct DoublyLinkedList* list, int value);
void doubly_linked_list_remove_head(struct DoublyLinkedList* list);
void doubly_linked_list_remove_tail(struct DoublyLinkedList* list);

#endif // DOUBLY_LINKED_LIST_H
