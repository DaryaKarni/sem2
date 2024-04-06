#include <iostream>

#include <iostream>

extern "C" int Procedure(int);

int main(){
	int x;
	std::cout << "Enter x: " << "\n";
	std::cin >> x;

	std::cout << "(2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x) = " << "\n";
	std::cout << "C++: " << (2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x) << "\n";
	std::cout << "asm: " << Procedure(x) << "\n";
	return 0;
}
