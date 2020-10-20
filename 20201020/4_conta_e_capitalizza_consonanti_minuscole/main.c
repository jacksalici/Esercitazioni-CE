#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char str[255] = "Prova";
	int num = 0;

	char *p;
	p = &str[0];

	//conta consonanti minuscole nella stringa
	__asm {
		mov eax, p
		mov esi, 0
		mov ecx, 0

		ciclo:
		mov bl, byte ptr[eax + esi * 1]

			cmp bl, 0
			je fine

			cmp bl, 97
			jl impostor
			cmp bl, 122
			jg impostor
			cmp bl, 'a'
			je impostor
			cmp bl, 'e'
			je impostor
			cmp bl, 'i'
			je impostor
			cmp bl, 'o'
			je impostor
			cmp bl, 'u'
			je impostor

			sub bl, 20h
			mov byte ptr[eax + esi * 1], bl


			inc esi
			jmp ciclo

			impostor : inc ecx
			inc esi
			jmp ciclo


			fine :
		sub esi, ecx
			mov num, esi
	}

	printf("il numero di vocali minuscole e' %d. Stringa capitalizzata: %s", num, str);

}