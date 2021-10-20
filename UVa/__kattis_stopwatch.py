from sys import stdin
getc = stdin.readline
pressed = int(getc())
total = 0
prev = 0
state = 0    # stopped
for _ in range(pressed):
    timestamp = int(getc())
    if state == 0:  # @ stopped state
        prev = timestamp
        state = 1   # go to running state   
    else:
        total += (timestamp - prev)
        state = 0
if state == 1:
    print('still running')
else:
    print(total)
