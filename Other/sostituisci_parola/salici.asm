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

mov esi, 0 ;per scorrere la parola
mov edi, 0 ;per scorrere la frase
mov ecx, dword ptr[ebp+8] ;frase
mov ebx, dword ptr[ebp+12] ;parola


ciclo_frase:

cmp byte ptr [ecx + edi], 0 
je fine_frase

cmp byte ptr [ecx + edi], ' '
jne non_spazio 

call maybe  ;se trovo uno spazio (ovvero sta per incominciare una parola) chiamo questa near per verificare se è la parola che cerco

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

ciclo_parola: ;in al metto l'attuale lettera della parola, in ah l'attuale lettera della frase

mov al, byte ptr [ebx + esi]      
cmp al, 0
je fine_parola
mov ah, byte ptr [ecx + edi]
cmp al, ah ;confronto lettera per lettera
jne parola_diversa
inc esi
inc edi
jmp ciclo_parola

fine_parola: ;quando la parola finisce (stringa 0 terminata) controllo che anche nella frase la parola sia finita
cmp byte ptr [ecx + edi], ' '
jne parola_diversa

call substitution ;se ho trovato una corrispondenza vado a sostituire in una funzione apposita
dec edi ;torno indetro di una lettera per poter tornare a verificare che, dopo lo spazio, non ci sia di nuovo una corrispondenza
parola_diversa:
ret
maybe endp

substitution proc 

sub edi, esi ;torno indietro nella frase della lunghezza della parola

mov esi, 0
mov edx, dword ptr [ebp+16]

inizio_sost:
mov ah, byte ptr [edx + esi]
cmp ah, 0 ;finché la nuova parola non finisce cambio lettera per lettera (le due parole sono sempre di lunghezza uguale)
je fine_sost
mov byte ptr [ecx+edi], ah
inc esi
inc edi
jmp inizio_sost

fine_sost:

ret 
substitution endp




end

