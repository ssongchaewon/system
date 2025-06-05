/* 
 * tail.c: 기본적으로 마지막 10줄을 출력하는 프로그램
 *   - 전체 입력을 버퍼에 저장한 뒤 마지막 n줄 출력
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1024
#define MAXLEN 1024

int main(int argc, char *argv[]) {
    int n = 10;
    if (argc > 1) n = atoi(argv[1]);  // 사용자 입력 줄 수
    char *lines[MAXLINES];
    char buffer[MAXLEN];
    int count = 0;
    // 입력을 전부 읽어서 배열에 저장
    while (count < MAXLINES && fgets(buffer, sizeof(buffer), stdin)) {
        lines[count] = strdup(buffer);
        count++;
    }
    // 마지막 n줄을 출력
    int start = count > n ? count - n : 0;
    for (int i = start; i < count; i++) {
        fputs(lines[i], stdout);
    }
    return 0;
}
