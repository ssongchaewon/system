/* 
 * dirname.c: 경로에서 디렉토리 경로 부분만 추출하여 출력하는 프로그램
 *   - libgen.h의 dirname 함수 사용
 */

#include <stdio.h>
#include <libgen.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    char *d = dirname(argv[1]);
    printf("%s\n", d);
    return 0;
}
