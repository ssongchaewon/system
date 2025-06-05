/* 
 * echo_n.c: -n 옵션처럼 출력 후 줄바꿈 없이 마무리
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc-1) printf(" ");
    }
    // 줄바꿈 생략
    return 0;
}
