/* 
 * grep_v.c: -v 옵션으로 패턴이 포함되지 않은 줄만 출력
 *   - !strstr 조건으로 역검색
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    char *pattern = argv[1];
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (!strstr(buffer, pattern))
            fputs(buffer, stdout);
    }
    return 0;
}
