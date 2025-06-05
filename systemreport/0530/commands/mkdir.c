/* 
 * mkdir.c: 디렉토리를 생성하는 프로그램 (기본 권한 0755)
 *   - mkdir 함수 사용
 */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    if (mkdir(argv[1], 0755) != 0) {
        perror("mkdir");  // 실패 시 에러 메시지 출력
        return 1;
    }
    return 0;
}
