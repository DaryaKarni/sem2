#include <iostream>
//дробь задаётся целым числителем и натуральным знаменателем. Сократить её numenator denominator
int main(){
    int num = 0;
    unsigned int denom = 3;
    int nod, flag = 0;

    _asm {
   
    cmp num, 0
    je zero_point
    jg beg1
    neg num
    mov flag, 1
    beg1:
    mov eax, num
    mov ebx, denom
    beg:
    cmp eax, ebx
    je equal
    jg greater
    sub ebx, eax
    jmp beg
    greater:
    sub eax, ebx
    jmp beg
    equal:
    mov nod, eax

    cmp flag, 1
    jne contin
    neg num
    
    contin:
    mov eax, num
    cdq
    idiv nod
    mov num, eax

    mov eax, denom
    cdq
    idiv nod
    mov denom, eax

    zero_point:
    }
    std::cout << num << "/" << denom << "\n";
    return 0;
}

