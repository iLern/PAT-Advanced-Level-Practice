from datetime import datetime

formatStr = "%H:%M:%S"

class People:
    def __init__(self, info: str):
        attr = info.split(' ')

        self.id = attr[0]
        self.begin = datetime.strptime(attr[1], formatStr)
        self.end = datetime.strptime(attr[2], formatStr) 

    def __lt__(self, other)->bool:
        return self.begin < other.begin


if __name__ == '__main__':
    n = int(input())

    l = []
    for i in range(n):
        s = input()
        l.append(People(s))


    sortedL = sorted(l)
    last = sortedL[0].end
    ans = sortedL[0].id

    for i in sortedL:
        if i.end > last:
            last = i.end
            ans = i.id

    print(sortedL[0].id, ans)

    