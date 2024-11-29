def powrange(start, end, step):
    res = []
    while start != end:
        res.append(start)
        start *= step
    return res

def fun(n, s):
    mat = [[], []]
    if s[0] == 'x':
        mat[0].append(1)
    else:
        mat[0].append(0)
    if s[1] == 'x':
        mat[0].append(1)
    else:
        mat[0].append(0)
    if s[2] == 'x':
        mat[1].append(1)
    else:
        mat[1].append(0)
    if s[3] == 'x':
        mat[1].append(1)
    else:
        mat[1].append(0)
    length = 2 ** (n + 1)
    res = [['x' for _ in range(length)] for _ in range(length)]
    for k in powrange(2, 2 ** (n + 2), 2):
        for y in range(k):
            for x in range(k):
                if mat[y % 2][x % 2] == 0:
                    for i in range(y * (length // k), (y + 1) * (length // k)):
                        for j in range(x * (length // k), (x + 1) * (length // k)):
                            res[i][j] = ' '
    for i in res:
        print(*i)



fun(int(input()), input() + input())
