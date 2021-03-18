def parentheses(sample:str):
    s:list = []
    pairs = {']':'[', '}':'{', ')':'('}

    count = 0
    for letter in sample:
        count += 1
        if letter in ['[', '{', '(']:
            s.append(letter)
            continue

        top = s[-1]
        if letter in [']', ')', '}'] and pairs[letter] == top:
            is_valid = True
            count -= 2
            s.pop()

    if s==[] and count == 0:
        return 1
    else:
        return 0


n = int(input())
A = []
for i in range(n):
    A.append(input())

for i in range(n):
    print(parentheses(A[i]))