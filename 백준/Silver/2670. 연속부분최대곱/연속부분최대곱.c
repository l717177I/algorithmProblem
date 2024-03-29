#include <stdio.h>

int N;
double D[10000+10];
void InputData(void)
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%lf", &D[i]);
}

double Solve(void)
{
    double x, max; // 다음 연산에 사용할 피곱셈연산자(?), 최댓값, 곱셈 값 저장할 변수
    x = max = D[0]; // 초기화.

    for(int i=1; i<N; i++)
    {
        x *= D[i];
        if (x <= D[i]) x = D[i];
        if (x > max) max = x; // 9.0 0.1 0.1 0.1 .... 이렇게 최대값이 하나만 있는 case는 9.0이 정답
    }
    return max;
}

int main(void)
{
    double ans = -1;
    InputData();    // 입력받는 부분
    ans = Solve();
    printf("%.3lf\n", ans); // 출력하는 부분
    return 0;
}