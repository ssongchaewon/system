/* 
 * ls_lh.c: -lh 옵션처럼 파일 크기를 사람이 읽기 쉬운 형식으로 표시
 *   - human_size 함수를 통해 바이트 단위를 KB, MB 등으로 변환
 */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// 권한 출력 함수 (ls_l과 동일)
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

// 바이트 형식을 사람이 읽기 쉬운 단위로 변환하여 출력
void human_size(long size) {
    const char* suffix[] = {"B","K","M","G","T"};
    int idx = 0;
    double d = size;
    while (d >= 1024 && idx < 4) {
        d /= 1024;
        idx++;
    }
    printf("%4.1f%s ", d, suffix[idx]);
}

int main(int argc, char *argv[]) {
    DIR *d = opendir(".");
    if (!d) return 1;

    struct dirent *entry;
    struct stat st;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        if (stat(entry->d_name, &st) == -1) continue;
        print_mode(st.st_mode);
        printf("%2ld ", st.st_nlink);
        printf("%s ", getpwuid(st.st_uid)->pw_name);
        printf("%s ", getgrgid(st.st_gid)->gr_name);
        human_size(st.st_size);  // 사람이 읽기 쉬운 크기 출력
        char buf[20];
        strftime(buf, sizeof(buf), "%b %d %H:%M", localtime(&st.st_mtime));
        printf("%s ", buf);
        printf("%s\n", entry->d_name);
    }
    closedir(d);
    return 0;
}
