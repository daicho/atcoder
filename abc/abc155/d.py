import itertools

n, k = map(int, input().split())
a = list(map(int, input().split()))
b = itertools.combinations(a, 2)
c = []

for t in b:
    c.append(t[0] * t[1])

c.sort()
print(c[k - 1])
