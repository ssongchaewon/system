/* 
 * uniq.c: 연속된 중복 라인을 하나로 출력하는 프로그램
 *   - 이전 라인과 현재 라인을 비교하여 같지 않을 때만 출력
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char prev[1024] = "";
    char buffer[1024];
    // 한 줄씩 읽어 이전과 비교
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (strcmp(buffer, prev) != 0) {
            fputs(buffer, stdout);
            strcpy(prev, buffer);
        }
    }
    return 0;
}
