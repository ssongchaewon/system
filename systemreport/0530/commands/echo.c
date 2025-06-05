/* 
 * echo.c: 인자로 받은 문자열을 출력하는 프로그램
 *   - 공백으로 구분하여 반복 출력 후 줄바꿈
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc-1) printf(" ");
    }
    printf("\n");
    return 0;
}
