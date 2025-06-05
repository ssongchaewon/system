/* 
 * ls.c: 현재 디렉토리에서 숨김 파일을 제외하고 파일 및 디렉토리 이름을 출력하는 프로그램 
 *   - opendir, readdir 함수 사용
 *   - entry->d_name이 '.'로 시작하면 숨김 파일이므로 건너뛰기
 */

#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    // 현재 디렉토리를 열기 위한 DIR 포인터
    DIR *d = opendir(".");
    if (!d) return 1;  // 디렉토리 열기에 실패하면 에러 코드 반환

    struct dirent *entry;
    // readdir로 디렉토리 엔트리 반복
    while ((entry = readdir(d)) != NULL) {
        // 이름이 '.'로 시작하는 숨김 파일 건너뛰기
        if (entry->d_name[0] == '.') continue;
        printf("%s  ", entry->d_name);
    }
    printf("\n");
    closedir(d);  // 디렉토리 닫기
    return 0;
}
