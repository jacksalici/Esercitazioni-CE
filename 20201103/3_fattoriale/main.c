//conta pari
#include<stdio.h>

_declspec(naked) int fatt(int f) {
	__asm {
		push ebp
		mov ebp, esp
		push edi
		push esi
		push ebx
		
		mov ebx, dword ptr[ebp + 8]
		mov esi, 1
		mov eax, 1
		INIZIO:
		cmp esi, ebx
		je FINE
		cdq
		imul ebx
		dec ebx
		JMP INIZIO

		FINE :
		pop ebx
		pop esi
		pop edi
		mov esp, ebp
		pop ebp
		ret
	}
}

int main() {
	int f = 4;

	printf("il fattoriale e' %d ", fatt(f));

}