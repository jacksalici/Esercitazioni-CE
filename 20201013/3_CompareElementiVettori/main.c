#include<stdio.h>

int main() {
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 1,-10,128, -5,4 };
	int c[5] = { 0 };

	int* p1, p2, p3;
	p1 = &a[0];
	p2 = &b[0];
	p3 = &c[0];


	//assignment: if a[i]>=b[i] then c[i]=1
	__asm {
		mov eax, p1 //vettore a
		mov ebx, p2 //vettore b
		mov ecx, p3 // vettore c
		mov edx, 0

		mov esi, 0
			
		loop_s:
		cmp esi, 5
		jnl loop_end
		mov edx, dword ptr[ebx + esi * 4]
		cmp dword ptr[eax + esi * 4], edx
		jng minor
		mov dword ptr[ecx + esi * 4], 1
		minor:
		inc esi
		jmp loop_s

		loop_end:
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d %d %d \n", a[i], b[i], c[i]);
	}
}