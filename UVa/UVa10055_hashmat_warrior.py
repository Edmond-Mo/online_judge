from sys import stdin, stdout

while True:
    try:
        a, b = (int(i) for i in stdin.readline().split())
        stdout.write("{}\n".format(abs(a-b)))
    except:
        break


