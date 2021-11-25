from sys import stdin, stdout

stack = []
q = int(stdin.readline())
for _ in range(q):
    query = stdin.readline()
    if query.startswith('Sleep'):
        name = query.split()[1]
        stack.append(name)
    elif query.startswith('Test'):
        if not stack:
            stdout.write('Not in a dream\n')
        else:
            stdout.write('{}\n'.format(stack[-1]))
    else:
        if stack:
            stack.pop()