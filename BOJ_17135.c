#include <stdio.h>
#include <math.h>
int n, m;
void inputData(void)
{
    scanf("%d %d ", &n, &m);
}
int main(void)
{
    return 0;
}
/*
1. 턴마다 궁수는 적 하나 공격
 - 모든 궁수는 동시에 공격
2. 궁수가 공격하는 적은 거리 D 이하 중 가장 가까운 적
 - 여러 명이 해당되면 가장 왼쪽 적 공격
 - 같은 적이 여러 궁수한테 당할 수 있음
3. 궁수 의 공격이 끝나면, 적은 아래로 한 칸 이동.
4. 모든 적이 아래로 내려가면 게임 끝!
※ 궁수는 3명!
문제 링크 : https://www.acmicpc.net/problem/17135
*/
