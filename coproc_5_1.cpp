#include <iostream>
#include <iomanip> 

int main() {

	float k = 1;
	float res = 0;
	float one = 1;
	float minusone = -1;
	float fract = 0;
	float sum = 0;
	float onechg = -1;
	float twelve = 12;
	float mypi = 0;
	float trash;
	
	_asm{
		
	mov ecx, 1500
	sumloop:
		fld k
		fld k
		fmul
		fld one
		fdiv st(0), st(1)
		fld fract
		fadd 
		fstp fract

		fld minusone
		fld onechg
		fmul
		fstp onechg
	

		fld onechg
     	        fld fract
		fmul
		fstp fract

		fld fract
		fld sum
		fadd 
		fstp sum

		fstp trash

		fld minusone
		fld fract
		fmul
		fld fract
		fadd
		fstp fract

		fld one
		fld k
		fadd
		fstp k
		
	loop sumloop

		fld twelve
		fld sum
		fmul
	        fsqrt
		fstp sum

		fld res
		fld sum
		fadd
		fstp res
		
		fld res
		fldpi
	        fcomp

		fldpi
		fstp mypi
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(20) << mypi << " - real pi" << "\n";
	std::cout << std::fixed;
	std::cout << std::setprecision(5) << res << "\n";
	std::cout << std::setprecision(7) << res << "\n";
	std::cout << std::setprecision(9) << res << "\n";
	return 0;
}
