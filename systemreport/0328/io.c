#include <stdio.h>
#include <ctype.h> 

int main() {
    char ch;

    while (1) {
        printf("문자 입력: ");
        scanf(" %c", &ch); 

        if (ch == '0') {
            break; 
        }
        if (isupper(ch)) {
            printf("%c의 소문자는 %c입니다.\n", ch, tolower(ch));
        }
        else if (islower(ch)) {
            printf("%c의 대문자는 %c입니다.\n", ch, toupper(ch));
        } else {
            printf("대문자나 소문자가 아닌 문자가 입력되었습니다.\n");
        }
    }

    return 0;
}