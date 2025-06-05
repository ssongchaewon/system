/* 
 * wc.c: 입력으로 받은 텍스트의 행, 단어, 바이트 수를 출력하는 프로그램
 *   - getchar를 사용하여 문자별 처리
 *   - 공백, 줄바꿈, 탭을 단어 구분으로 간주
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int lines = 0, words = 0, bytes = 0;
    char c;
    while ((c = getchar()) != EOF) {
        bytes++;
        if (c == '\n') lines++;
        if (c == ' ' || c == '\n' || c == '\t') words++;
    }
    printf("%d %d %d\n", lines, words, bytes);
    return 0;
}
