/* 
 * grep_r.c: -r 옵션처럼 디렉토리를 재귀적으로 탐색하며 파일 내용 중 패턴 검색
 *   - traverse 함수 재귀로 디렉토리 탐색
 *   - search_in_file로 파일마다 패턴 검색
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// 파일에서 패턴을 찾아 해당 라인을 "파일명:내용"으로 출력
void search_in_file(const char *filename, const char *pattern) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, pattern))
            printf("%s:%s", filename, buffer);
    }
    fclose(fp);
}

// 디렉토리를 열어 하위 파일/디렉토리 탐색
void traverse(const char *dirpath, const char *pattern) {
    DIR *d = opendir(dirpath);
    if (!d) return;
    struct dirent *entry;
    char path[1024];
    struct stat st;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0) continue;
        snprintf(path, sizeof(path), "%s/%s", dirpath, entry->d_name);
        if (stat(path, &st) == -1) continue;
        if (S_ISDIR(st.st_mode)) {
            traverse(path, pattern);  // 디렉토리면 재귀 호출
        } else {
            search_in_file(path, pattern);  // 파일이면 내용 검색
        }
    }
    closedir(d);
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    traverse(".", argv[1]);  // 현재 디렉토리에서 탐색 시작
    return 0;
}
