//
//  main.c
//  q1924
//
//  Created by 위대연 on 12/6/25.
//

#include <stdio.h>
#include <string.h>
/**
 q1924 2007년
 */
/*
void solution(void) {
    // 1. month, day 입력받기 int, int
    int month = 0;
    int day = 0;
    
    scanf("%d %d", &month, &day);
    
    // 2. 입력받은 날짜를 1월 + 지난 일수로 변경
    int temp = 0;
    for (int i = 1; i < month; i++) {
        //  4, 6, 9, 11 월은  30일까지 2월은 28일까지
        switch (i) {
            case 2:
                temp += 28;
                break;
            case 4: case 6: case 9: case 11:
                temp += 30;
                break;
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                // 1~12까지만 들어올텐데 굳이 필요없을지도?
                temp += 31;
                break;
            default: break;
        }// switch
    }// for
    
    char result[4] = {};
    
    // 3. 요일 계산 SUN, MON, TUE, WED, THU, FRI, SAT
    int rema = (day+temp) % 7;
    switch (rema) {
        case 0:
            strcpy(result, "SUN");
            break;
        case 1:
            strcpy(result, "MON");
            break;
        case 2:
            strcpy(result, "TUE");
            break;
        case 3:
            strcpy(result, "WED");
            break;
        case 4:
            strcpy(result, "THU");
            break;
        case 5:
            strcpy(result, "FRI");
            break;
        case 6:
            strcpy(result, "SAT");
            break;
        default:
            strcpy(result, "ERR");
            break;
    }
    
    // 4. 출력 형식에 맞춰 출력 딱히 뭐없었네 그냥 출력했어도 됐겠다
    printf("%s\n", result);
    return;
}


int main(int argc, const char * argv[]) {
    solution();
    return 0;
}
*/

void solution(void) {
    int month, day;
    scanf("%d %d", &month, &day);

    // 2007년의 각 월 일수
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 시작 요일 배열
    const char *week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int total = 0;
    for (int i = 0; i < month - 1; i++)
        total += daysInMonth[i];

    total += day;

    printf("%s\n", week[total % 7]);
}

int main(int argc, const char * argv[]) {
    solution();
    return 0;
}

