#include <iostream>
//2x + 3y = 50
int main() {
    int x = 0, y = 0, k = 0;
    int A[10] = {};
    int B[10] = {};
    _asm {
        mov edx, 0
        lea esi, A
        lea edi, B

        cycle1 :
        mov eax, x
            cycle2 :
        mov ebx, y
            imul eax, 2
            imul ebx, 3
            add eax, ebx
            cmp eax, 50
            je found
            jg incx
            inc y
            mov eax, x
            jmp cycle2
            incx :
        inc x
            mov y, 0
            jmp cycle1
            found :
        mov ecx, x
            mov[esi][edx * 4], ecx
            mov ecx, y
            mov[edi][edx * 4], ecx
            inc edx
            cmp x, 25
            je end
            jmp incx
            end :
        mov k, edx
    }

    for (int i = 0; i < k;i++) {
        std::cout << "2*" << A[i] << " + 3*" << B[i] << " = " << 2 * A[i] + 3 * B[i] << "\n";
    }
    return 0;
}
     
