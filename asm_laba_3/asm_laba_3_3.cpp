#include <iostream>
//0 1 1 2 3 5 8 13 21 34 55...
int main(){
	
	int a[50] = {};
	a[0] = 0;
	a[1] = 1;
	int n;
	_asm {
		
		lea esi, a
		mov [esi], 0
		mov ebx, 1
		mov [esi][ebx * 4], 1
		mov eax, [esi]

		add eax, [esi][ebx * 4] // 1
		inc ebx//2
		mov [esi][ebx * 4], eax // 1 array[2]

		cycle:
		add eax, [esi][ebx * 4 - 4]
		jo _end
		inc ebx
		mov[esi][ebx * 4], eax 
		jmp cycle

		_end:
		add ebx, 1
		mov n, ebx
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << "\n";
	}
	return 0;
}