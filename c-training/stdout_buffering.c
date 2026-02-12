#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    // It will empty the putchar buffer only after the sleep.
    {
        char *str = "Hello World";
        size_t len = strlen(str);
        printf("%d\n", (int) len);
        for (size_t i = 0; i < len; i++) {
            putchar(str[i]);
        }
        sleep(5);
    }




    return 0;
}
