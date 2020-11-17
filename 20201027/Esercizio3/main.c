#include<stdio.h>
//converti in maiuscolo
__declspec(naked) void convertimaiusc(char *p) {
	__asm {
		push ebp
		mov ebp, esp
		push edi
		push esi
		push ebx

		mov ebx, dword ptr[ebp + 8]

		mov esi, 0
		ciclo:
		cmp byte ptr[ebx + esi * 1], 0
			je fine
			cmp byte ptr[ebx + esi * 1], ' '
			je is_a_space
			mov cl, byte ptr[ebx + esi * 1]
			sub cl, 32
			mov byte ptr[ebx + esi * 1], cl
			is_a_space :
		inc esi
			jmp ciclo
			fine :
		pop ebx
			pop esi
			pop edi
			mov esp, ebp
			pop ebp
			ret
	}
}


int main()
{
	char str[255] = "la mamma di tua mamma tua nonna";
	convertimaiusc(str);
	printf("%s", str);
}