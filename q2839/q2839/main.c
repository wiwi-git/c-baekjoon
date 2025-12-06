//
//  main.c
//  q2839
//
//  Created by 위대연 on 12/7/25.
//

#include <stdio.h>
#include <stdbool.h>

/**
 q2839 설탕 배달
 */

#define BIG 5
#define SMALL 3

void solution(int n) {
    // 1. N을 입력받는다.
    
    // 2. 5와3 으로 나누고 나머지를 남긴다
    int big = n / BIG;
    int rBig = n % BIG;
    int small = rBig / SMALL;
    int rSmall = rBig % SMALL;
    
    while(rBig != 0 && rSmall != 0) {
        // big에서 하나씩 줄여서 small을 늘리는식으로 반복해보자
        big -= 1;
        rBig += BIG;
        if (big < 0) {
            // big을 아무리 줄여도 정상적인 값이 나오지 않는 경우 -1
            printf("-1\n");
            return;
        }
        
        small = rBig / SMALL;
        rSmall = rBig % SMALL;
    }
    

    // 3. 결과 출력
    printf("%d\n", big + small);

    return;
}

int main(int argc, const char * argv[]) {
    int n = 0;
    scanf("%d", &n);
    
    solution(n);
        
    return 0;
}
