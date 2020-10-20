#include<stdio.h>


int main()
{
	int a;
	int b;

	a = 5;
	b = 7;

	__asm {
		mov eax, a
		mov ebx, b

		add eax, ebx


		mov b,eax

	}
	printf("%d", b);
}