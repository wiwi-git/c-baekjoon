//
//  main.c
//  q3085
//
//  Created by 위대연 on 1/6/26.
//

#include <stdlib.h>
#include <stdio.h>
/**
 q3085 사탕 게임

 */


int cMax = 0, pMax = 0, zMax = 0, yMax = 0;

/// value, count
struct CandyLog {
    char value;
    int count;
};

void updateMaxValue(struct CandyLog log) {
    switch (log.value) {
        case 'C':
            if (cMax < log.count) cMax = log.count;
            break;
        case 'P':
            if (pMax < log.count) pMax = log.count;
            break;
        case 'Z':
            if (zMax < log.count) zMax = log.count;
            break;
        case 'Y':
            if (yMax < log.count) yMax = log.count;
            break;
        default:
            break;
    }
}

void swap(char * a, char * b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void countCandy(int width, char board[][width]) {
    // 가로를 먼서 세고
    for (int i = 0; i < width; i ++) {
        struct CandyLog log = {'\0', 1};
        // 행
        for (int k = 0; k < width; k ++) {
            // 열
            struct CandyLog current = { board[i][k], 1};
            if (log.value == current.value) {
                log.count ++;
                if (k == width - 1) updateMaxValue(log);
            } else {
                updateMaxValue(log);
                log = current;
            }
        }// for 열 반복
    }
    
    // 세로를 다음에 센다
    for (int i = 0; i < width; i ++) {
        struct CandyLog log = {'\0', 1};
        // 열
        for (int k = 0; k < width; k ++) {
            // 행
            struct CandyLog current = {board[k][i], 1};
            if (log.value == current.value) {
                log.count ++;
                if (k == width - 1) updateMaxValue(log);
            } else {
                updateMaxValue(log);
                log = current;
            }
        }// for 열 반복
    }
}
 
int main(int argc, const char * argv[]) {
    // 1. 입력받고
    
    int width = 0;
    if (scanf("%d", &width) == EOF) {
        return -1;
    }
    
    char board[width][width];
    for (int i = 0; i < width; i++) {
        char temp[width];
        scanf("%s", temp);
        for (int j = 0; j < width; j ++) {
            board[i][j] = temp[j];
        }
    }
    
    /**
     5
     YCPZY
     CYZZP
     CCPPP
     YCYZC
     CPPZZ
     */
    /*
    int width = 5;
    char board[5][5] = {
        { 'Y','C','P','Z','Y' },
        { 'C','Y','Z','Z','P' },
        { 'C','C','P','P','P' },
        { 'Y','C','Y','Z','C' },
        { 'C','P','P','Z','Z' }
    };*/
    /*
    int width = 3;
    char board[3][3] = {
        {'C','C','P'},
        {'C','C','P'},
        {'P','P','C'}
    };
    */
    // 2. 가장 연속된게 긴애를 찾자 -> 1칸식 비어서 나오는거면? 어떻게 할건데 -> 그럼 다른 애들도 1칸이상씩 비어있겠지 인접한걸 찾아야할테고 그런데 그럼 무조건 1아니면 3아닌가?
    /**
     CCP
     CCP
     PPC
     빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y
     */
    
    // 가로끼리 스왑할때
    for (int i = 0; i < width; i ++) {
        for (int k = 0; k < width - 1; k ++) {
            if (board[i][k] == board[i][k+1]) {
                // 같은 값이면?
                continue;
            }
            swap(&board[i][k], &board[i][k+1]);
            countCandy(width, board);
            swap(&board[i][k], &board[i][k+1]);
        }
    }
    // 세로끼리 스왑할때
    for (int i = 0; i < width; i ++) {
        for (int k = 0; k < width - 1; k ++) {
            if (board[k][i] == board[k+1][i]) {
                // 같은 값이면?
                continue;
            }
            swap(&board[k][i], &board[k+1][i]);
            countCandy(width, board);
            swap(&board[k][i], &board[k+1][i]);
        }
    }
    
    int arr[4] = {cMax, pMax, zMax, yMax};
    int maxVal = arr[0];
    for (int i = 1; i < 4; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    
    printf("%d\n", maxVal);
    
    return EXIT_SUCCESS;
}
