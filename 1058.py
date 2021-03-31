a, b = input().split(' ')
a1, a2, a3 = map(int, a.split('.'))
b1, b2, b3 = map(int, b.split('.'))

ans1 = a1 + b1
ans2 = a2 + b2
ans3 = a3 + b3

ans2 += ans3 // 29
ans3 %= 29

ans1 += ans2 // 17
ans2 %= 17

print('.'.join(map(str, [ans1, ans2, ans3])))