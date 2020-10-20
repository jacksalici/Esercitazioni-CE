#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char str[255] = "Prova";
	int num = 0;

	char *p;
	p = &str[0];

	//conta vocali nella stringa
	__asm {
		mov eax, p
		mov esi, 0
		mov ecx, 0

		ciclo:
		mov bl, byte ptr[eax + esi * 1]
		cmp bl, 'a'
		je trovata_vocale
		cmp bl, 'e'
		je trovata_vocale
		cmp bl, 'i'
		je trovata_vocale
		cmp bl, 'o'
		je trovata_vocale
		cmp bl, 'u'
		je trovata_vocale
		cmp bl, 'A'
		je trovata_vocale
		cmp bl, 'E'
		je trovata_vocale
		cmp bl, 'I'
		je trovata_vocale
		cmp bl, 'E'
		je trovata_vocale		
		cmp bl, 'U'
		je trovata_vocale
		cmp bl, 0
		je fine
		inc esi
		jmp ciclo
		trovata_vocale: inc ecx
		inc esi
		jmp ciclo
						
		fine:
		mov num, ecx
	}

	printf("il numero di vocali e' %d", num);

}