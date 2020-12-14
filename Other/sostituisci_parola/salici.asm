.586
.model flat
.code


;void sost_parola(char *src, char * wrd_wrong, char * wrd);

_sost_parola proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

mov esi, 0
mov edi, 0 ;per scorrere la frase
mov ecx, dword ptr[ebp+8] ;src
mov ebx, dword ptr[ebp+12] ;parola


ciclo_frase:

cmp byte ptr [ecx + edi], 0 
je fine_frase

cmp byte ptr [ecx + edi], ' '
jne non_spazio

call maybe
;dec edi
non_spazio:
inc edi
jmp ciclo_frase

fine_frase:
pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_sost_parola endp

maybe proc
inc edi
mov esi,0

ciclo_parola:
;al pointer to word
mov al, byte ptr [ebx + esi]
cmp al, 0
je fine_parola
mov ah, byte ptr [ecx + edi]
cmp al, ah
jne parola_diversa
inc esi
inc edi
jmp ciclo_parola

fine_parola:
cmp byte ptr [ecx + edi], ' '
jne parola_diversa

call substitution
dec edi
parola_diversa:
ret
maybe endp

substitution proc

sub edi, esi

mov esi, 0
mov edx, dword ptr [ebp+16]

inizio_sost:
mov ah, byte ptr [edx + esi]
cmp ah, 0
je fine_sost
mov byte ptr [ecx+edi], ah
inc esi
inc edi
jmp inizio_sost

fine_sost:

ret
substitution endp




end

