//
//  main.c
//  q1978
//
//  Created by 위대연 on 12/15/25.
//

#include <stdio.h>
/**
 q1978 소수 찾기
 */
int solution(int *values, int nSize) {
    int count = 0;

    for (int i = 0; i < nSize; i++) {
        int value = values[i];

        if (value == 1) continue;

        int isPrime = 1;
        for (int j = 2; j * j <= value; j++) {
            if (value % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) count++;
    }

    return count;
}


int main(int argc, const char * argv[]) {
    int n = 0;
    while (scanf("%d", &n) == 1) {
        int values[n];
        for (int i = 0; i < n; i ++) {
            scanf("%d", &values[i]);
        }
        
        int count = solution(values, n);
        printf("%d\n", count);
    }
    
    return 0;
}
//  2, 3, 5, 7, 11, 13, 17
