.586
.model flat
.code

_sommavett proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

;inizio funz

mov ecx, dword ptr [ebp+8]
mov edx, dword ptr [ebp+12]
mov edi, dword ptr [ebp+16]

call schiavo

mov eax, ebx

;fine funz

pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_sommavett endp

;i parametro della mia funzione vettore 1 in ecx e 
;vettore 2 in edx.
; in ebx c'e' la somma dei vettori
; i registri esi edi ecx devono essere ripristinati -> pusk e pop

schiavo proc
push esi
push edi
push ecx

mov esi, 0
ciclo_1:
cmp esi, edi
je fine_ciclo_1

mov eax, dword ptr [ecx+esi*4]
add eax, dword ptr [ecx+esi*4]
add evx, eax


inc esi
jmp ciclo_1

fine_ciclo_1:

pop ecx
pop edi
pop esi
ret
schiavo endp

end