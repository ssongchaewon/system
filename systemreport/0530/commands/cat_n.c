/* 
 * cat_n.c: -n 옵션처럼 줄 번호를 붙여 출력하는 cat 프로그램
 *   - 줄 번호를 카운트하여 각 줄 앞에 번호 출력
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    char buffer[1024];
    int line_no = 1;
    // 한 줄씩 읽어와 줄 번호와 함께 출력
    while (fgets(buffer, sizeof(buffer), stdin)) {
        printf("%6d  %s", line_no++, buffer);
    }
    return 0;
}
