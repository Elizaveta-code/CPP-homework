#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static Node* create_node(int value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// 1
List init(size_t n)
{
    List list = {NULL, NULL, 0};
    for (size_t i = 0; i < n; i++)
    {
        push_back(&list, 0);
    }
    return list;
}

// 2
void print(const List* pl)
{
    if (pl == NULL)
        return;
    Node* current = pl->head;
    while (current != NULL)
    {
        printf("%i", current->value);
        if (current->next != NULL)
            printf(" ");
        current = current->next;
    }
    printf("\n");
}

// 3
void push_back(List* pl, int value)
{
    Node* new_node = create_node(value);
    if (pl->size == 0)
    {
        pl->head = new_node;
        pl->tail = new_node;
    }
    else
    {
        pl->tail->next = new_node;
        new_node->prev = pl->tail;
        pl->tail = new_node;
    }
    pl->size++;
}

// 4
int pop_back(List* pl)
{    
    Node* last_node = pl->tail;
    int value = last_node->value;
    if (pl->size == 1)
    {
        pl->head = NULL;
        pl->tail = NULL;
    }
    else
    {
        pl->tail = last_node->prev;
        pl->tail->next = NULL;
    }
    free(last_node);
    pl->size--;
    return value;
}

// 5
void push_front(List* pl, int value)
{
    if (pl == NULL)
        return;
    Node* new_node = create_node(value);
    if (pl->size == 0)
    {
        pl->head = new_node;
        pl->tail = new_node;
    }
    else
    {
        new_node->next = pl->head;
        pl->head->prev = new_node;
        pl->head = new_node;
    }
    pl->size++;
}

// 6
int pop_front(List* pl)
{
    if (pl == NULL || pl->size == 0)
    {
        fprintf(stderr, "Error: empty list\n");
        exit(1);
    }
    Node* first_node = pl->head;
    int value = first_node->value;
    if (pl->size == 1)
    {
        pl->head = NULL;
        pl->tail = NULL;
    }
    else
    {
        pl->head = first_node->next;
        pl->head->prev = NULL;
    }
    free(first_node);
    pl->size--;
    return value;
}

// 7
Node* erase(List* pl, Node* p)
{
    if (pl == NULL || p == NULL || pl->size == 0)
        return NULL;
    Node* next_node = p->next;
    if (p == pl->head && p == pl->tail)
    {
        pl->head = NULL;
        pl->tail = NULL;
    }
    else if (p == pl->head)
    {
        pl->head = p->next;
        pl->head->prev = NULL;
    }
    else if (p == pl->tail)
    {
        pl->tail = p->prev;
        pl->tail->next = NULL;
        next_node = NULL;
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    free(p);
    pl->size--;
    return next_node;
}

// 8
void splice(List* plist, Node* p, List* pother)
{
    if (plist == NULL || pother == NULL || pother->size == 0)
        return;
    if (plist->size == 0)
    {
        plist->head = pother->head;
        plist->tail = pother->tail;
    }
    else if (p == plist->head)
    {
        pother->tail->next = plist->head;
        plist->head->prev = pother->tail;
        plist->head = pother->head;
    }
    else if (p == NULL)
    {
        plist->tail->next = pother->head;
        pother->head->prev = plist->tail;
        plist->tail = pother->tail;
    }
    else
    {
        Node* prev_node = p->prev;
        prev_node->next = pother->head;
        pother->head->prev = prev_node;
        pother->tail->next = p;
        p->prev = pother->tail;
    }
    plist->size += pother->size;
    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

// 9
void destroy(List* pl)
{
    if (pl == NULL)
        return;
    Node* current = pl->head;
    while (current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

// 10
void advance(Node** pp, size_t n)
{
    if (pp == NULL || *pp == NULL)
        return;
    Node* current = *pp;
    for (size_t i = 0; i < n && current != NULL; i++)
    {
        current = current->next;
    }
    *pp = current;
}