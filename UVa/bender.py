while True:
    L = int(input())
    if L == 0:
        break
    ops = input().split()
    pointed = '+x'
    for op in ops:
        #print('{}--({})-->'.format(pointed, op), end='')
        if pointed == '+x':
            if op != 'No':
                pointed = op
        elif pointed == '-x':
            if op == '+y':
                pointed = '-y'
            elif op == '-y':
                pointed = '+y'
            elif op == '+z':
                pointed = '-z'
            elif op == '-z':
                pointed = '+z'
        elif pointed == '+y':
            if op == '+y':
                pointed = '-x'
            elif op == '-y':
                pointed = '+x'
        elif pointed == '-y':
            if op == '+y':
                pointed = '+x'
            elif op == '-y':
                pointed = '-x'
        elif pointed == '+z':
            if op == '+z':
                pointed = '-x'
            elif op == '-z':
                pointed = '+x'
        elif pointed == '-z':
            if op == '+z':
                pointed = '+x'
            elif op == '-z':
                pointed = '-x'
        #print('{}'.format(pointed))
    print(pointed)
