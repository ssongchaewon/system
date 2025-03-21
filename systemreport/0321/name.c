#include <stdio.h>

int main() {
    char studentID[20]; 
    char name[50];    

    printf("학번을 입력하세요: ");
    scanf("%s", studentID); 

    printf("이름을 입력하세요: ");
    scanf("%s", name);

    printf("학번: %s\n", studentID);
    printf("이름: %s\n", name);

    return 0;
}
