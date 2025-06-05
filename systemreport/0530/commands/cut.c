/* 
 * cut.c: 지정된 구분자와 필드 번호에 따라 필드를 잘라서 출력하는 프로그램
 *   - (예) cut ':' 1 /etc/passwd -> 구분자가 ':'이고 첫 번째 필드 출력
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;  // 구분자와 필드 인자 체크
    char delimiter = argv[1][0];
    int field = atoi(argv[2]);  // 출력할 필드 번호
    char buffer[1024];
    // 표준 입력 루프
    while (fgets(buffer, sizeof(buffer), stdin)) {
        int count = 1;
        // 구분자로 문자열 분할
        char *token = strtok(buffer, &delimiter);
        while (token) {
            if (count == field) {
                printf("%s", token);
                break;
            }
            token = strtok(NULL, &delimiter);
            count++;
        }
        printf("\n");
    }
    return 0;
}
