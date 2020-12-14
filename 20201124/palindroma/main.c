#include<stdio.h>

int palindroma(char* str);

int main() {
	char str[255] = "anagramma";

	printf("la stringa è palindroma: %d", palindroma(str));
}