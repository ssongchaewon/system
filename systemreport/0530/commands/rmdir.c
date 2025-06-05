/* 
 * rmdir.c: 빈 디렉토리를 삭제하는 프로그램
 *   - rmdir 함수 사용
 */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    if (rmdir(argv[1]) != 0) {
        perror("rmdir");  // 삭제 실패 시 메시지 출력
        return 1;
    }
    return 0;
}
