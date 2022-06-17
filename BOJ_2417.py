def binary_search(target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if mid**2 < target:
            start = mid + 1
        else:
            end = mid - 1
    return start


n = int(input())
print(binary_search(n, 0, n))
