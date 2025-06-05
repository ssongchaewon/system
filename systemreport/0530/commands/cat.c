/* 
 * cat.c: 표준 입력에서 받은 내용을 그대로 출력하는 프로그램
 *   - fgets로 한 줄씩 읽고 fputs로 출력
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char buffer[1024];
    // fgets로 입력을 읽어 EOF까지 반복
    while (fgets(buffer, sizeof(buffer), stdin)) {
        fputs(buffer, stdout);
    }
    return 0;
}
