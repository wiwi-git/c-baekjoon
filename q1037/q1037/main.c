//
//  main.c
//  q1037
//
//  Created by 위대연 on 12/11/25.
//
/**
 q1037 약수
 */
#include <stdio.h>

int solution(int size, int divisors[]) {
    int min = divisors[0];
    int max = divisors[0];
    
    for (int i = 0; i < size; i++) {
        int value = divisors[i];
        if (max < value) {
            max = value;
        }
        if (min > value) {
            min = value;
        }
    }
    return min * max;
}


int main(int argc, const char * argv[]) {
//    int values[4][14] = {
//        {4, 2},
//        {2},
//        {3, 4, 2, 12, 6, 8},
//        {14, 26456, 2, 28, 13228, 3307, 7, 23149, 8, 6614, 46298, 56, 4, 92596}
//    };
//    
//    int correct[4] = {
//        8, 4, 24,185192
//    };
//    
//    int sizes[4] = {2,1,6,14};
//    
//    for (int i = 0; i < 4; i ++) {
//        int * value = values[i];
//        int answer = correct[i];
//        int size = sizes[i];
//        
//        int result = solution(size, value);
//        
//        if (result != answer) {
//            printf("ERR: 예상값과 같지 않음 %d != %d", result, answer);
//            return 0;
//        }
//    }
    
    int size;

    while (scanf("%d", &size) != EOF) {

        int divisor[size];
        for (int i = 0; i < size; i++) {
            scanf("%d", &divisor[i]);
        }

        printf("%d\n", solution(size, divisor));
    }

    return 0;
}
