import math

def isPrime(x : int)->bool:
    if x == 2:
        return True
    elif x <= 1:
        return False
    else:
        for i in range(2, int(math.sqrt(x))):
            if x % i == 0:
                return False
        return True

l, k = map(int, input().split(' '))
num = input()

i = 0
flag = False
while i + k <= l:
    # print(num[i : i + k + 1])
    if isPrime(int(num[i : i + k])) == True:
        print(num[i : i + k])
        flag = True
        break

    i += 1

if not flag:
    print('404')