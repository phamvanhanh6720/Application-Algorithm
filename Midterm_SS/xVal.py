n = int(input())
res = 0

for i in range(n):
    str = input()
    if "++" in str:
        res += 1
    else:
        res -= 1

print(res)