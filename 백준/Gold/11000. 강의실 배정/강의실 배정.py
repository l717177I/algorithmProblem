import sys, heapq
input = sys.stdin.readline

n = int(input())
endTime= []
classTime = []
for i in range(n):
    start,end = map(int,input().split())
    classTime.append((start,end))

# 이문제 핵심은 끝나는 시간하고 시작하는 시간을 비교하는 것
# 시작하는 시간을 오름차순으로 정렬해준다. 그러면? 끝나는 시간만 비교하면 되는데
# 끝나는 시간도 끝나는 순서대로 비교해야하는데  모든 강의 끝나는 시간을 비교할 순 없다.
classTime.sort()

heapq.heappush(endTime,classTime[0][1])
cnt = 1
for i in range(1,n):
    # 언제추가?
    # 강의실이 필요한 경우는 끝나는 정렬 했을 때, 끝나는 시간 보다 시작하는 시간이 빠른 경우 추가가 되어야 하고
    # 끝나는 시간 보다 느리면 한 강의실에서 수업을 할 수 있다.
    if classTime[i][0] < endTime[0]:
        heapq.heappush(endTime,classTime[i][1])
        # 그냥 endTime length로 해도 될듯
        cnt += 1
    else:
        heapq.heappop(endTime)
        heapq.heappush(endTime,classTime[i][1])

print(cnt)