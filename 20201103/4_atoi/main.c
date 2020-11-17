//conta atoi
#include<stdio.h>

_declspec(naked) unsigned int a2i(char *str) {
	__asm {
		push ebp
		mov ebp, esp
		push edi
		push esi
		push ebx


		mov edx, 10
		mov ecx, 0
		mov edi, 1 
		mov esi, 1 
		mov ebx, dword ptr[ebp + 8]
		STRLEN:
		cmp byte ptr[ebp, esi*4], 0
		je STRLEN_END
		inc esi
		jmp STRLEN

		STRLEN_END:
		
		cmp esi, 0
		je FINE
		mov eax, byte ptr[ebp, esi * 4]
		imul edi
			
		
		add acx, eax
		dec esi
							
		
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
	char v[255] = "123";

	printf("%d", a2i(v));

}