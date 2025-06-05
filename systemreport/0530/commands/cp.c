/* 
 * cp.c: 파일 복사 프로그램 (단일 파일)
 *   - fopen으로 원본을 읽기, 대상 파일을 쓰기 모드로 열어 복사
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;  // 인자가 부족하면 종료
    FILE *src = fopen(argv[1], "rb");
    if (!src) return 1;  // 원본 파일 열기 실패
    FILE *dst = fopen(argv[2], "wb");
    if (!dst) { fclose(src); return 1; }  // 대상 파일 열기 실패

    char buffer[4096];
    size_t n;
    // fread로 읽은 바이트를 fwrite로 쓰기
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }

    fclose(src);
    fclose(dst);
    return 0;
}
