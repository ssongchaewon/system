/* 
 * uptime.c: 시스템 부팅 이후 경과 시간을 출력하는 프로그램
 *   - sysinfo 함수를 사용하여 uptime(초) 조회
 */

#include <stdio.h>
#include <sys/sysinfo.h>

int main(int argc, char *argv[]) {
    struct sysinfo s;
    if (sysinfo(&s) == 0) {
        long hours = s.uptime / 3600;               // 시간 단위 계산
        long mins = (s.uptime % 3600) / 60;         // 분 단위 계산
        printf("up %ld:%02ld\n", hours, mins);
    }
    return 0;
}
