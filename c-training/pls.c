// PREFIXED LENGTH STRING (PLS)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct pls {
    uint32_t len;
    uint32_t refcount;
    char str[];
};

char *pls_create(char *init, int len) {
    struct pls *p = malloc(sizeof(struct pls) + len + 1);
    p->len = len;
    p->refcount = 1;

    for (int i=0; i < len; i++) {
        p->str[i] = init[i];
    }
    p->str[len] = 0;
    return p->str;
}

/* Display the string 's' on the screen. */
void pls_print (char *s) {
    struct pls *p = s - sizeof(*p);
    for (int i=0; i < p->len; i++) {
        putchar(p->str[i]);
    }
    printf("\n");
}

void pls_free(char *s) {
    free(s-sizeof(struct pls));
}

void pls_release(char *s) {
    struct pls *p = s - sizeof(*p);
    if (p->refcount == 0) {
        printf("ABORTED ON FREE ERROR");
        exit(1);
    }

    p->refcount--;
    if (p->refcount == 0) pls_free(s);
}

int pls_len(char *s) {
    struct pls *p = s - sizeof(*p);
    return p->len;
}

int main () {
    char *mystr = pls_create("Pippo pluto 123!", 16);
    pls_print(mystr);
    printf("My string lenght = %d\n", pls_len(mystr));
    pls_free(mystr);
}
