//somma di un vettore char
__declspec(naked) char sommavet(char *p, int l) {
	__asm {
		push ebp
		mov ebp, esp
		push edi
		push esi
		push ebx

		mov ecx, dword ptr[ebp + 8]
		mov ebx, dword ptr[ebp + 12]
		mov eax, 0
		mov esi, 0

		ciclo:
		cmp esi, ebx
			je fine
			add al, dword ptr[ecx + esi * 4]
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
	char vet[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char *p = &vet[0];
	int	c= sommavet(p, 10);
}