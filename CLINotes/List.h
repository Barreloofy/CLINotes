
#include <stdlib.h>
#include <stdio.h>

#ifndef LIST_H
#define LIST_H

#define ERROR 1
#define SUCCESS 0
typedef struct Node {
    char* data;
    struct Node* next;
} Node;
Node* nodeCreate(char*);
int nodeDestroy(Node*);

typedef struct List {
    Node* head;
    Node* tail;
} List;
List* listCreate(void);
int listDestroy(List*);
int listInsert(List*, Node*);
int listRemove(List*, int);
Node* listPeek(List*, int);

#endif
