/* 
 * mv.c: 파일 또는 디렉토리 이름 변경(이동) 프로그램
 *   - rename 함수 사용
 *   - 실패 시 perror로 에러 메시지 출력
 */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;
    if (rename(argv[1], argv[2]) != 0) {
        perror("mv");  // 에러 발생 시 이유 출력
        return 1;
    }
    return 0;
}
