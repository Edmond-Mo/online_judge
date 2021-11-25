def gen(p):
    if not p:
        return 'A'
    if p[-1] < 'Z':
        return p[:-1] + chr(ord(p[-1])+1)
    s = list(p)
    s[-1] = 'A'
    carry = True
    for i in range(len(s) - 2, -1, -1):
        if carry:
            if s[i] < 'Z':
                s[i] = chr(ord(s[i]) + 1)
                carry = False
            else:
                s[i] = 'A'
                carry = True
    if carry:
        s.append('A')
    return ''.join(s)

while True:
    lines = int(input())
    if lines == 0: break

    names = [input() for _ in range(lines)]
    names.sort()
    left = names[lines // 2 - 1]
    right = names[lines // 2]
    # look for the first diff char
    ll = len(left)
    rl = len(right)
    i = 0
    while i < ll and i < rl and left[i] == right[i]:
        i += 1
    if i == ll:
        print(left)
    else:
        prefix = left[:i]
        pat = ''
        while prefix + pat < left or prefix + pat >= right:
            pat = gen(pat)
        print(prefix + pat)
