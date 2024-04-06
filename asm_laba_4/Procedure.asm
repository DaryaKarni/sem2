;.686P
.model flat, c
.code

;(2 * x - 1)* (2 * x + 1)* (x + 3) / (2 * x)

Procedure		proc x : dword
        mov eax, x
        imul eax, 2
        sub eax, 1

        mov ebx, x
        imul ebx, 2
        add ebx, 1
        imul eax, ebx

        mov ecx, x
        imul ecx, 2

        mov ebx, x
        add ebx, 3
        imul eax, ebx
        cdq
        idiv ecx
        ret
Procedure endp
end
        
    