//somma di un vettore int
__declspec(naked) int sommavet(int *p, int l) {
	__asm {
push ebp
mov ebp, esp
push edi
push esi	
push ebx

mov ecx, dword ptr[ebp+8]
mov ecx, dword ptr[ebp + 12]
mov eax, 0
mov esi, 0

ciclo:
cmp esi, ebx
je fine
add eax, dword ptro [ecx+esi*4]
inc esi
jmp ciclo

fine:
pop ebx
pop esi
pop edi
mov esp, ebp
pop edp
ret
	}
}


int main()
{
	int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

}