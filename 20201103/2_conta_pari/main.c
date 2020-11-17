//conta pari
#include<stdio.h>

_declspec(naked) int media(int* v, int lunghezza) {
	__asm {
		push ebp
		mov ebp, esp
		push edi
		push esi
		push ebx

		mov ebx, dword ptr[ebp + 8]
		mov esi, 0
		mov edi, 2
		mov eax, 0
		mov ecx, 0
		INIZIO_SOMMATORIA:
		cmp esi, dword ptr[ebp + 12]
		je FINE
		mov eax, dword ptr[ebx + esi * 4]
		inc esi

		cdq
		idiv edi
		cmp edx, 0
		jne INIZIO_SOMMATORIA
		inc ecx
		jmp INIZIO_SOMMATORIA


		FINE :
		mov eax, ecx
		pop ebx
		pop esi
		pop edi
		mov esp, ebp
		pop ebp
		ret
	}
}

int main() {
	int v[10] = { 1,2,3,4,5,6,7,8,9,11 };

	printf("il numero di pari e' %d ", media(v, 10));

}