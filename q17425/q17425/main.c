//
//  main.c
//  q17425
//
//  Created by 위대연 on 12/13/25.
//

#include <stdio.h>
/**
 q17425 약수의합
 
 첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 100,000)가 주어진다. 둘째 줄부터 테스트 케이스가 한 줄에 하나씩 주어지며 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
 */


#define MAX 1000000

long long f[MAX + 1];
long long g[MAX + 1];

long long solution(long n) {
    // f[1] ~ f[n] 까지의 합
    long long g = 0;
    for (int i = 1; i <= n; i++) {
        g += f[i];
    }
    return g;
}

void setupEratos(long max) {
    // 각 i의 배수들의 합을 f배열에 저장
    for (int i = 1; i <= max; i ++) {
        for (int j = i; j <= max; j += i) {
            f[j] += i;
        }
    }
}

void setupSumArray(long max) {
    // g값을 미리 전부 계산
    for (int i = 1; i <= max; i++) {
        g[i] = g[i - 1] + f[i];
    }
}

int main(int argc, const char * argv[]) {
    long t;
    
    while (scanf("%ld", &t) == 1) {
        long nValues[100000] = {0};
        long max = 0;
        
        for (int i = 0; i < t; i ++) {
            scanf("%ld", &nValues[i]);
            if (nValues[i] > max) {
                max = nValues[i];
            }
        }
        
        // fx값 미리계산
        setupEratos(max);
        
        // gx값 미리계산
        setupSumArray(max);
        
        // 결과 출력
        for (int i = 0; i < t; i ++)
            printf("%lld\n", g[nValues[i]]);
    }
    
    return 0;
}
/**
 5
 1
 2
 10
 70
 10000
 */
