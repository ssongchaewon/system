/* 
 * ls_la.c: 숨김 파일을 포함하여 모든 파일의 상세 정보(-la) 출력
 *   - ls_l과 ls_a 기능을 합침
 */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// 파일 권한 출력 함수 (ls_l과 동일)
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
    DIR *d = opendir(".");
    if (!d) return 1;

    struct dirent *entry;
    struct stat st;
    // 디렉토리 엔트리 반복
    while ((entry = readdir(d)) != NULL) {
        // 파일 상태 정보 가져오기
        if (stat(entry->d_name, &st) == -1) continue;
        print_mode(st.st_mode);  // 권한 정보 출력
        printf("%2ld ", st.st_nlink);
        printf("%s ", getpwuid(st.st_uid)->pw_name);
        printf("%s ", getgrgid(st.st_gid)->gr_name);
        printf("%5ld ", st.st_size);
        char buf[20];
        strftime(buf, sizeof(buf), "%b %d %H:%M", localtime(&st.st_mtime));
        printf("%s ", buf);
        printf("%s\n", entry->d_name);
    }
    closedir(d);
    return 0;
}
