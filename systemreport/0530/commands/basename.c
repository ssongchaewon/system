/* 
 * basename.c: 경로에서 파일 이름 부분만 추출하여 출력하는 프로그램
 *   - libgen.h의 basename 함수 사용
 */

#include <stdio.h>
#include <libgen.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    char *b = basename(argv[1]);
    printf("%s\n", b);
    return 0;
}
