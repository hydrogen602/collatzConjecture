#include <stdio.h>
#include <stdlib.h>

int lineNum = 0;

void throw_error(char * err, char * cause) {
    if (lineNum > 0) {
        fprintf(stderr, "ERROR: Line %d: %s: %s\n", lineNum, err, cause);
    }
    else {
        fprintf(stderr, "ERROR: %s: %s\n", err, cause);
    }

    exit(EXIT_FAILURE);
}

void set_line_num(int n) {
    lineNum = n;
}