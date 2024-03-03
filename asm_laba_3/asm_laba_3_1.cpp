#include <iostream>


int main() {

	int a, res;
	std::cin >> a;

	_asm {

		mov ecx, 11
		mov eax, a
			beg1:
		imul eax, a
			loop beg1
		
		mov ecx, 7
		mov ebx, a
			beg2:
		imul ebx, a
			loop beg2
		add eax, ebx
		add eax, a
		mov res, eax
	}

	std::cout << res << "\n";

	return 0;
}