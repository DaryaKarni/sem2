#include <iostream>
//var 8
// ex 2
//Поменять порядок цифр натурального числа на обратный



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
