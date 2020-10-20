#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char str[255] = "Ingegneria Informatica fa schifo ma si diventa ricchi";
	int num = 0;
	
	char *p;
	p = &str[0];

	//conta caratteri
	__asm{
		mov eax, p

		mov esi, 0

		ciclo:
		mov bl,byte ptr [eax + esi*1]
		cmp bl,0
		je fine

		inc esi
		jmp ciclo

		fine:
		inc esi
		mov num, esi
	}

	printf("la lunghezza e' %d", num);

}