
#ifndef STORAGE_H
#define STORAGE_H

#include <stdlib.h>
#include <stdio.h>
#include "List.h"

#define FILENAME "DataNotes.txt"
#define ERROR 1
#define SUCCESS 0
int storeNotes(List*);
int retrieveNotes(List*);

#endif
