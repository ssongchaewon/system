/* 
 * pwd.c: 현재 작업 디렉토리 경로를 출력하는 프로그램
 *   - getcwd 함수 사용
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    }
    return 0;
}
