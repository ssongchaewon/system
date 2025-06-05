/* 
 * tail_5.c: 마지막 5줄만 출력하는 프로그램
 *   - tail.c와 유사하지만 고정 5줄
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1024
#define MAXLEN 1024

int main(int argc, char *argv[]) {
    int n = 5;
    char *lines[MAXLINES];
    char buffer[MAXLEN];
    int count = 0;
    // 입력을 모두 읽어서 배열에 저장
    while (count < MAXLINES && fgets(buffer, sizeof(buffer), stdin)) {
        lines[count] = strdup(buffer);
        count++;
    }
    int start = count > n ? count - n : 0;
    for (int i = start; i < count; i++) {
        fputs(lines[i], stdout);
    }
    return 0;
}
