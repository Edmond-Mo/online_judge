M = [[1,2,3,4],
     [5,6,7,8],
     [9,10,11,12],
     [13,14,15,16]]

transposed = list(zip(*M))
rotatedCw = []
for row in transposed:
    rotatedCw.append(row[::-1])

# one liner to rotate matrix clockwise
insane = [row[::-1] for row in zip(*M)]

for i in rotatedCw:
    print(i)
print()

for i in insane:
    print(i)
print()

anti = [row[::-1] for row in M]
anti = list(zip(*anti))
for i in anti:
    print(i)
print()

# one liners to rotate matrix anti-clockwise
# both works
crazy = list(zip(*(row[::-1] for row in M)))
crazy2 = [*zip(*(row[::-1] for row in M))]
for i in crazy2:
    print(i)
print()

