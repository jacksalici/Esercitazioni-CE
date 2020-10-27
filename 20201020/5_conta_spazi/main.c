#include<stdio.h>

int main(void) {

	char str[] = " Ingegneria    informatica  fa schifo ";
	char *p = str;
	int spazi;
	__asm {

		MOV EAX, p
		MOV ESI, 0	//FLAG CICLO 
		MOV EBX, 0 //CONTASPAZI
		MOV EDX, 0 //EDX INIZIALMENTE VALE 0 E CRESCE PER OGNI VALORE DIVERSO SE ' '. DOPO OGNI PRIMO SPAZIO DOPO DEL TESTO TORNA A 0. SE EDX E' DIVERSO DA 0 E C'E' UNO SPAZIO ALLORA E' IL PRIMO DOPO UNA PAROLA E QUIDNI POSSO CONTARE UNA PAROLA.


		INIZIO_CICLO:
		CMP  BYTE PTR[EAX + ESI * 1], 0
			JE FINE

			CMP BYTE PTR[EAX + ESI * 1], ' '
			JNE NOT_A_SPACE
			CMP EDX, 0
			JE CONTINUE
			INC EBX
			MOV EDX, 0
			JMP CONTINUE
			NOT_A_SPACE :
		INC EDX
			CONTINUE :
		INC ESI
			JMP INIZIO_CICLO


			FINE :
		MOV spazi, EBX

	}

	printf("%d", spazi);
}