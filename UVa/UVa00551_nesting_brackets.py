# (* and *) counts as ONE character
# Yes, even for counting toward the
# position of the wrong bracket!

from sys import stdin, stdout


b = ')]}>#'
h = {'(':')', '[':']', '{':'}', '<':'>', '@':'#'}

for s in stdin:
    s = s.strip('\n')
    s = s.replace('(*', '@')
    s = s.replace('*)', '#')
    stack = []
    i = 0
    problem = -1
    while i < len(s):
        if s[i] in h:
            stack.append(s[i])
        elif s[i] in b:
            if not stack:
                problem = i + 1
                break
            top = stack.pop()
            if h[top] != s[i]:
                problem = i + 1
                break
        i += 1

    if problem >= 0:
        stdout.write('NO {}\n'.format(problem))
    else:
        if stack:
            stdout.write('NO {}\n'.format(i+1))
        else:
            stdout.write('YES\n')
