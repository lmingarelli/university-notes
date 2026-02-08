// PREFIXED LENGTH STRING (PLS)

#include <stdio.h>
#include <stdlib.h>

char *pls_create(char *init, int len) {
    char *s = malloc(1+len+1);
    unsigned char *lenptr = (unsigned char*) s;
    *lenptr = len;
    for (int i = 0; i < len; i++) {
        s[i+1] = init[i];
    }
    s[len+1] = 0;
    return s;
}

void pls_print (char *s) {
    unsigned char *lenptr = (unsigned char*) s;
    for (int i = 0; i < *lenptr; i++) {
        putchar(s[i+1]);
    }
    printf("\n");
}

int main () {
    char *mystr = pls_create("Pippo pluto 123!", 16);
    pls_print(mystr);
}
