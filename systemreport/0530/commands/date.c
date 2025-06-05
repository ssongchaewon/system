/* 
 * date.c: 현재 시스템 시간과 날짜를 출력하는 프로그램
 *   - time, localtime, strftime 함수를 사용하여 형식화
 */

#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    time_t t = time(NULL);  // 현재 시간 가져오기
    struct tm *tm = localtime(&t);
    char buf[100];
    // "요일 월 일 시:분:초 시간대 연도" 형식으로 출력
    strftime(buf, sizeof(buf), "%a %b %d %H:%M:%S %Z %Y", tm);
    printf("%s\n", buf);
    return 0;
}
