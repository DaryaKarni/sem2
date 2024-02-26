#include <iostream>
//var 8
// ex 2
//Поменять порядок цифр натурального числа на обратный

//10 0000 1010
//01 0000 0001


//11 0000 1011
//11 0000 1011
// 
//0
//12 0000 1100 
//21 0001 0101
//13 0000 1101
//31 0001 1111
//18 0001 0010
//81 0101 0001


//123 12.3 1.2 0.1 


int main() {
	int x = 10, n , count = -1, sum = 0, res;
	std::cin >> n;
	_asm {
		mov eax, n

		check_z :
		cmp eax, 0
			je end_check
			cdqs
			div x
			inc count // end : 2 
			jmp check_z

			end_check :
		mov eax, n
			cmp count, 1
			jl the_end

			mov eax, n
			start :
		cdq
			div x
			mov ebx, edx // 3
			sub edx, edx
			cmp count, 0
			je digit
			mov ecx, count

			beg :
		imul ebx, x
			loop beg
			add sum, ebx
			dec count
			jmp start
			digit :
		add sum, ebx

			mov eax, sum
			the_end :
		mov res, eax




	}
	std::cout << res << "\n";
	return 0;
}