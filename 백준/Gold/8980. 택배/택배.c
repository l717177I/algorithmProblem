#include <stdio.h>
#include <stdlib.h>
int N, C, M;    // 마을 수, 트럭의 용량, 본부에서 준 정보
int truck_state[2000+10] = {0};  // 마을별 트럭의 상태를 나타내는 배열
typedef struct
{
    int s, e, box;   // 시작점, 목적지, 박스
} TRUCK;
TRUCK truck[10000+10];

// 보기싫어서 메인 아래에다가 정의
int compare(const void *a, const void *b);
void InputData(void);

int Solve(void)
{
    int i, j, ans = 0;
    qsort(truck, M, sizeof(truck[0]), compare);

    for (i=0; i<M; i++)
    {
        int start = truck[i].s; // 배송지
        int end = truck[i].e;   // 목적지
        int tmp = truck[i].box; // 현재 트럭에 넣을(혹은 넣고싶은) 박스 수
        // truck_state에 그때그때 추가할 수 있는 만큼 배송이 가능함.
        for (j=start; j<end; j++)
        {
            if(C < tmp + truck_state[j])    // 만일 현재 트럭에 박스 다 넣을 때, 최대 용량 초과한다면?
            {
                // 최대 용량과 현재 트럭 상태의 차이 만큼만 트럭에 채워넣어준다.
                // j에서 트럭이 꽉 차 있으면 tmp는 0이 되니까 괜춘
                tmp = C - truck_state[j];   
            }
            // 초과 안하면 때려넣어주세요.
            truck_state[j] += tmp;
        }
        ans += tmp;
    }
    return ans;
}

int main(void)
{
    int ans = -1;
    InputData();// 입력받는 부분
    ans = Solve();
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}

// 구현 ============================================

int compare(const void *a, const void *b)
{
    TRUCK *x = (TRUCK *)a, *y = (TRUCK *)b;
    return x->e - y->e;
}

void InputData(void)
{
    int i;
    scanf("%d %d", &N, &C);
    scanf("%d", &M);
    for (i=0; i<M; i++)
    {
        scanf("%d %d %d", &truck[i].s, &truck[i].e, &truck[i].box);
    }
}