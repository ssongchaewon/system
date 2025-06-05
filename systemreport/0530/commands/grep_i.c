/* 
 * grep_i.c: -i 옵션으로 대소문자 구분 없이 검색하는 grep
 *   - 패턴과 입력 라인을 모두 소문자로 변환하여 비교
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    char pattern[256];
    // 패턴을 소문자로 변환
    for (int i = 0; argv[1][i]; i++)
        pattern[i] = tolower(argv[1][i]);
    pattern[strlen(argv[1])] = '\0';

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        char lower[1024];
        // 입력 라인을 소문자로 변환
        for (int i = 0; buffer[i]; i++)
            lower[i] = tolower(buffer[i]);
        lower[strlen(buffer)] = '\0';

        // 소문자로 변환된 문자열에서 패턴 검색
        if (strstr(lower, pattern))
            fputs(buffer, stdout);
    }
    return 0;
}
