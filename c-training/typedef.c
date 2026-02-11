#include <stdio.h>

typedef struct {
    int n;
    int d;
} fract;

/* We declare a type fractptr as a pointer of type fract */
typedef fract *fractptr;

int main() {
    fract f;
    /* We do not have to specify that is a pointer with *fp */
    fractptr fp = &f;
    f.n = 10;
    f.d = 20;
    printf("%d/%d\n", f.n, f.d);
    printf("%d/%d\n", fp->n, fp->d);
}
