from sys import stdin
while True:
    try:
        count, *nums = [int(i) for i in stdin.readline().split()]
        if count == 1:
            print('Jolly')
            continue
        delta = [] 
        prev = nums[0]
        for i in range(1, len(nums)):
            delta.append(abs(nums[i] - prev))
            prev = nums[i]
        delta.sort()
        jolly = True
        for i in range(len(delta)):
            if delta[i] != (i + 1):
                print('Not jolly')
                jolly = False
                break
        if jolly:
            print('Jolly')
    except:
        break
