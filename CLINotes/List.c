
#include "List.h"


Node* nodeCreate(char* data) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

int nodeDestroy(Node* node) {
    if (node == NULL) {
        return ERROR;
    }
    free(node->data);
    free(node);
    return SUCCESS;
}


List* listCreate(void) {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int listDestroy(List* list) {
    Node* currentNode = NULL;
    if (list == NULL) {
        return ERROR;
    }
    if (list->head == NULL) {
        free(list);
        return SUCCESS;
    }
    currentNode = list->head;
    while (currentNode != NULL) {
        Node* nodeToDestroy = currentNode;
        currentNode = currentNode->next;
        nodeDestroy(nodeToDestroy);
    }
    free(list);
    return SUCCESS;
}

int listInsert(List* list, Node* node) {
    if (list == NULL || node == NULL) {
        return ERROR;
    }
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = list->tail->next;
    }
    return SUCCESS;
}

int listRemove(List* list, int index) {
    Node* currentNode = NULL;
    int count;
    if (list == NULL || list->head == NULL) {
        return ERROR;
    }
    count = 0;
    currentNode = list->head;
    while (currentNode != NULL) {
        if (count != index - 1 && index != 0) {
            currentNode = currentNode->next;
            count++;
        } else {
            if (index == 0) {
                if (currentNode->next == NULL) {
                    list->head = NULL;
                    list->tail = NULL;
                } else {
                    list->head = currentNode->next;
                }
                if (nodeDestroy(currentNode) != SUCCESS) {
                    return ERROR;
                }
                return SUCCESS;
            } else if (currentNode->next != NULL) {
                Node* nodeToRemove = currentNode->next;
                if (nodeToRemove == list->tail) {
                    currentNode->next = NULL;
                    list->tail = currentNode;
                } else {
                    currentNode->next = nodeToRemove->next;
                }
                if (nodeDestroy(nodeToRemove) != SUCCESS) {
                    return ERROR;
                }
                return SUCCESS;
            }
        }
    }
    return SUCCESS;
}

Node* listPeek(List* list, int index) {
    Node* currentNode = NULL;
    int count;
    if (list == NULL || list->head == NULL) {
        return NULL;
    }
    count = 0;
    currentNode = list->head;
    while (currentNode != NULL) {
        if (count == index) {
            return currentNode;
        }
        currentNode = currentNode->next;
        count++;
    }
    return NULL;
}
