//
//  main.c
//  q11718
//
//  Created by 위대연 on 12/7/25.
//

#include <stdio.h>
#include <string.h>

/**
 q11718 그대로 출력하기
 */


/*
void solution(void) {
    char temp[101] = "";
    for (int i = 0; i < 100; i++) {
        if (fgets(temp, sizeof(temp), stdin) == NULL) return;
        printf("%s", temp);
    }
    return;
}
*/

void solution(void) {
    char temp[101];
    while (fgets(temp, sizeof(temp), stdin) != NULL) {
        printf("%s", temp);
    }
}

int main(int argc, const char * argv[]) {
    solution();
    return 0;
}
