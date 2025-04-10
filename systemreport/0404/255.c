#include <stdio.h>

void printBinary(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int countOnes(unsigned char num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    unsigned char num;

    printf("0~255 사이의 정수를 입력하세요: ");
    scanf("%hhu", &num); 

    printf("입력한 수의 2진수: ");
    printBinary(num);
    printf("\n");

    int ones = countOnes(num);
    printf("1의 개수: %d개\n", ones);

    unsigned char upper4Bits = (num >> 4) & 0x0F;
    printf("상위 4비트: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (upper4Bits >> i) & 1);
    }
    printf("\n");

    return 0;
}