// 왜 BinarySearch를 선택해야 되는가?
//  1) N과 M의 최댓값은 10^5
//  2) K와 M은 반비례.
//  3) 즉 K가 클수록 M은 작음
//  4) K를 일단 엄청 큰 숫자로 업데이트 한 후 계속 줄여나간다
#include <stdio.h>
#include <stdlib.h>
#define MAX_N (100000)
int N, M;   // 1 ≤ N ≤ 100,000, 1 ≤ M ≤ N
int need[MAX_N];
int max_won;

void Input_Data(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N;i++)
    {
		scanf("%d", &need[i]);
        max_won = need[i]>max_won? need[i]:max_won;
	}
}

int Solve(void)
{
    int K = max_won;  // 초기값은 최댓값으로 
    int left = max_won, right = 100000*10000;  // 통장 잔고는 무한대. 
    while(left <= right)
    {
        int i, day = 0;             // index, 인출해야되는날들(=인출횟수)
        int mid = (left+right) / 2; // 일단 중심값만큼 초기화
        int wallet = 0;             // 지갑. 초기에는 0원.
        
        for(i=0; i<N; i++)  // 통장 인출 시작
        {
            if (wallet < need[i]) // 인출해야되는 상황이면 
            {
                wallet = mid;   // wallet를 mid만큼 업데이트
                day += 1;       // 인출 횟수 업뎃
            }
            wallet -= need[i];  // 아님 지갑에서 빼감
        }
        
        if (day <= M)   // 인출 횟수가 M보다 작으면
        {
            K = mid;    // K는 현 mid값
            right = mid - 1;    // right값을 줄입시다.
        }
        else left = mid + 1;
    }
    return K;
}

int main(void)
{
	int sol = -1;
	Input_Data();
	sol = Solve();
	printf("%d\n", sol);
	return 0;
}