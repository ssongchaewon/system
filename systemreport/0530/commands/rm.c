/* 
 * rm.c: 파일 삭제 프로그램
 *   - unlink 함수 사용
 *   - 실패 시 perror로 에러 메시지 출력
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    if (unlink(argv[1]) != 0) {
        perror("rm");  // 파일 삭제 실패 시 메시지 출력
        return 1;
    }
    return 0;
}
