/* 
 * mkdir_p.c: -p 옵션처럼 중간 디렉토리를 포함하여 생성하는 프로그램
 *   - 문자열을 '/'로 분리하여 경로별로 mkdir 호출
 */

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

// 경로 문자열을 받아 중간 디렉토리를 순차적으로 생성
void make_path(char *path) {
    char tmp[1024];
    char *p = NULL;
    size_t len;
    snprintf(tmp, sizeof(tmp), "%s", path);
    len = strlen(tmp);
    if (tmp[len - 1] == '/') tmp[len - 1] = 0;
    for (p = tmp + 1; *p; p++) {
        if (*p == '/') {
            *p = 0;
            mkdir(tmp, 0755);
            *p = '/';
        }
    }
    mkdir(tmp, 0755);
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    make_path(argv[1]);  // 경로 생성 함수 호출
    return 0;
}
