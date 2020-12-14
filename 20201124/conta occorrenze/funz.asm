.586
.model flat
.code

_conta_occorrenze proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

;inizio funz

mov ecx, dword ptr[ebp+8] ;str
mov edx, dword ptr[ebp+12] ;parola
mov esi, 0 ; contatore str
mov edi, 0 ; contatore parola
mov eax, 0 ; numero referenze
ciclo_0:
cmp byte ptr [ecx + esi], 0
je fine_0
cmp byte ptr [ecx + esi], ' '
jne not_new_word
call ctrl_parola
not_new_word:
inc esi
jmp ciclo_0


fine_0:

; fine funz

pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_conta_occorrenze endp

ctrl_parola proc

mov edi, 0
inc esi

ciclo_parola:
cmp byte ptr [ecx + esi], ' '
je spazio_stringa
cmp byte ptr [edx + edi], 0
je fine_parola
mov bl, byte ptr [edx + edi] 
cmp byte ptr [ecx + esi], bl
jne fine_parola

inc esi
inc edi
jmp ciclo_parola

spazio_stringa:
cmp byte ptr [edx + edi], 0
jne fine_parola
inc eax
fine_parola:
dec esi
ret
ctrl_parola endp

end