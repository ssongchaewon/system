/* 
 * grep_text.c: 지정된 패턴이 포함된 줄을 출력하는 grep 기본 기능
 *   - 문자열 검색을 위해 strstr 함수 사용
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;  // 패턴 인자 없으면 종료
    char *pattern = argv[1];
    char buffer[1024];
    // 표준 입력을 한 줄씩 읽어 패턴이 포함된 줄 출력
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (strstr(buffer, pattern))
            fputs(buffer, stdout);
    }
    return 0;
}
