.586
.model flat
.code


;int cerca_combinazioni_numero(char *src, int num, int* vettori_num);

_cerca_combinazioni_numero proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

mov esi, 0 ;per scorrere la src
mov al, byte ptr[ebp+12] ;num
add al, 30h
mov ecx, dword ptr[ebp+8] ;src
mov ebx,  dword ptr[ebp+16]  ;vettori_num

mov dword ptr[ebx+0], 0
mov dword ptr[ebx+4], 0
mov dword ptr[ebx+8], 0

ciclo_src:
cmp byte ptr[ecx+esi], 0
je fine_ciclo_src
cmp al, byte ptr[ecx+esi]
jne not_the_number
inc esi
cmp al, byte ptr[ecx+esi]
jne is_single
inc esi
cmp al, byte ptr[ecx+esi]
jne is_double
inc esi
cmp al, byte ptr[ecx+esi]
jne is_triple


is_single:
inc dword ptr[ebx+0]
inc esi
jmp ciclo_src

is_double:
inc dword ptr[ebx+4]
inc esi
jmp ciclo_src

is_triple:
inc dword ptr[ebx+8]
inc esi
jmp ciclo_src

not_the_number:
inc esi
jmp ciclo_src

fine_ciclo_src:
mov eax, 0
pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_cerca_combinazioni_numero endp




end

