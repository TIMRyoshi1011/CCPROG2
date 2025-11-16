#include <stdio.h>
#include <string.h>

int main() {

    int n = 5;
    float f = 3.14;
    char c = 'W';
    char s[21] = "Hello";

    FILE *ptr;

    ptr = fopen("info.txt", "w");

    fprintf(ptr, "THE CONTENTS OF THIS FILE:\n");
    fprintf(ptr, "int: %d\n", n);
    fprintf(ptr, "float: %f\n", f);
    fprintf(ptr, "char: %c\n", c);
    fprintf(ptr, "string: %s\n", s);

    fclose(ptr);

    return 0;
}