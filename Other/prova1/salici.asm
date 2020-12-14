.586
.model flat
.code

_divisione_array proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

mov edi, 0
mov ecx, dword ptr[ebp+8] ;src
mov ebx, dword ptr[ebp+20] ;resto
mov esi, dword ptr[ebp+12] ;divisore
ciclo_0:
inc edi
cmp edi, dword ptr[ebp+16] ;cmp edi+1 con lunghezza
je fine_ciclo_0
dec edi
call divisione

mov dword ptr[ecx+edi*4], eax
mov dword ptr[ebx+edi*4], edx

inc edi
jmp ciclo_0


fine_ciclo_0:


pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_divisione_array endp

divisione proc

mov eax, dword ptr[ecx+edi*4]
cdq
idiv esi


ret
divisione endp

end

