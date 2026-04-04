#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct pls {
    long len;
    char str[21];
};

#define HEXDUMP_CHAR_PER_LINE 8
void hexdump(void *p, size_t len) {
    unsigned char *byte = p;
    size_t po = 0;
    for (size_t i = 0; i < len; i++) {
        printf("%02X ", byte[i]);
        if ((i+1) % HEXDUMP_CHAR_PER_LINE == 0 || i == len-1) {
            if (i == len-1) {
                int pad = HEXDUMP_CHAR_PER_LINE -
                    (len % HEXDUMP_CHAR_PER_LINE);
                pad %= HEXDUMP_CHAR_PER_LINE;

                for (int j = 0; j < pad; j++) printf("~~ ");
            }

            printf("\t");
            for (size_t j = po; j <= i; j++) {
                int c = isprint(byte[j]) ? byte[j] : '.';
                printf("%c", c);
            }

            printf("\n");
            po = i+1;
        }

    }
}

int main() {
    struct pls s;

    s.len = 10;
    memcpy(s.str, "1234567890", 11);
    printf("%p\n", &s);
    printf("%p\n", &s.str);

    printf("%d\n", sizeof(s));
    hexdump(&s, sizeof(s));
    return 0;
}
