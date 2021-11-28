state = 0
while True:
    try:
        line = list(input().strip("\n"))
        i = 0
        while i < len(line):
            if line[i] == '"':
                if state == 0:
                    line[i:i+1] = ["`", "`"]
                    state = 1
                else:
                    line[i:i+1] = ["'", "'"]
                    state = 0
            i += 1
        print(''.join(line))
    except:
        break

