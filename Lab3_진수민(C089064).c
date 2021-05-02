//  Lab No.3 : 복소수 구조체를 정의하고 연산하는 프로그램.
// 작성자: 503, 진수민(C089064)
// 날짜  : 2021년 3월 17일
// 실수부와 허수부를 나누어 복소수 구조체를 구현함
// 복소수 사칙연산 법칙을 이용해 계산하는 함수를 작성함

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	double real;		
	double imag;
}Complex;

Complex add_complex(Complex a, Complex b) {
	Complex c;

	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;

	return c;
}

Complex sub_complex(Complex a, Complex b) {
	Complex c;

	c.real = a.real - b.real;
	c.imag = a.imag - b.imag;

	return c;
}

Complex multi_complex(Complex a, Complex b) {
	Complex c;

	c.real = (a.real*b.real) - (a.imag * b.imag);
	c.imag = (a.real * b.real) + (a.imag * b.imag);

	return c;
}

void print_complex(Complex c) {
	printf("%4.1f + %4.1fi\n", c.real, c.imag);
}

Complex reset_complex(Complex c) {
	c.real = c.imag = 5.7;
	return c;
}

void main() {
	Complex a = { 1.0, 2.0 };
	printf("초기화 이전 : ");
	print_complex(a);
	a = reset_complex(a);
	printf("초기화 이후 : ");
	print_complex(a);

	Complex a = { 3.0, 3.0 };
	Complex b = { 3.0, 5.3 };
	
	printf("\n a = ");
	print_complex(a);
	printf(" b = ");
	print_complex(b);

	Complex c = add_complex(a, b); 
	printf("복소수 덧셈 결과 : ");
	print_complex(c);
	
	Complex c = sub_complex(a, b); 
	printf("복소수 뺄셈 결과 : ");
	print_complex(c);

	c = multi_complex(a, b);
	printf("\n복소수 곱셈 결과 : ");
	print_complex(c);
	
}