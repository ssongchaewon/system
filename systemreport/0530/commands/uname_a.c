/* 
 * uname_a.c: -a 옵션처럼 시스템의 다양한 정보를 공백으로 구분하여 출력
 *   - sysname, nodename, release, version, machine 출력
 */

#include <stdio.h>
#include <sys/utsname.h>

int main(int argc, char *argv[]) {
    struct utsname u;
    uname(&u);
    printf("%s %s %s %s %s\n", u.sysname, u.nodename, u.release, u.version, u.machine);
    return 0;
}
