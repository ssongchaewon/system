/* 
 * rm_f.c: -f 옵션처럼 오류를 무시하고 파일 삭제 시도
 *   - unlink 실패 시 무시
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    if (unlink(argv[1]) != 0) {
        // 오류 무시
    }
    return 0;
}
