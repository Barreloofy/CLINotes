
#include "Storage.h"


int storeNotes(List* list) {
    FILE* file = NULL;
    Node* currentNode = NULL;
    if (list == NULL) { return ERROR; }
    file = fopen(FILENAME, "w");
    if (file == NULL) { return ERROR; }
    currentNode = list->head;
    while (currentNode != NULL) {
        if (fputs(currentNode->data, file) <= 0) {
            fclose(file);
            return ERROR;
        }
        if (fputc('\n', file) == EOF) {
            fclose(file);
            return ERROR;
        }
        currentNode = currentNode->next;
    }
    fclose(file);
    return SUCCESS;
}

int retrieveNotes(List* list) {
    FILE* file = NULL;
    char* buffer = NULL;
    char* bridge = NULL;
    Node* node = NULL;
    char character;
    int count;
    if (list == NULL) { return ERROR; }
    file = fopen(FILENAME, "r");
    if (file == NULL) { return ERROR; }
    buffer = malloc(sizeof(char));
    if (buffer == NULL) {
        fclose(file);
        return ERROR;
    }
    count = 0;
    while ((character = fgetc(file)) != EOF) {
        if (character != '\n') {
            buffer[count] = character;
            count++;
            bridge = realloc(buffer, sizeof(char) * (count));
            if (bridge == NULL) {
                free(buffer);
                fclose(file);
                return ERROR;
            }
            buffer = bridge;
        }
        else {
            buffer[count] = '\0';
            node = nodeCreate(buffer);
            if (node == NULL) {
                free(buffer);
                fclose(file);
                return ERROR;
            }
            if (listInsert(list, node) == ERROR) {
                free(buffer);
                free(node);
                fclose(file);
                return ERROR;
            }
            buffer = malloc(sizeof(char));
            if (buffer == NULL) {
                fclose(file);
                return ERROR;
            }
            count = 0;
        }
    }
    return SUCCESS;
}
