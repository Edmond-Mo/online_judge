len_db = dict()
len_db[0] = 0
len_db[1] = 1

def get_cycle_length(n):
    global len_db
    if n in len_db:
        return len_db[n]

    count = 1
    backup = n
    while n != 1:
        if n % 2 == 0:
            n >>= 1
        else:
            n = 3 * n + 1

        if n in len_db:
            len_db[backup] = len_db[n] + count
            return len_db[backup]

        count += 1

    return count

while True:
    try:
        txt = input()
        if not txt: break
        start, stop = [int(i) for i in txt.split()]
        best = 0
        for num in range(min(start, stop), max(start, stop)+1):
            curr = get_cycle_length(num)
            if curr > best: best = curr
        print('{} {} {}'.format(start, stop, best))
    except EOFError:
        break

