/* 
 * hostname.c: 시스템 호스트 이름을 출력하는 프로그램
 *   - gethostname 함수 사용
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buffer[256];
    if (gethostname(buffer, sizeof(buffer)) == 0) {
        printf("%s\n", buffer);
    }
    return 0;
}
