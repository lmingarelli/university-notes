#include <stdio.h>

int main() {
    FILE *fp = fopen("stdio1.c", "r");
    if (fp == NULL){
        printf("Unable to open the file\n");
        return 1;
    }
    char buf[32];
    size_t nread;
    while (1) {
        nread = fread(buf, 1, sizeof(buf), fp);
        if (nread == 0) return 0;
        for (size_t i = 0; i < nread; i++) {
            printf("%c", buf[i]);
        }
    }
    fclose(fp);
}
