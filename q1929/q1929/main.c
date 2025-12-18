//
//  main.c
//  q1929
//
//  Created by 위대연 on 12/15/25.
//

#include <stdio.h>
/**
 q1929 소수 구하기
 문제
 M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

 입력
 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

 출력
 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
 */

void printPrime(int min, int max) {
    if (min < 2) min = 2;

    for (int i = min; i <= max; i++) {
        int isPrime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        
        if (isPrime) printf("%d\n", i);
    }
}

int main(int argc, const char * argv[]) {
    int min = 0, max = 0;
    while (scanf("%d %d", &min, &max) == 2) {
        printPrime(min, max);
    }
    return 0;
}
