//
//  q17478.c
//  baekjoon
//
//  Created by 위대연 on 12/1/25.
//

#include <stdio.h>
#include "q17478.h"

/**
 17478번 재귀함수가 뭔가요?
 */

void _print(int tabCount, const char *msg) {
    // ____
    int prefixSize = 4 * tabCount;
    char prefix[prefixSize+1];
    
    for (int i = 0; i < prefixSize; i ++) {
        prefix[i] = '_';
    }
    // TODO: 문자열 마지막을 직접 체크해줘야 했었나?
    prefix[prefixSize] = '\0';
    
    printf("%s%s\n",prefix, msg);
}


void recursive(int depth, int last) {
    _print(depth, "\"재귀함수가 뭔가요?\"");
    
    // 선인의 답
    if (depth == last) {
        _print(depth, "\"재귀함수는 자기 자신을 호출하는 함수라네\"");
    } else {
        _print(depth, "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
        _print(depth, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
        _print(depth, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
        int newDepth = depth + 1;
        recursive(newDepth, last);
    }
    _print(depth, "라고 답변하였지.");
    return;
}

void solution(void) {
    int count = 0;
    scanf("%d", &count);
    
    // 도입문
    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    printf("\"재귀함수가 뭔가요?\"\n");
    
    // 교수님!
    printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
    
    // 선인과의 대화
    recursive(1, count);
    
    // 교수님 답변 끝!
    printf("라고 답변하였지.\n");
    return;
}
