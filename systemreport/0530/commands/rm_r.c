/* 
 * rm_r.c: -r 옵션으로 디렉토리를 재귀적으로 삭제하는 프로그램
 *   - rmdir와 unlink 사용
 *   - remove_dir 함수 재귀 호출
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

// 주어진 경로의 디렉토리를 재귀적으로 삭제
void remove_dir(const char *path) {
    DIR *d = opendir(path);
    if (!d) return;
    struct dirent *entry;
    char buf[1024];
    struct stat st;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0) continue;
        snprintf(buf, sizeof(buf), "%s/%s", path, entry->d_name);
        stat(buf, &st);
        if (S_ISDIR(st.st_mode)) {
            remove_dir(buf);  // 디렉토리면 재귀 삭제
        } else {
            unlink(buf);  // 파일이면 삭제
        }
    }
    closedir(d);
    rmdir(path);  // 비어있는 디렉토리 삭제
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    remove_dir(argv[1]);
    return 0;
}
