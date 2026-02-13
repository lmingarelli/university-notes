#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare_integers(const void *a, const void *b){
	const int *ap = a; 	
	const int *bp = b;
	if (ap[0] > bp[0]) return 1;
	else if (ap[0] < bp[0]) return -1;
	else return 0;	
}

int main() {
	int a[10];
	for (int i = 0; i < 10; i++){
		// With &15 we are going to limit the dimension of the int
		// returned by rand to 4 bit (1111 = 15)
		a[i] = rand() & 15; 		
	}	

	a[2] = INT_MAX;
	a[5] = INT_MIN;
	qsort(a, 10, sizeof(int), compare_integers);

	for (int i = 0; i < 10; i++){
		printf("%d " , a[i]);
	}

	printf("\n");
	return 0;
}
	
