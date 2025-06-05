/* 
 * id.c: 현재 사용자의 uid 및 gid 정보를 출력하는 프로그램
 *   - getpwuid, getgrgid 함수 사용
 */

#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
    uid_t uid = geteuid();
    gid_t gid = getegid();
    struct passwd *pw = getpwuid(uid);
    struct group *gr = getgrgid(gid);
    if (pw && gr) {
        // uid와 gid 정보를 "(이름)" 형식과 함께 출력
        printf("uid=%d(%s) gid=%d(%s)\n", uid, pw->pw_name, gid, gr->gr_name);
    }
    return 0;
}
