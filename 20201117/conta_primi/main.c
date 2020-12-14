#include<stdio.h>

int primo(int *a, int*b, int lunghezza);

/*si realizzi una funziona che imette in b[i] 1 se a[i] è primo,
0 altrimenti. La funzione ritorna quanti numeri primi ci sono nel vettore a.*/

int main() {
	int a[10] = { 3,4,5,6,7,8,9,10,11,12 };
	int b[11] = { 0,0,0,0,0,0,0,0,0,0 };
	printf("%d", primo(a, b, 10));
}

