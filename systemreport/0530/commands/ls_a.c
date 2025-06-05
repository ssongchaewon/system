/* 
 * ls_a.c: 현재 디렉토리에서 모든 파일(숨김 포함) 이름을 출력하는 프로그램
 *   - 숨김 파일도 포함하기 위해 이름 검사 없이 바로 출력
 */

#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    // 현재 디렉토리 열기
    DIR *d = opendir(".");
    if (!d) return 1;

    struct dirent *entry;
    // 디렉토리 엔트리 반복
    while ((entry = readdir(d)) != NULL) {
        printf("%s  ", entry->d_name);  // 모든 파일 이름 출력
    }
    printf("\n");
    closedir(d);
    return 0;
}
