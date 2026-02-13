#include <stdio.h>
#include <string.h>
#include <limits.h>

struct foo {
	unsigned char a:4;
	unsigned char b:4;
	unsigned char c:4;
   	unsigned char d:8;	
};

int main() {
	struct foo f;

	f.a = 15;
	f.b = 16;
	f.c = 17;
	f.d = 200;
	printf("%d %d %d %d\n", f.a, f.b, f.c, f.d);
	return 0;
}
