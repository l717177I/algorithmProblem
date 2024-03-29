#include <stdio.h>
#define MAX(x, y) (x)>(y)? (x):(y)  // 최댓값 구하는 매크로함수
#define MAXDISH 3000    // 초밥의 가짓수
int N, D, K, C;
int sushi[3000000+MAXDISH+10];  // 초밥 접시들, Sliding Window 사용하기 위해 dishesCheck 사이즈만큼 늘려줌
int dishesCheck[MAXDISH + 10] = { 0 };  // 초밥 몇종류 먹었는지 체크하기 위한 배열

void InputData(void)
{
    scanf("%d %d %d %d", &N, &D, &K, &C);
    for (int i=0; i<N; i++) scanf("%d", &sushi[i]);
}

int Solve(void) // 총 시간복잡도는 O(N+K)
{
    int i, max_sushi = 1, cnt = 1;
    dishesCheck[C] = 1; // 초밥 쿠폰 처리
    // 1. SlidingWindows 기법 사용
    for (i=0; i<K; i++) // K만큼 초밥 먹기
    {
        if (dishesCheck[sushi[i]] == 0) cnt++; // 새로운 초밥이라면 카운팅
        dishesCheck[sushi[i]] += 1; // 종류에 카운팅
        sushi[N+i] = sushi[i]; // 배열 뒤에 추가
    }

    // 2. K 만큼 Sliding Window
    for (i=0; i<N; i++)
    {
        dishesCheck[sushi[i]] -= 1;
        if (dishesCheck[sushi[i]] == 0) cnt--; // 해당 초밥 먹은게 짤린 경우
        if (dishesCheck[sushi[i+K]] == 0) cnt++; // k개만큼 초밥을 처음 먹은 경우
        dishesCheck[sushi[i+K]] += 1;
        max_sushi = MAX(max_sushi, cnt);    // 최대 가짓수만큼 갱신
    }
    return max_sushi;
}

int main(void)
{
    int ans = -1;
    InputData();    // 입력받는 부분
    ans = Solve();
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}