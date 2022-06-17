import sys
fastin = sys.stdin.readline


def binary_search_2(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return 1
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return 0


testcase = int(input())
for _ in range(testcase):
    '''
    1 ≤ n, m ≤ 1,000,000, 1 ≤ m ≤ 1,000,000
    모든 정수의 범위: int (~=INF)
    '''
    n = int(input())
    note_1 = list(map(int, fastin().split()))
    note_1.sort()
    m = int(input())
    note_2 = list(map(int, fastin().split()))
    for num in note_2:
        print(binary_search_2(note_1, num, 0, n-1))
