#include <ccore/data_structure/list/doubly_linked_list.h>
#include <stdlib.h>

// [TODO]: Find better ways to alert the user of malloc failures

struct DoublyLinkedListNode* doubly_linked_list_node_initialize(int value)
{
    struct DoublyLinkedListNode* node = (struct DoublyLinkedListNode*)malloc(sizeof(struct DoublyLinkedListNode));
    if (node == NULL)
        return NULL; // malloc failure

    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void doubly_linked_list_node_destroy(struct DoublyLinkedListNode* node)
{
    node->next = NULL;
    node->prev = NULL;
    free(node);
}

struct DoublyLinkedList* doubly_linked_list_initialize(void)
{
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));
    if (list == NULL)
        return NULL; // malloc failure

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

struct DoublyLinkedList* doubly_linked_list_initialize_with_value(int value)
{

    struct DoublyLinkedList* list = doubly_linked_list_initialize();
    if (list == NULL)
        return NULL; // malloc failure

    struct DoublyLinkedListNode* root = doubly_linked_list_node_initialize(value);
    if (root == NULL)
        return NULL; // malloc failure

    list->head = root;
    list->tail = root;
    list->size = 1;
    return list;
}

void doubly_linked_list_destroy(struct DoublyLinkedList *list)
{
    if (list == NULL)
        return;

    struct DoublyLinkedListNode* curr = list->head;
    struct DoublyLinkedListNode* next_node;
    while (curr != NULL) {
        next_node = curr->next;
        curr->next = NULL;
        curr->prev = NULL;
        free(curr);
        curr = next_node;
    }
    list->head = NULL;
    list->tail = NULL;
    free(list);
}

void doubly_linked_list_prepend(struct DoublyLinkedList *list, int value)
{
    if (list == NULL) {
        list = doubly_linked_list_initialize_with_value(value);
        return; // could be final answer, or malloc failure
    }

    struct DoublyLinkedListNode* new_node = doubly_linked_list_node_initialize(value);
    if (new_node == NULL)
        return; // malloc failure
    
    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size = 1;
        return;
    }

    list->size += 1;

    new_node->next = list->head;
    list->head->prev = new_node;
    list->head = new_node;
}

void doubly_linked_list_append(struct DoublyLinkedList *list, int value)
{
    if (list == NULL) {
        list = doubly_linked_list_initialize_with_value(value);
        return; // could be final answer, or malloc failure
    }

    struct DoublyLinkedListNode* new_node = doubly_linked_list_node_initialize(value);
    if (new_node == NULL)
        return; // malloc failure

    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size = 1;
        return;
    }

    list->size += 1;

    list->tail->next = new_node;
    new_node->prev = list->tail;
    list->tail = new_node;
}

void doubly_linked_list_remove_head(struct DoublyLinkedList* list)
{
    if (list == NULL)
        return;

    if (list->size == 0)
        return;

    list->size -= 1;

    struct DoublyLinkedListNode* to_remove = list->head;
    list->head = list->head->next;

    to_remove->next = NULL;
    to_remove->prev = NULL;
    free(to_remove);
}

void doubly_linked_list_remove_tail(struct DoublyLinkedList* list)
{
    if (list == NULL)
        return;

    if (list->size == 0)
        return;

    if (list->head == list->tail) {
        free(list->head);
        return;
    }

    list->size -= 1;

    struct DoublyLinkedListNode* to_remove = list->tail;
    list->tail = to_remove->prev;
    list->tail->next = NULL;
    to_remove->prev = NULL;
    free(to_remove);
}
