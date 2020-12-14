.586
.model flat
.code

_palindroma proc
push ebp
mov ebp, esp
push ebx
push esi
push edi

;inizio funz

mov ecx, dword ptr[ebp+8]
mov esi, 0 ;contatore, edi: lunghezza
mov al, 1 ;eax è palindromo
call strlen

ci:
dec edi
cmp esi, edi
jge fi

mov bl, byte ptr[ecx+edi]
cmp byte ptr[ecx+esi], bl
jne not_p
inc esi
dec edi
jmp ci

not_p:
mov al, 0
fi:
ret
; fine funz

pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret
_palindroma endp

strlen proc

mov edi, 0
ciclo_lun:
cmp byte ptr [ecx+edi],0
je fine_lun
inc edi
jmp ciclo_lun

fine_lun:
ret
strlen endp

end