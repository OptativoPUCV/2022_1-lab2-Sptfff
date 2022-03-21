#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* listado = (List*) malloc(sizeof(List));

    listado->current = NULL;
    listado->tail = NULL;
    listado->head = NULL;

    return listado;
}

void * firstList(List * list) {
    list->current = list->head;
    if (!(list->current == NULL)){
        return list->current->data;
    }
    else return NULL;
    
}

void * nextList(List * list) {
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    
    while(list->current->next != NULL){

        list->current = list->current->next;
    }

    return list->current;
}

void * prevList(List * list) {
    list->current = list->current->prev;

    return list->current;
}

void pushFront(List * list, void * data) {
    Node *n = createNode(data);
    n->next = list->head;
    if(list->head){
        list->head->prev =  n;
    }
    list->head=n;
    n->prev = NULL;
    list->tail++;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node* n = createNode(data);
    n->next = list-> current;
    if(list->current){
        list->current->next = n;
    }
    list->current = n;
    n->next = NULL;
    list->tail++;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {  

    Node* aux = list->head;
    while(aux->next != list->current){
        aux = aux->next;
    }
    aux->next = list->current->next;
    free(list->current);
    list->current = list->head;

    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
