/* 
 * ls_l.c: 현재 디렉토리에서 숨김 파일을 제외하고 -l 옵션과 비슷하게 상세 정보 출력 
 *   - 파일 모드, 링크 수, 소유자, 그룹, 파일 크기, 수정 시간, 이름을 표시
 *   - stat 함수를 통해 파일 정보를 얻음
 *   - getpwuid, getgrgid로 소유자 및 그룹 이름 조회
 */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// 파일 권한을 문자열 형식으로 출력하는 함수
void print_mode(mode_t mode) {
    printf( (S_ISDIR(mode)) ? "d" : "-");
    printf( (mode & S_IRUSR) ? "r" : "-");
    printf( (mode & S_IWUSR) ? "w" : "-");
    printf( (mode & S_IXUSR) ? "x" : "-");
    printf( (mode & S_IRGRP) ? "r" : "-");
    printf( (mode & S_IWGRP) ? "w" : "-");
    printf( (mode & S_IXGRP) ? "x" : "-");
    printf( (mode & S_IROTH) ? "r" : "-");
    printf( (mode & S_IWOTH) ? "w" : "-");
    printf( (mode & S_IXOTH) ? "x" : "-");
    printf(" ");
}

int main(int argc, char *argv[]) {
    // 현재 디렉토리 열기
    DIR *d = opendir(".");
    if (!d) return 1;

    struct dirent *entry;
    struct stat st;
    // 디렉토리 엔트리 반복
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_name[0] == '.') continue;  // 숨김 파일 건너뛰기
        // 파일 상태 정보 가져오기
        if (stat(entry->d_name, &st) == -1) continue;
        // 파일 권한 출력
        print_mode(st.st_mode);
        printf("%2ld ", st.st_nlink);  // 링크 수 출력

        // 사용자 및 그룹 이름 조회 후 출력
        printf("%s ", getpwuid(st.st_uid)->pw_name);
        printf("%s ", getgrgid(st.st_gid)->gr_name);
        // 파일 크기 출력
        printf("%5ld ", st.st_size);

        // 수정 시간 형식화하여 출력
        char buf[20];
        strftime(buf, sizeof(buf), "%b %d %H:%M", localtime(&st.st_mtime));
        printf("%s ", buf);
        // 파일 이름 출력
        printf("%s\n", entry->d_name);
    }
    closedir(d);
    return 0;
}
