/* 
 * df.c: 현재 디렉토리가 포함된 파일 시스템의 총 용량과 사용 가능한 용량을 출력
 *   - statvfs 함수를 사용하여 파일 시스템 통계 조회
 */

#include <stdio.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[]) {
    struct statvfs v;
    if (statvfs(".", &v) == 0) {
        unsigned long total = v.f_blocks * v.f_frsize;   // 총 블록 수 * 블록 크기
        unsigned long avail = v.f_bavail * v.f_frsize;   // 사용 가능 블록 수 * 블록 크기
        printf("Total: %lu bytes\nFree: %lu bytes\n", total, avail);
    }
    return 0;
}
