
count_dict = {'a': 1, 'b':2, 'c':3,
'd': 1, 'e':2, 'f':3,
'g': 1, 'h':2, 'i':3,
'j': 1, 'k':2, 'l':3,
'm': 1, 'n':2, 'o':3,
'p': 1, 'q':2, 'r':3, 's':4,
't': 1, 'u':2, 'v':3,
'w': 1, 'x':2, 'y':3, 'z':4, ' ':1}

n = int(input())
lines = []
for i in range(n):
    lines.append(input())

for i in range(n):
    line = lines[i]
    count = 0
    for letter in line:
        count += count_dict[letter]
    
    print("Case #{}: {}".format(i+1, count))