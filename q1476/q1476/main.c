//
//  main.c
//  q1476
//
//  Created by 위대연 on 1/12/26.
//

#include <stdlib.h>
#include <stdio.h>

/**
 q1476 날짜 계산
 */

// k * 15 ... 10 == j * 28 ... 20 == n * 19 ... 12

#define EBASE 15
#define SBASE 28
#define MBASE 19

int match(int target, int base, int max) {
    int i = 0;
    while (1) {
        int mulTarget = base * i + target;
        i++;
        if (mulTarget == max) return 1;
        else if (mulTarget > max) return -1;
    }
    return -1;
}

/// param: sun, moon, earth
int findMulSun(int sun, int moon, int earth) {
    int i = 0;
    while (1) {
        int mulSun = 28 * i + sun;
        i ++;
        
        // find moon
        int matchResult = match(moon, MBASE, mulSun);
        if (matchResult == -1) {
            // 일치값을 찾지 못하고 값이 넘어섰다. mulSun값을 변화시켜 다시 시도
            continue;
        }
        
        // find earth
        matchResult = match(earth, EBASE, mulSun);
        if (matchResult == -1) {
            // 일치값을 찾지 못하고 값이 넘어섰다. mulSun값을 변화시켜 다시 시도
            continue;
        }
        
        // 값을 찾았음.
        return mulSun;
    }
}

int main(int argc, const char * argv[]) {
    int earth = 0, sun = 0, moon = 0;
    
    if (scanf("%d", &earth) == EOF) {
        // NZEC에러가 나서 EXIT_FAILURE에서 0으로 변경
        return 0;
    }
    
    scanf("%d", &sun);
    scanf("%d", &moon);
    
    // 우선 작은 애들은 그냥 넘기자
    // 1 ~ 15
    if (earth == sun && sun == moon) {
        printf("%d\n", earth);
        return EXIT_SUCCESS;
    }
     
    int result = findMulSun(sun, moon, earth);
    printf("%d\n", result);
    
    return EXIT_SUCCESS;
}
