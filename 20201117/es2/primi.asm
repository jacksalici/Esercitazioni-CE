.586
.model flat
.code

_primo proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

;inizio funz

mov ebx, dword ptr [ebp+8]  ;a
mov ecx, dword ptr [ebp+12] ;b


scorro_a:
mov esi, 0
cmp esi, dword ptr [ebp+16]
je fine_a
ciclo_a:
mov eax, dword ptr [ebx + esi*4]
call is_prime
mov dword ptr [ecx + esi*4], edi
inc esi
fine_a:


call count_prime




;fine funz

pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_primo endp

is_prime proc
push esi
mov esi, 2
mov edi, 1

ciclo_2:
cmp eax, esi
je fine_ciclo_2 

push eax
cdq
idiv esi
pop eax

cmp edx, 0

jne not_prime
inc esi

jmp ciclo_2

not_prime:
mov edi, 0
fine_ciclo_2:

pop esi
ret
is_prime endp


count_prime proc
mov esi, 0
mov eax, 0
ciclo_3:
cmp esi, dword ptr[ebp+16]
je fine_ciclo_3

add eax, dword ptr[ecx+esi*4]
inc esi
jmp ciclo_3
fine_ciclo_3:
ret
count_prime endp
end