
#include "Storage.h"
#define FileName "DataNotes.txt"


int storeNotes(List* list) {
    FILE* file = NULL;
    Node* currentNode = NULL;
    if (list == NULL) { return 1; }
    file = fopen(FileName, "w");
    currentNode = list->head;
    while (currentNode != NULL) {
        if (fputs(currentNode->data, file) <= 0) { return 1; }
        if (fputc('\n', file) == -1) { return 1; }
        currentNode = currentNode->next;
    }
    fclose(file);
    return 0;
}

int retrieveNotes(List* list) {
    FILE* file = NULL;
    char* buffer = NULL;
    char* bridge = NULL;
    Node* node = NULL;
    char character;
    int count;
    if (list == NULL) { return 1; }
    file = fopen(FileName, "r");
    if (file == NULL) { return 1; }
    buffer = malloc(sizeof(char));
    if (buffer == NULL) { return 1; }
    count = 0;
    while ((character = fgetc(file)) != -1) {
        if (character != '\n') {
            buffer[count] = character;
            count++;
            bridge = realloc(buffer, sizeof(char) * (count));
            if (bridge == NULL) {
                free(buffer);
                fclose(file);
                return 1;
            }
            buffer = bridge;
        }
        else {
            buffer[count] = '\0';
            node = nodeCreate(buffer);
            if (node == NULL) {
                free(buffer);
                fclose(file);
                return 1;
            }
            if (listInsert(list, node) == 1) {
                free(buffer);
                free(node);
                fclose(file);
                return 1;
            }
            buffer = malloc(sizeof(char));
            if (buffer == NULL) {
                fclose(file);
                return 1;
            }
            count = 0;
        }
    }
    return 0;
}
