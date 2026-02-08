#include <stdio.h>

int main() {
    char x = 2;     // 1 byte
    printf("Hello World %d\n", x); // x viene "promosso" a int da printf

    x = 'A';     // 1 byte
    // x viene sembre interpretato come un numero e viene 
    // "promosso" a int da printf
    printf("Hello World %d\n", x); 
    return 1;
}
