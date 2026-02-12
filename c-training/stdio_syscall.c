#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    // Using system call
    int fd = open("stdio_libfunc.c", O_RDONLY);
    if (fd == -1) {
        printf("Error number is %d (ENOENT error is equal %d)\n", errno, ENOENT);
        perror("Unable to open the file");
        return 1;
    }

    char buf[32];
    ssize_t nread;
    while (1) {
        nread = read(fd, buf, sizeof(buf));
        if (nread == -1) {
            perror("Reading file");
            return 0;
        }
        // File has no more lines
        if (nread == 0) break;

        for (ssize_t i = 0; i < nread; i++) {
            printf("%c", buf[i]);
        }
    }

    close(fd);
    return 0;
}
