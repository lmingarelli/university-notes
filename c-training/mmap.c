#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
	int fd = open("mmap.c", O_RDONLY);
	printf("Open file descriptor: %d\n", fd);
	void *mem = mmap(NULL, 100, PROT_READ, MAP_SHARED, fd, 0);
	printf("File mapped at %p\n", mem);
	char *s = mem;
	for (int i=0; i < 10; i++) {
		printf("s[%d] = %c\n", i, s[i]);
	}
	return 0;
}
