//
//  main.c
//  q2609
//
//  Created by 위대연 on 12/15/25.
//
/**
 q2609 최대공약수와 최소공배수
 */
#include <stdio.h>


// 최대공약수 유클리드 호제법
long calcGCD(long num1, long num2) {
    long a,b;
    
    if (num1 > num2) {
        a = num1;
        b = num2;
    } else {
        a = num2;
        b = num1;
    }
    
    if (b == 0) return a;
    return calcGCD(b, a % b);
}

// 최소공배수 gcd이용 버전
long calcLCM(long num1, long num2) {
    long a,b;
    
    if (num1 > num2) {
        a = num1;
        b = num2;
    } else {
        a = num2;
        b = num1;
    }
    
    return (a / calcGCD(a, b)) * b;
}
 

int main(int argc, const char * argv[]) {
    
    long num1,num2;
    
    while (scanf("%ld %ld", &num1, &num2) == 2) {
        long gcd = calcGCD(num1, num2);
        long lcm = calcLCM(num1,num2);
        printf("%ld\n%ld\n", gcd, lcm);
    }
    
    return 0;
}
