/* 
 * whoami.c: 현재 사용자의 로그인 이름을 출력하는 프로그램
 *   - geteuid, getpwuid 함수를 사용하여 사용자 정보 검색
 */

#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
    uid_t uid = geteuid();  // 유효 사용자 ID 가져오기
    struct passwd *pw = getpwuid(uid);
    if (pw) printf("%s\n", pw->pw_name);
    return 0;
}
