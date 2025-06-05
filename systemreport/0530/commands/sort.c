/* 
 * sort.c: 입력된 라인을 사전 순으로 정렬하여 출력하는 프로그램
 *   - fgets로 모든 라인을 읽어 배열에 저장 후 qsort로 정렬
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1024
#define MAXLEN 1024

int main(int argc, char *argv[]) {
    char *lines[MAXLINES];
    char buffer[MAXLEN];
    int count = 0;
    // 입력을 모두 읽어 배열에 저장
    while (count < MAXLINES && fgets(buffer, sizeof(buffer), stdin)) {
        lines[count] = strdup(buffer);
        count++;
    }
    // 사전 순 정렬
    qsort(lines, count, sizeof(char*), (int(*)(const void*, const void*))strcmp);
    // 정렬된 라인 출력
    for (int i = 0; i < count; i++) {
        fputs(lines[i], stdout);
    }
    return 0;
}
