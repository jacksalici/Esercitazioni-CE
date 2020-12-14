#include<stdio.h>

//int palindroma(char* str);
int conta_occorrenze(char* str, char* parola);
//non ne mai ne la prima ne l'ultima, parole sempre divise con lo spazio

int main() {
	//char str[255] = "ammagamma";
	char str2[255] = " cacca cacca cacca cacca ";
	char parola[256] = "cacca";
	//printf("la stringa è palindroma: %d", palindroma(str));
	printf("il numero di occorrenze è %d", conta_occorrenze(str2, parola));
}