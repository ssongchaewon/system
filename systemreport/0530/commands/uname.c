/* 
 * uname.c: 시스템의 커널 이름만 출력하는 프로그램
 *   - uname 함수 사용
 */

#include <stdio.h>
#include <sys/utsname.h>

int main(int argc, char *argv[]) {
    struct utsname u;
    uname(&u);
    printf("%s\n", u.sysname);  // 커널 이름 출력
    return 0;
}
