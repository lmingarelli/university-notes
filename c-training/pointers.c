#include <stdio.h>

void incr(int *p){
    // It uses the value of the variable pointed by p while writing
    // and reading
    *p = *p + 1;
}

int main() {
    // Showing variable shadowing and code block scopes
    int i = 8;
    {
        int i = 5;
        printf("i (%zu bytes) is stored at %p\n", sizeof(i), &i);
    }
    printf("i (%zu bytes) is stored at %p\n", sizeof(i), &i);
    printf("-----------------1-------------------\n");

    // Showing basic pointers behavior and why star should be written
    // near variable name and not near the type
    {
        int *y, x;
        x = 42;
        y = &x;
        printf("x (%zu bytes) has value: %d\n", sizeof(x), x);
        printf("y (%zu bytes), has value: %p (this is also the address of x)\n", sizeof(y), y);
        printf("y (%zu bytes), is stored at %p\n", sizeof(y), &y);
    }
    printf("-----------------2-------------------\n");

    // Showing the differences between using * in the variable declaration and
    //  using it in variable valorization.
    {
        int x = 5;
        int *y = NULL;
        printf("x was %d\n", x);
        y = &x;
        printf("x is stored at the address %p\n", y);
        *y = 10; // Changing the variable POINTED by y
        printf("x is now %d\n", x);        
        incr(y);
        printf("x is now %d\n", x);
        incr(&x);
        printf("x is now %d\n", x);
    }
    printf("-----------------3-------------------\n");

    // Arrays are pointers in C. Showing also that printf knows that a string
    // variable is also a pointer, and using the same writing (but different
    // format) we specify two different things. In this case, the memory
    // address where mystr starts, and the whole string value.
    {
        char mystr[] = "Hello World";
        char *p = mystr;
        printf("At %p I can see: %s\n", mystr, mystr);
        // We can use a pointer as an array
        printf("p[0], p[1], p[2] = %c%c%c\n", p[0], p[1], p[2]);
        // Or we can use pointers mathematics
        printf("*p, *(p+1), *(p+2) = %c%c%c\n", *p, *(p+1), *(p+2));
    }
    printf("-----------------4-------------------\n");

    // Showing that the ++ operator change its shift based on the pointer type
    {
        char mystr[] = "AABBCCDDEEFF";
        // Using short we are telling C that the info in memory have a
        // dimension of 2 byte (instead of 1 for char)
        short *p = (short *) mystr;
        // Here it prints 16705 because bytes are in base 256 (because
        // they have 8 bit and 2^8=256, so each position
        // is n x 256^posizione). So in this case is
        // (65 x 256^1) + (65 x 256^0)
        printf("*p = %d\n", *p);
        printf("p[1] = %d\n", p[1]);
        p++;
        // Here it doesn't print (65 x 256^1) + (66 x 256^0)
        // but (66 x 256^1) + (66 x 256^0) because ++ understand
        // the pointer type and shift by its dimension.
        // So in this case a short* will shift by 2 bytes = sizeof(short)
        printf("*p++ = %d\n", *p);
    }
    printf("-----------------5-------------------\n");

    // Showing how to cycle a string with an intelligent condition
    {
        char str[] = "Hello0000123";
        char *p = str;
        while(*p) {
            printf("%c", *p);
            p++;
        }
        printf("\n");
    }

    return 1;
}
