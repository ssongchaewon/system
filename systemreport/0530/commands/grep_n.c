/* 
 * grep_n.c: -n 옵션으로 출력 시 줄 번호를 함께 표시
 *   - lineno 변수를 사용하여 현재 줄 번호 추적
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    char *pattern = argv[1];
    char buffer[1024];
    int lineno = 1;
    // 한 줄씩 읽어 패턴이 포함되면 "줄번호:내용" 형식으로 출력
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (strstr(buffer, pattern))
            printf("%d:%s", lineno, buffer);
        lineno++;
    }
    return 0;
}
