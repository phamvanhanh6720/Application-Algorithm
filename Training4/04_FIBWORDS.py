def count(s: str, pattern: str):
    if len(s) < len(pattern):
        return 0

    if s[:len(pattern)]==pattern:
        return 1 +  count(s[1:], pattern)
    else:
        return count(s[1:], pattern)


def preprocess():
    global F
    global occurs
    global signal
    global n, pattern, l_pattern

    F.append('0')
    occurs[0] = count('0', pattern)
    signal[0] = ['0', '0']

    F.append('1')
    signal[1] = ['1', '1']
    occurs[1] = count('1', pattern)

    i = 2
    while True:
        F.append(F[-1]+F[-2])
        occurs[i] = count(F[-1], pattern)

        if len(F[-1]) >= len(pattern):
            
            prefix = F[i-1][:min(l_pattern, len(F[i-1]))]
            posfix = F[i-1][-min(l_pattern, len(F[i-1])):]
            signal[i-1] = [prefix, posfix]

            prefix = F[i][:min(l_pattern, len(F[i]))]
            posfix = F[i][-min(l_pattern, len(F[i])):]
            signal[i] = [prefix, posfix]
            i += 1

            return i
        i += 1  

n = int(input())
pattern = input()
l_pattern = len(pattern)

occurs = [-1 for _ in range(n+1)]
signal = [["",""] for _ in range(n+1)]
F = []


s_point = preprocess()

for i in range(s_point, n+1, 1):
    n_exist1 = occurs[i-1]
    n_exist2 = occurs[i-2]

    prefix1 = signal[i-1][0]
    posfix1 = signal[i-1][1]

    prefix2 = signal[i-2][0]
    posfix2 = signal[i-2][1]

    if len(prefix1) < l_pattern or len(posfix1) < l_pattern or len(prefix2) < l_pattern or len(posfix2) < l_pattern:
        F.append(F[-1]+F[-2])

        prefix = F[i][:min(l_pattern, len(F[i]))]
        posfix = F[i][-min(l_pattern, len(F[i])):]
        signal[i] = [prefix, posfix]
        occurs[i] = count(F[-1], pattern)
        

    else:
        signal[i] = [prefix1, posfix2]
        union = posfix1 + prefix2
        
        total_exist = n_exist1 + n_exist2 + count(union, pattern) - count(posfix1, pattern) - count(prefix2, pattern)

        occurs[i] = total_exist


print("Case 1: {}".format(occurs[n]))

