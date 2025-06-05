/* 
 * sort_r.c: -r 옵션으로 사전 순 역순 정렬하여 출력하는 프로그램
 *   - 비교 함수에서 두 인자의 순서를 뒤바꿈
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1024
#define MAXLEN 1024

// 문자열 역순 비교 함수
int cmp_desc(const void *a, const void *b) {
    return strcmp(*(char**)b, *(char**)a);
}

int main(int argc, char *argv[]) {
    char *lines[MAXLINES];
    char buffer[MAXLEN];
    int count = 0;
    // 입력을 모두 읽어 배열에 저장
    while (count < MAXLINES && fgets(buffer, sizeof(buffer), stdin)) {
        lines[count] = strdup(buffer);
        count++;
    }
    // 역순 정렬
    qsort(lines, count, sizeof(char*), cmp_desc);
    for (int i = 0; i < count; i++) {
        fputs(lines[i], stdout);
    }
    return 0;
}
