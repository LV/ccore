#include <ccore/data_structure/list/singly_linked_list.h>
#include <stdlib.h>

// [TODO]: Find better ways to alert the user of malloc failures

struct SinglyLinkedListNode* singly_linked_list_node_initialize(int value)
{
    struct SinglyLinkedListNode* node = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
    if (node == NULL)
        return NULL; // malloc failure

    node->data = value;
    node->next = NULL;
    return node;
}

void singly_linked_list_node_destroy(struct SinglyLinkedListNode* node)
{
    node->next = NULL;
    free(node);
}

struct SinglyLinkedList* singly_linked_list_initialize(void)
{
    struct SinglyLinkedList* list = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
    if (list == NULL)
        return NULL; // malloc failure

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

struct SinglyLinkedList* singly_linked_list_initialize_with_value(int value)
{

    struct SinglyLinkedList* list = singly_linked_list_initialize();
    if (list == NULL)
        return NULL; // malloc failure

    struct SinglyLinkedListNode* root = singly_linked_list_node_initialize(value);
    if (root == NULL) {
        free(list);
        return NULL; // malloc failure
    }

    list->head = root;
    list->tail = root;
    list->size = 1;
    return list;
}

void singly_linked_list_destroy(struct SinglyLinkedList *list)
{
    if (list == NULL)
        return;

    struct SinglyLinkedListNode* curr = list->head;
    struct SinglyLinkedListNode* next_node;
    while (curr != NULL) {
        next_node = curr->next;
        curr->next = NULL;
        free(curr);
        curr = next_node;
    }
    list->head = NULL;
    list->tail = NULL;
    free(list);
}

void singly_linked_list_prepend(struct SinglyLinkedList *list, int value)
{
    if (list == NULL) {
        list = singly_linked_list_initialize_with_value(value);
        return; // could be final answer, or malloc failure
    }

    struct SinglyLinkedListNode* new_node = singly_linked_list_node_initialize(value);
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
    list->head = new_node;
}

void singly_linked_list_append(struct SinglyLinkedList *list, int value)
{
    if (list == NULL) {
        list = singly_linked_list_initialize_with_value(value);
        return; // could be final answer, or malloc failure
    }

    struct SinglyLinkedListNode* new_node = singly_linked_list_node_initialize(value);
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
    list->tail = new_node;
}

void singly_linked_list_remove_head(struct SinglyLinkedList* list)
{
    if (list == NULL)
        return;

    if (list->size == 0)
        return;

    list->size -= 1;

    struct SinglyLinkedListNode* to_remove = list->head;
    list->head = list->head->next;

    to_remove->next = NULL;
    free(to_remove);
}

void singly_linked_list_remove_tail(struct SinglyLinkedList* list)
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

    struct SinglyLinkedListNode* to_remove = list->tail;
    struct SinglyLinkedListNode* iter = list->head;
    while(iter->next != to_remove)
        iter = iter->next;

    list->tail = iter;
    free(to_remove);
}
