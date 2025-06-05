/* 
 * stat.c: 파일의 크기, 권한, 마지막 수정 시간을 출력하는 프로그램
 *   - stat 함수를 사용하여 struct stat 구조체에 정보 저장
 *   - ctime으로 수정 시간 형식화
 */

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    struct stat st;
    if (stat(argv[1], &st) != 0) return 1;
    printf("Size: %ld\n", st.st_size);                       // 파일 크기
    printf("Permissions: %o\n", st.st_mode & 0777);          // 권한 (8진수)
    printf("Last modified: %s", ctime(&st.st_mtime));        // 마지막 수정 시간
    return 0;
}
