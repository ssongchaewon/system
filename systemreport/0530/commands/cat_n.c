/*
 * cat_n.c
 *
 * 설명:
 *  - 이 프로그램은 표준 입력(stdin)으로부터 텍스트를 한 줄씩 읽어서,
 *    각 줄 앞에 줄 번호를 붙여 표준 출력(stdout)으로 출력합니다.
 *  - UNIX의 `cat -n` 명령어와 유사한 동작을 수행합니다.
 *  - 줄 번호는 1부터 시작하여 한 줄이 출력될 때마다 1씩 증가합니다.
 * 
 * 사용법:
 *  ./cat_n
 * 
 * 사용 예시:
 *  ./cat_n
 *  → 사용자가 입력한 각 줄 앞에 줄 번호를 붙여 출력함 (입력 종료는 Ctrl+D)
 * 
 *  echo -e "hello\nworld" | ./cat_n
 *  → 출력:
 *       1  hello
 *       2  world
 */

#include <stdio.h>  // 표준 입출력 함수 사용을 위한 헤더 파일

int main(int argc, char *argv[]) {
    char buffer[1024];  // 한 줄의 입력을 저장할 버퍼 (최대 1023자 + 널문자)
    int line_no = 1;    // 줄 번호를 저장할 변수 (1부터 시작)

    // 표준 입력으로부터 한 줄씩 읽어올 때까지 반복
    while (fgets(buffer, sizeof(buffer), stdin)) {
        // fgets:
        //  - 최대 sizeof(buffer) - 1 만큼 문자열을 읽고 '\n' 포함
        //  - 문자열 끝에 '\0' 추가
        //  - 입력이 끝나면 NULL 반환

        // 현재 줄 번호를 출력한 뒤, 읽어온 문자열 출력
        // 줄 번호는 오른쪽 정렬(6자리)로 출력
        printf("%6d  %s", line_no++, buffer);
        // 예시 출력:
        //      1  첫 번째 줄 내용
        //      2  두 번째 줄 내용
    }

    return 0;  // 프로그램 정상 종료
}
