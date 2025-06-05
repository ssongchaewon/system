/* 
 * ls_r.c: -r 옵션처럼 알파벳 역순으로 파일 이름 출력
 *   - readdir로 읽은 후 배열에 저장, qsort로 역순 정렬
 */

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

// 파일 이름을 저장하는 구조체
typedef struct {
    char name[256];
} FileInfo;

// 이름 내림차순 비교 함수
int cmp(const void *a, const void *b) {
    FileInfo *fa = (FileInfo*)a;
    FileInfo *fb = (FileInfo*)b;
    return strcmp(fb->name, fa->name);
}

int main(int argc, char *argv[]) {
    DIR *d = opendir(".");
    if (!d) return 1;

    struct dirent *entry;
    FileInfo arr[1024];
    int count = 0;
    // 디렉토리 엔트리 배열에 저장
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        strcpy(arr[count].name, entry->d_name);
        count++;
    }
    closedir(d);
    // 이름 기준으로 역순 정렬
    qsort(arr, count, sizeof(FileInfo), cmp);
    // 정렬된 이름 출력
    for (int i = 0; i < count; i++) {
        printf("%s  ", arr[i].name);
    }
    printf("\n");
    return 0;
}
