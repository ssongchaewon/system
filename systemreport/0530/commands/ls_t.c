/* 
 * ls_t.c: -t 옵션처럼 수정된 시간 순서대로 파일 이름 출력
 *   - stat을 사용해 수정 시간을 얻고, qsort로 정렬
 */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 파일 이름과 수정 시간을 저장하는 구조체
typedef struct {
    char name[256];
    time_t mtime;
} FileInfo;

// 수정 시간 내림차순 정렬 비교 함수
int cmp(const void *a, const void *b) {
    FileInfo *fa = (FileInfo*)a;
    FileInfo *fb = (FileInfo*)b;
    return (fb->mtime - fa->mtime) > 0 ? 1 : -1;
}

int main(int argc, char *argv[]) {
    DIR *d = opendir(".");
    if (!d) return 1;

    struct dirent *entry;
    FileInfo arr[1024];
    int count = 0;
    struct stat st;
    // 파일 정보 배열에 저장
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        if (stat(entry->d_name, &st) == -1) continue;
        strcpy(arr[count].name, entry->d_name);
        arr[count].mtime = st.st_mtime;
        count++;
    }
    closedir(d);
    // 수정 시간 기준으로 정렬
    qsort(arr, count, sizeof(FileInfo), cmp);
    // 정렬된 이름 출력
    for (int i = 0; i < count; i++) {
        printf("%s  ", arr[i].name);
    }
    printf("\n");
    return 0;
}
