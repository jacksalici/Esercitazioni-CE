#include <stdio.h>

//programma che sostituisce una parola con un altra con lo stesso numero di lettere.
//con parola si intende serie di caratteri che sia inizia sia finisce con uno spazio!

void sost_parola(char *src, char * wrd_wrong, char * wrd);

int main()
{
	char frase[100] = "se fossimo cugini mia mamma mamma sarebbe la tua mamma ";
	char parola_sbagliata[50] = "mamma";
	char parola_nuova[50] = "nonna";
	
	sost_parola(frase, parola_sbagliata, parola_nuova);

	printf("%s", frase);

	getchar();
}