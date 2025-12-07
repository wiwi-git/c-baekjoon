//
//  main.c
//  q10430
//
//  Created by 위대연 on 12/8/25.
//

#include <stdio.h>
/**
 q10430 나머지
 */

void solution(int a, int b, int c) {
    // 첫째 줄에 (A+B)%C
    printf("%d\n", (a+b)%c);
    // 둘째 줄에 ((A%C) + (B%C))%C
    printf("%d\n", ((a%c) + (b%c))%c);
    // 셋째 줄에 (A×B)%C
    printf("%d\n", (a*b)%c);
    // 넷째 줄에 ((A%C) × (B%C))%C
    printf("%d\n", ((a%c) * (b%c))%c);
}

int main(int argc, const char * argv[]) {
    int a,b,c = 0;
    scanf("%d %d %d", &a,&b,&c);
    solution(a,b,c);
    return 0;
}
