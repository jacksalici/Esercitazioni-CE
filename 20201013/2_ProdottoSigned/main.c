#include<stdio.h>



int main(void) {
	int a = -5, b = 7, c;
	__asm {
		mov eax, a
		mov ebx, b
 
		
		mov edx, 0 //contatore negativi, se nessuno o entrambi i fattori sono negativi non devo fare nulla, altrimenti dovrà negare il risultato
		cmp eax, 0
		jg A_Positivo //se A non è positivo ne calcolo il negato e incremento il contatore negativo
		neg eax
		inc edx

		A_Positivo:
		cmp ebx, 0
		jg B_Positivo //se B non è positivo ne calcolo il negato e incremento il contatore negativo
		neg ebx
		inc edx

		B_Positivo:

		mov ecx, 0 //ecx sarà il risultato del prodotto 
		ciclo:
		cmp ebx, 0
		je terminatore
		add ecx, eax
		dec ebx

		jmp ciclo

		terminatore: 
		
		cmp edx, 1 //regolo il segno del prodotto
		jne fine
		neg ecx
		fine: mov c, ecx
	}

	printf("il prodotto fra %d e %d risulta %d", a, b, c);
}