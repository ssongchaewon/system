/* 
 * head_5.c: 앞 5줄만 출력하는 프로그램
 *   - 인자 없이 고정 5줄
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 5;
    char buffer[1024];
    int count = 0;
    // 5줄 읽어서 출력
    while (count < n && fgets(buffer, sizeof(buffer), stdin)) {
        fputs(buffer, stdout);
        count++;
    }
    return 0;
}
