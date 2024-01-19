#include <stdio.h>
#include <stdint.h>

typedef unsigned char byte;
typedef unsigned int word;

//8-bit rotate function by macro
//(byte)������ ������ w�� 32-bit������ �ν� -> ���� ���� �� ����
#define ROR(w,mv) ((((byte)(w))>>(mv))|(((byte)(w))<<(8-(mv)))) 
#define ROL(w,mv) ((((byte)(w))<<(mv))|(((byte)(w))>>(8-(mv))))

//F0
//macro�� ������ �� �ӵ� up!
byte F0(byte input) {
	return (byte)(ROL(input, 1) ^ ROL(input, 2) ^ ROL(input, 7));
}

//F1
//macro�� ������ �� �ӵ� up!
byte F1(byte input) {
	return (byte)(ROL(input, 3) ^ ROL(input, 4) ^ ROL(input, 6));
}

void make_F_box() {
	int i;
	byte value = 0;

	for (i = 0; i < 256; i++) {
		if (i != 0 && i % 16 == 0) {
			printf("\n");
		}
		value = F0(i);
		printf("0x%02x, ", value);
	}
	printf("\n");
	printf("\n");

	for (i = 0; i < 256; i++) {
		if (i != 0 && i % 16 == 0) {
			printf("\n");
		}
		value = F1(i);
		printf("0x%02x, ", value);
	}



}

int main() {
	make_F_box();
}