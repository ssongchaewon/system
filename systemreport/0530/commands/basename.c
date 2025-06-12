/*
 * basename.c
 *
 * 설명:
 *  - 이 프로그램은 주어진 파일 경로에서 파일 이름(즉, 마지막 경로 구성 요소)만 추출하여 출력합니다.
 *  - 예를 들어, "/usr/bin/gcc" 라는 경로가 주어지면 "gcc" 를 출력합니다.
 *  - 표준 C 라이브러리의 <libgen.h>에 포함된 basename() 함수를 사용합니다.
 * 
 * 사용법:
 *  ./basename [경로]
 * 
 * 예시:
 *  ./basename /home/user/test.txt
 *  → 출력: test.txt
 */

#include <stdio.h>      // 표준 입출력 함수 (printf 등)
#include <libgen.h>     // basename 함수가 선언된 헤더 파일

int main(int argc, char *argv[]) {
    // 인자가 2개 미만이면 (즉, 경로를 인자로 받지 않으면) 프로그램 종료
    if (argc < 2) {
        fprintf(stderr, "사용법: %s [경로]\n", argv[0]);
        return 1;
    }

    // basename 함수는 입력된 경로 문자열에서 마지막 구성 요소를 반환
    // 예: "/usr/local/bin/gcc" → "gcc"
    char *b = basename(argv[1]);

    // 추출된 파일 이름 출력
    printf("%s\n", b);

    return 0;  // 프로그램 정상 종료
}
