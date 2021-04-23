n = int(input())
costs= []
str = input()
for i in str.split('')

costs.sort()

for i in range(1, n+1, 1):
    costs[i] += costs[i-1]

max_sum = max(costs)
min_sum = min(costs)

dict_cost = {}
for v in range(min_sum, max_sum + 1, 1):
    i = 0
    j = 1
    while not(costs[i] <= v < costs[j]):
        i+=1
        j+=1

    dict_cost[v] = (i+1)

q = int(input())
values = []
for i in range(q):
    values.append(int(input()))

for v in values:
    if v < min_sum:
        print(0)
    elif v >= max_sum:
        print(n)
    else:
        print(dict_costs[v])
    