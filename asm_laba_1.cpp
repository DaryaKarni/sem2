#include <iostream>

int main() {

	_int16 
		A1 = 0b01, A2 = 0b10, A3 = 0b101,
		B1 = 0b01, B2 = 0b01, B3 = 0b0,
		C1 = 0, C2 = 0, C3 = 0;
	long unsigned int res(0);

	_asm {

		mov ax, A1
		add ax, B1
		jae number2
		mov bx, 1
		number2:
		mov C1, ax
			
	    mov ax, A2
		add ax, B2
		mov C2, ax
			
		mov ax, A3
		add ax, B3
		mov C3, ax

	}

	res += C3;         
	res = res << 4;   
	res += C2;      
	res = res << 4;  
	res += C1;  

	std::cout << "10 c/c: " << res << "\n";
	std::cout << "16 c/c: " << std::hex << res << std::endl;
	return 0;
}