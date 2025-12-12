//
//  main.c
//  q17427
//
//  Created by 위대연 on 12/12/25.
//

#include <stdio.h>

/**
 q17427 약수의 합 2
 
 시간 제한    메모리 제한    제출    정답    맞힌 사람    정답 비율
 0.5 초 (추가 시간 없음)    512 MB    15925    6308    5342    40.357%
 
 문제
 두 자연수 A와 B가 있을 때, A = BC를 만족하는 자연수 C를 A의 약수라고 한다. 예를 들어, 2의 약수는 1, 2가 있고, 24의 약수는 1, 2, 3, 4, 6, 8, 12, 24가 있다. 자연수 A의 약수의 합은 A의 모든 약수를 더한 값이고, f(A)로 표현한다. x보다 작거나 같은 모든 자연수 y의 f(y)값을 더한 값은 g(x)로 표현한다.

 자연수 N이 주어졌을 때, g(N)을 구해보자.

 입력
 첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

 출력
 첫째 줄에 g(N)를 출력한다.
 */
/*

/// x의 모든 약수의 합값을 반환하는 함수
int f(int x) {
    int sum = 1 + x;
    int stop = x;
    for (int i = 2; i < stop; i ++) {
        if (x % i == 0) {
            sum += i;
            stop = x / i;
            sum += stop;
        }
    }
    return sum;
}

/// 주어진 x 이하의 모든 자연수값을 f(x)에 넣고 더한값을 반환하는 함수
int g(int x) {
    int sum = 1;
    for (int i = x; i > 1; i --) {
        sum += f(i);
    }
    return sum;
}

int solution(int n) {
    return g(n);
}


 int main(int argc, const char * argv[]) {
 //    int values[5][2] = {
 //        { 1,1 },
 //        { 2,4 },
 //        { 10, 87 },
 //        { 70, 4065 },
 //        { 10000, 82256014 }
 //    };
 //
 //    for (int i = 0; i > 5; i ++) {
 //        int result = solution(values[i][0]);
 //        if (result != values[i][1]) printf("ERR: 잘못된 출력이 검출 되었습니다. %d != %d", result, values[i][1]);
 //    }
 
 int n = 0;
 while (scanf("%d\n", &n) == 1) {
 printf("%d\n", solution(n));
 }
 
 return 0;
 }
 */

#define MAX 1000000

long long f[MAX + 1];

long long solution(int n) {
    // 각 i의 배수들의 합을 f배열에 저장
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j += i) {
            f[j] += i;
        }
    }
    
    // f[1] ~ f[n] 까지의 합
    long long g = 0;
    for (int i = 1; i <= n; i++) {
        g += f[i];
    }
    return g;
}

int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d\n", &n) == 1) {
        printf("%lld\n", solution(n));
    }
    
    return 0;
}
