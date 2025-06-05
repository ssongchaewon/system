/* 
 * wc_l.c: -l 옵션으로 행 수만 출력하는 프로그램
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int lines = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') lines++;
    }
    printf("%d\n", lines);
    return 0;
}
