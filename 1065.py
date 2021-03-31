n = int(input())
for i in range(1, 4):
    a, b, c = map(int, input().split(' '))
    if a + b > c:
        print('Case #{}: true'.format(i))
    else:
        print('Case #{}: false'.format(i))