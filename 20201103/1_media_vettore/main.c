//media intera
#include<stdio.h>

_declspec(naked) int media(int* v, int lunghezza) {
	__asm {
		push ebp
		mov ebp, esp
		push edi
		push esi
		push ebx
		
		mov ebx, dword ptr [ebp + 8]

		mov esi, dword ptr [ebp + 12]
		
		mov ecx, 0
		mov eax, 0
		INIZIO_SOMMATORIA:
		cmp ecx, esi
		je SOMMA_TERMINATA
		add eax, dword ptr[ebx + ecx*4]
		inc ecx
		jmp INIZIO_SOMMATORIA
		

		SOMMA_TERMINATA:
		cdq
		idiv esi
		
		
		
		pop ebx
		pop esi
		pop edi
		mov esp, ebp
		pop ebp
		ret
	}
}

int main() {
	int v[10]={1,2,3,4,5,6,7,8,9,10};

	printf("la media e' %d ", media(v, 10));

}