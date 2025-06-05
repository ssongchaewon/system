/* 
 * ls_R.c: -R 옵션처럼 디렉토리를 재귀적으로 탐색하여 모든 하위 파일/디렉토리 출력
 *   - list_dir 함수 재귀 호출
 *   - indent 매개변수로 깊이에 따른 들여쓰기 처리
 */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// 경로와 들여쓰기 레벨을 받아 디렉토리 목록을 출력
void list_dir(const char *path, int indent) {
    DIR *d = opendir(path);
    if (!d) return;
    struct dirent *entry;
    struct stat st;
    char fullpath[1024];
    // 디렉토리 엔트리 반복
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
        // 들여쓰기 출력 (깊이에 따라 공백 증가)
        for (int i = 0; i < indent; i++) printf("  ");
        printf("%s\n", entry->d_name);

        // 전체 경로 생성
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        // 디렉토리인지 확인 후 재귀 호출
        if (stat(fullpath, &st) == 0 && S_ISDIR(st.st_mode)) {
            list_dir(fullpath, indent+1);
        }
    }
    closedir(d);
}

int main(int argc, char *argv[]) {
    // 현재 경로에서 탐색 시작, 깊이 0
    list_dir(".", 0);
    return 0;
}
