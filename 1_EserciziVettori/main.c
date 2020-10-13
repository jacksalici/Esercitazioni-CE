#include<stdio.h>

/*
int main()
{
	int *p;
	int somma=0 ;
	int vet[5] = { 1,2,3,4,5 };
	p = &vet[0]; //4byte perchè architettura 4bit

	

	__asm {
		//leggo gli elementi di posizione 0 e 4 del vettore e li sommo
		//inidirizzamento tramite base + indice*scala
		mov ebx, p
				
		mov ecx, dword ptr[ebx]

		mov esi, 4
		add ecx, dword ptr [ebx+esi*4]
		mov somma, ecx

	}
	printf("%d", somma);
}
*/

int main() {
	char vet[11] = "margherita";
	char *p = &vet[0];

	//sovrascrivi m di margherita con M, a con A

	__asm {
		mov ebx, p
		mov esi, 0
		mov al, byte ptr[ebx + esi]
		sub al, 32
		mov byte ptr[ebx + esi], al
		add esi, 9
		mov al, byte ptr[ebx + esi]
		sub al, 32
		mov byte ptr[ebx + esi], al

	}

	printf("%s", vet);


}
