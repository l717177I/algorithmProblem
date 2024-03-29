#include <stdio.h>
#define MAX(x, y) (x)>(y)?(x):(y)
int N;  // 히스토그램 수, 1 ≤ N ≤ 100,000
int H[100000 + 10];   // 히스토그램 높이, 0 ≤ hi ≤ 1000000000
// stack function ==============
typedef struct
{
    int idx, h;
} HISTO_INFO;
HISTO_INFO stack[100000 + 10];
int wp;
void push(int x, int idx)
{
    stack[wp].h = x;
    stack[wp++].idx = idx;
}
void pop(void) { wp--; }
int empty(void) { return wp == 0; }
int size(void) { return wp; }
HISTO_INFO front(void) { return stack[wp - 1]; }
// ==============================
 
int InputData(void)
{
    scanf("%d", &N);
    if (N == 0) return 0;
    for (int i = 0; i < N; i++) scanf("%d", &H[i]);
    return 1;
}
 
long long Solve(void)   // 1) 스택을 어떤 기준으로 push할것인지? 2) 넓이를 어떻게 구할것인지?
{
    int i;
    long long max_area = -1;
    wp = 0;
    for (i = 0; i < N; i++)
    {
        // 비어있거나, 들어올 HISTO_INFO가 기존것보다 크다면 무조건 push
        if (empty() || stack[wp - 1].h <= H[i])
        {
            push(H[i], i);
            continue;
        }
        else   // stack[wp - 1].h > H[i]
        {
            int idx = i;    // 인덱스 뺏어오기 용도
            while(!empty())
            {
                HISTO_INFO st = front();
                 
                if (st.h <= H[i]) break;
                idx = st.idx;
                max_area = MAX(max_area, (long long)st.h * (i - st.idx));  // 빼오면서 넓이 최댓값 갱신하기
                pop();
            }
            // if (idx > i) idx = i;   // 만약 앞에 인덱스가 더 적다면 뺏어오기
            push(H[i], idx);
        }
    }
 
    while (!empty())
    {
        HISTO_INFO st = front();
        max_area = MAX(max_area, (long long)st.h * (N-st.idx));
        pop();
    }
    return max_area;
}
 
int main(void)
{
    long long ans = -1;
    while (InputData())  //입력받는 부분
    {
        ans = Solve();
        printf("%lld\n", ans);//출력하는 부분
    }
    return 0;
}