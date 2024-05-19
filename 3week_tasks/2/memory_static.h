#ifndef MEMORY_STATIC_H
#define MEMORY_STATIC_H

#include <stddef.h>

char* memory_static_func(char* lspStudyArr);
char* memory_static_free(char** gspStudyName);

extern char* gspStudyName;
extern char* lspStudyArr;

#endif
