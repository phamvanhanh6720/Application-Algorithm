line1 = input()
m, b = [int(number) for number in line1.split(' ')]
line2 = input()
A = [int(n) for n in line2.split()]

res = -1

for i in range(1, m-1, 1):
    a_i = A[i]
    value_1 = max(A[0:i]) - a_i

    value_2 = max(A[i+1:]) - a_i

    if value_1 >= b and value_2 >=b:
        signal_v = value_1 + value_2
        res = max(signal_v, res)

print(res)