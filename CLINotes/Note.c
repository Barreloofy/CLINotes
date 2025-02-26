
#include "Note.h"
#include "List.h"


int noteAdd(List* list) {
    char* buffer = NULL;
    char* bridge = NULL;
    char character;
    int count;
    if (list == NULL) { return ERROR; }
    buffer = malloc(sizeof(char));
    if (buffer == NULL) { return ERROR; }
    count = 0;
    printf("Enter your note: ");
    getchar();
    while ((character = getchar()) != '\n') {
        buffer[count] = character;
        count++;
        bridge = realloc(buffer, sizeof(char)* count);
        if (bridge == NULL) {
            free(buffer);
            return ERROR;
        }
        buffer = bridge;
    }
    buffer[count] = '\0';
    if (listInsert(list, nodeCreate(buffer)) != SUCCESS) {
        printf("Failed to add note\n");
        free(buffer);
        return ERROR;
    }
    printf("Note added successfully!\n");
    return SUCCESS;
}

int notesView(List* list) {
    Node* currentNode = NULL;
    int count;
    if (list == NULL) {
        return ERROR;
    }
    if (list->head == NULL) {
        printf("No notes yet!\n");
        return ERROR;
    }
    printf("\n=== Notes ===\n\n");
    currentNode = list->head;
    count = 1;
    while (currentNode != NULL) {
        printf("%d: %s\n", count, currentNode->data);
        count++;
        currentNode = currentNode->next;
    }
    printf("\n=== Notes ===\n");
    return SUCCESS;
}

int noteRemove(List* list) {
    int selector;
    if (list == NULL) { return ERROR; }
    if (notesView(list) != SUCCESS) { return ERROR; }
    printf("Note to remove, Nr: ");
    while (1) {
        if (scanf("%d", &selector) == 1) { break; }
        while (getchar() != '\0') { continue; }
    }
    selector = (selector == 0 ? 0 : selector - 1);
    if (listRemove(list, selector) != 0) {
        printf("Something went wrong\n");
        return ERROR;
    }
    printf("Note removed successfully!\n");
    return SUCCESS;
}
