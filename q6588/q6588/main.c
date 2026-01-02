//
//  main.c
//  q6588
//
//  Created by 위대연 on 1/3/26.
//

#include <stdlib.h>
#include <stdio.h>

/**
 q6588 골드바흐의 추측
 
 테스트 케이스는 짝수 정수 n 하나로 이루어져 있다. (6 ≤ n ≤ 1000000)
 입력의 마지막 줄에는 0이 하나 주어진다.
 */
#define MAX 1000000

long long p[MAX];
long long check[MAX] = {0};
long LAST = 0;

void setupPrime(int min, int max) {
    if (min < 2) min = 2;

    long pIndex = 0;
    
    for (int i = min; i <= max; i++) {
        int isPrime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        
//        if (isPrime) printf("%d\n", i);
        if (isPrime) {
            p[pIndex] = i;
            check[i] = 1;
            LAST = pIndex;
            pIndex ++;
        }
    }
}


/// n = a + b 형태로 출력
void findCombin(long n) {
    long pIndex = 0;
    
    while (pIndex < LAST) {
        long a = p[pIndex];
        long b = n - p[pIndex];
        if (check[b] == 1) {
            // 8 = 3 + 5
            printf("%lu = %lu + %lu\n", n, a, b);
            return;
        }
        pIndex ++;
    }
    
    printf("Goldbach's conjecture is wrong.");
    return;
}

int main(int argc, const char * argv[]) {
    setupPrime(3, MAX);
    
    long target = 0;
    while (scanf("%lu", &target) != EOF && target != 0) {
        findCombin(target);
    }
    
    return EXIT_SUCCESS;
}
