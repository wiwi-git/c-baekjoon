//
//  main.c
//  q4375
//
//  Created by 위대연 on 12/8/25.
//

#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>

/**
 q4375 1
 */
/*
int intLength(int n) {
    char buffer[100];
    sprintf(buffer, "%d", n);
    int nLength = (int)strlen(buffer);
    return nLength;
}

int solution(int n) {
    // 1. str을 짤라서 할지 그대로 할지 타겟을 정함 - 짜르는 기준 n의 글자수 + 1 보다 큰가
    char str[100] = "1";
    int nLength = intLength(n);
    int targetLength = nLength + 1;
    int currentIndex = 0;
    
    while (1) {
        int strLength = (int)strlen(str);
        char target[8] = "";
        if (strLength > targetLength) {
            strncpy(target, str, targetLength);
            target[targetLength] = '\0';
        } else {
            strcpy(target, str);
            target[targetLength] = '\0';
        }
        currentIndex = targetLength;
        
        int innerFlag = 1;
        while (innerFlag) {
            // 2. 정해진 타겟을 atoi로 int형으로 변환
            int i = atoi(target);
            if (i <= 0) {
                printf("err : %s\n", target);
                return 0;
            }
            
            // 3. 변환한 값 % n 값을 구함
            int remain = i % n;
            
            // 4. 정해진 타겟뒤에 str값이 더 있는지 확인함
            if (strLength > currentIndex) {
                // 5. 더 있으면 나머지값에 추가 문자열을 붙여서 2번 타겟으로 반복
                char temp[8] = "";
                char back[3] = {str[currentIndex],'\0'};
                sprintf(temp, "%d", remain);
                strcat(temp, back);
                strcpy(target, temp);
                currentIndex ++;
                // 2번 복귀,, 복귀를 어떻게 하지? 고투문도 아니고...
                continue;
            } else if (remain == 0){
                // 6. 정해진 타겟뒤에 str값이 없으면 나머지값이 0인지 확인
                // 찾기 성공!
                return (int)strlen(str);
            } else {
                // 7. 나머지값이 0이 아니면 str값에 "1"을 덧붙여서 1번 str로 복귀
                strcat(str, "1");
                // 1번 복귀
                innerFlag = 0;
            }
        }// inner loop
    }// while
    
    return 0;
}

*/

int solution(int n) {
    int remain = 1 % n;
    int count = 1;
    
    while (remain != 0) {
        remain = (remain * 10 + 1) % n;
        count ++;
    }
    
    return count;
}


int main(int argc, const char * argv[]) {
//    int n = 0;
//    scanf("%d", &n);
//    int result = solution(n);
    
//    clock_t start = clock();
//    
//    int testValues[] = { 3,7, 9901 };
//    int checkAnswer[] = { 3, 6, 12 };
//    int exCount = sizeof(testValues) / sizeof(testValues[0]);
//    
//    for (int i = 0; i < exCount; i++) {
//        int value = testValues[i];
//        int result = solution(value);
//        if (result != checkAnswer[i]) {
//            printf("ERR: 예상 값이 같지 않음. %d > %d\n", value, result );
//            return -1;
//        }
//    }
//    
//    clock_t end = clock();
//    double duration = (double)(end - start) / CLOCKS_PER_SEC;
//    
//    printf("실행 시간: %lf\n", duration);
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", solution(n));
    }

    return 0;
}
