#include <stdio.h>

int main() {
    int i = 0;
   
    // I while si possono scrivere come se fossimo in assembly usando il
    // comando goto e le etichette
    again:
    printf("%d\n", i);
    i++;
    if (i < 10) goto again;

    // Un altro modo è quello di usare un if con jump condizionale
    // ad etichetta
    i = 0;
    loop:
    if (i>=10) goto next;
        printf("%d\n", i);
        i++;
        goto loop;
    next:

    return 1;
}
