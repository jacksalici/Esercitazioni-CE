.586
.model flat
.code


;int cerca_combinazioni_numero(int *src, int num, int media);

_cerca_combinazioni_numero proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

mov esi, 0 ;per scorrere la src
mov ebx, 0
mov ecx, dword ptr[ebp+8] ;src

inizio_ciclo:
cmp esi,  dword ptr[ebp+12]
je fine
mov eax, dword ptr [ecx+esi*4]
cqd
idiv 2
cmp edx, 0
jne not_even
inc edi
not_even:
add ebx, dword ptr [ecx+esi*4]
inc esi
jmp inizio_ciclo
fine:

mov eax, ebx
cdq
idiv esi
mov dword ptr[ebp+16], edx

mov eax, edi

pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_cerca_combinazioni_numero endp




end

