/* 
 * head.c: 기본적으로 앞 10줄을 출력하는 프로그램
 *   - 인자가 있으면 atoi로 숫자 n을 받아 앞 n줄 출력
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 10;
    if (argc > 1) n = atoi(argv[1]);  // 사용자 입력 줄 수
    char buffer[1024];
    int count = 0;
    // 지정된 줄 수까지 읽어서 출력
    while (count < n && fgets(buffer, sizeof(buffer), stdin)) {
        fputs(buffer, stdout);
        count++;
    }
    return 0;
}
