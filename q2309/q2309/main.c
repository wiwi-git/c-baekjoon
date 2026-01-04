//
//  main.c
//  q2309
//
//  Created by 위대연 on 1/5/26.
//

#include <stdlib.h>
#include <stdio.h>

/**
 q2309 일곱 난쟁이 스페셜 저지
 */
void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/// 오름차순 버블말곤 기억이 안난다
void sort(int * arr, int size) {
    for (int i = 0; i < size - 1; i ++) {
        for (int j = 0; j < size - 1 - i; j ++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}



int main(int argc, const char * argv[]) {
    int size = 9;
    int target[size];
    int index = 0;
    int sum = 0;
    
    while (index < size && scanf("%d",&target[index]) != EOF) {
        sum += target[index];
        index++;
    }
    
    sort(target, size);
    
    int otherIndex0 = -1, otherIndex1 = -1;
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (sum - target[i] - target[j] == 100) {
                otherIndex0 = i;
                otherIndex1 = j;
                break;
            }
        }
        if (otherIndex0 != -1) break;
    }
    
    for (int i = 0; i < size; i ++) {
        if (i == otherIndex0 || i == otherIndex1) continue;
        printf("%d\n", target[i]);
    }
    
    return EXIT_SUCCESS;
}
