#include <stdio.h>

//programma che sostituisce una parola con un altra con lo stesso numero di lettere.
//con parola si intende serie di caratteri che sia inizia sia finisce con uno spazio!

int cerca_combinazioni_numero(char *src, int num, int* vettori_num);

int main()
{
	char str[255] = "bel2la la 12 vita 11 1 2345 22 111 1 1 12221 1 11 1";
	int vettori_num[3];
	int ret;
	
	ret = cerca_combinazioni_numero(str, 2, vettori_num);

}