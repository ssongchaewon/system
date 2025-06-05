/* 
 * cp_r.c: -r 옵션으로 디렉토리 복사 프로그램
 *   - 디렉토리인지 확인, 디렉토리면 재귀적으로 복사
 *   - mkdir로 대상 디렉토리 생성
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// 단일 파일 복사 함수
void copy_file(const char *src, const char *dst) {
    FILE *in = fopen(src, "rb");
    if (!in) return;
    FILE *out = fopen(dst, "wb");
    if (!out) { fclose(in); return; }

    char buf[4096];
    size_t n;
    while ((n = fread(buf,1,sizeof(buf),in)) > 0) {
        fwrite(buf,1,n,out);
    }
    fclose(in);
    fclose(out);
}

// 디렉토리 복사 함수 (재귀)
void copy_dir(const char *src, const char *dst) {
    mkdir(dst, 0755);  // 대상 디렉토리 생성
    DIR *d = opendir(src);
    if (!d) return;
    struct dirent *entry;
    char s_path[1024], d_path[1024];
    struct stat st;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,"..")==0) continue;
        snprintf(s_path, sizeof(s_path), "%s/%s", src, entry->d_name);
        snprintf(d_path, sizeof(d_path), "%s/%s", dst, entry->d_name);
        stat(s_path, &st);
        if (S_ISDIR(st.st_mode)) {
            copy_dir(s_path, d_path);  // 하위 디렉토리면 재귀 호출
        } else {
            copy_file(s_path, d_path);  // 파일이면 복사
        }
    }
    closedir(d);
}

int main(int argc, char *argv[]) {
    if (argc < 3) return 1;
    struct stat st;
    // 첫 번째 인자가 디렉토리인지 확인
    if (stat(argv[1], &st)==0 && S_ISDIR(st.st_mode)) {
        copy_dir(argv[1], argv[2]);
    } else {
        copy_file(argv[1], argv[2]);
    }
    return 0;
}
