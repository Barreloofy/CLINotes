
#include "Note.h"
#include "List.h"


void noteAdd(List* list) {
    char* buffer = NULL;
    char* bridge = NULL;
    char character;
    int count;
    if (list == NULL) { return; }
    buffer = malloc(sizeof(char));
    if (buffer == NULL) { return; }
    count = 0;
    printf("Enter your note: ");
    getchar();
    while ((character = getchar()) != '\n') {
        buffer[count] = character;
        count++;
        bridge = realloc(buffer, sizeof(char)* count);
        if (bridge == NULL) {
            free(buffer);
            return;
        }
        buffer = bridge;
    }
    buffer[count] = '\0';
    if (listInsert(list, nodeCreate(buffer)) != 0) {
        printf("Failed to add note\n");
        free(buffer);
        return;
    }
    printf("Note added successfully!\n");
}

int notesView(List* list) {
    Node* currentNode = NULL;
    int count;
    if (list == NULL) {
        return 1;
    }
    if (list->head == NULL) {
        printf("No notes yet!\n");
        return 1;
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
    return 0;
}

int noteRemove(List* list) {
    int selector;
    if (list == NULL) { return 1; }
    if (notesView(list) != 0) { return 1; }
    printf("Note to remove, Nr: ");
    while (1) {
        if (scanf("%d", &selector) == 1) { break; }
        while (getchar() != '\0') { continue; }
    }
    selector = (selector == 0 ? 0 : selector - 1);
    if (listRemove(list, selector) != 0) {
        printf("Something went wrong\n");
        return 1;
    }
    printf("Note removed successfully!\n");
    return 0;
}
