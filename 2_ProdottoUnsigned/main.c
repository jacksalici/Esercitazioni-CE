#include<stdio.h>



int main(void) {
	unsigned int a = 5, b = 7, c;
	__asm {
		mov eax,a
		mov ebx,b
		mov ecx,0
		inizio:
		cmp ebx, 0
		je fine
		add ecx, eax
		dec ebx
		jmp inizio
		fine: mov c,ecx
	}

	printf("il prodotto fra %d e %d risulta %d", a, b, c);
}