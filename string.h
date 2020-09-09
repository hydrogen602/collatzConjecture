#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * All internal funcs or variables should start with __str_
 * All methods should start with str_
 * 
*/
char * __str_nullstring = "";

typedef struct STRING_STRUCT {
    char * __ptr;
    size_t __memLength;
} String;

String buildStringNull() {
    String s = { NULL, 0 };
    return s;
}

String buildString(char * st) {
    String s = { NULL, 0 };

    s.__memLength = strlen(st) + 1;
    s.__ptr = calloc(s.__memLength, 1);
    if (s.__ptr == NULL) {
        fprintf(stderr, "Could not allocate memory");
        exit(1);
    }
    strcpy(s.__ptr, st);
    return s;
}

void str_free(String * self) {
    if (self->__ptr != NULL) {
        free(self->__ptr);
        self->__ptr = NULL;
        self->__memLength = 0;
    }
}

char * str_getString(String * self) {
    if (self->__ptr == NULL) {
        return __str_nullstring;
    }
    else {
        return self->__ptr;
    }
}

size_t str_getLen(String * self) {
    if (self->__ptr == NULL) {
        return 0;
    }
    else {
        return strlen(self->__ptr);
    }
}

String str_concat(String * self, String * other) {
    size_t newLen = str_getLen(self) + str_getLen(other) + 1;
    String s = {
        calloc(newLen, 1),
        newLen
    };
    if (s.__ptr == NULL) {
        fprintf(stderr, "Could not allocate memory");
        exit(1);
    }

    strcpy(s.__ptr, self->__ptr);
    strcat(s.__ptr, other->__ptr);
    return s;
}

