
#include <stdio.h>
#include "Note.h"
#include "List.h"
#include "Storage.h"


int main(void) {
    List* list = listCreate();
    if (list == NULL) {
        printf("CLINotes couldn't be initialized!\n");
        printf("terminating program\n");
        return 1;
    }
    retrieveNotes(list);
    printf("=== Simple Note-Taking CLI ===\n");
    while (1) {
        int selector = 0;
        printf("\n1. Add Note\n");
        printf("2. View Notes\n");
        printf("3. Delete Note\n");
        printf("4. Exit\n");
        printf("\nChoose an option: ");
        if (scanf("%d", &selector) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {};
        }
        switch (selector) {
            case 1:
                noteAdd(list);
                break;
            case 2:
                notesView(list);
                break;
            case 3:
                noteRemove(list);
                break;
            case 4:
                storeNotes(list);
                listDestroy(list);
                return 0;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
}
