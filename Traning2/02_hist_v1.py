def find_max_S(A:list, n: int):
    max_S = 0

    for start in range(0, n, 1):

        for end in range(start, n, 1):
            min_height = min(A[start:end+1])
            S = min_height * (end - start +1)
            max_S = max(S, max_S)

    return max_S

res = []
while True:
    lines = input()
    numbers = [int(n) for n in lines.split() if n!= '']
    # print(numbers)
    if numbers[0] == 0:
        break

    n = numbers[0]
    A = numbers[1:]
    res.append(find_max_S(A, n))

for r in res:
    print(r)