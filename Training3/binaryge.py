n = int(input())
str_binary = input()

def binary_to_decimal(str_binary):
    str_binary = str_binary[::-1]

    res = sum([int(str_binary[i])*pow(2,i) for i in range(len(str_binary))])

    return res

def decimal_to_binary(num):
    return bin(num).replace("0b", "")


max_value = pow(2, n) - 1
curr_value = binary_to_decimal(str_binary)
if curr_value == max_value:
    print(-1)
else:
    res = decimal_to_binary(curr_value+1)
    l = len(res)
    print('0'*(n-l)+res)
   