#include <stdio.h>

//programma che sostituisce una parola con un altra con lo stesso numero di lettere.
//con parola si intende serie di caratteri che sia inizia sia finisce con uno spazio!

int cerca_combinazioni_numero(int *src, int num, int *media);

int main()
{
	int src[6] = {1, 2, 3, 4, 5, 6};
	int media = 0;
	int *pm = &media;
	int ret;
	
	ret = cerca_combinazioni_numero(src, 6, pm);
	printf("%d", media);
}