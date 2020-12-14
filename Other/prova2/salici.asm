.586
.model flat
.code


;int somma_modulo(int *src, int lunghezza, int *dst, int divisore);

_somma_modulo proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

mov esi, 0
mov edi, 0;flag
mov ecx, dword ptr[ebp+8] ;src
mov ebx, dword ptr[ebp+16] ;resto

mov eax, 0 ;somma dei resti

ciclo_0:
cmp edi, dword ptr[ebp+12] ;cmp edi+1 con lunghezza
je fine_ciclo_0

call divisione


inc edi
jmp ciclo_0


fine_ciclo_0:
mov eax, esi


;tutti divisori
cmp eax, 0
jne fine_1
mov eax, -1
jmp fine


fine_1:
mov edi, 0

ciclo_2:
cmp edi, dword ptr[ebp+12]
je fine
cmp dword ptr[ebx+edi*4], 0
je fine_2
inc edi
jmp ciclo_2

fine_2:
mov eax, -2

fine:
pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_somma_modulo endp

divisione proc

mov eax, dword ptr[ecx+edi*4]
cdq
idiv dword ptr[ebp+20]
mov dword ptr[ebx+edi*4], edx

add esi, edx



ret
divisione endp

end

