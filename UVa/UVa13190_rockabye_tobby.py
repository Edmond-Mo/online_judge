from sys import stdin, stdout
import heapq

def bsta(arr, k, L, H):
    tries = 0
    while tries < 30:
        mid = (L + H) // 2
        totake = 0
        for f, a, b in arr:
            totake += mid // f
        #print('{} {} {} totake {}'.format(L, H, mid, totake))
        if totake == k:
            return mid
        if totake > k:
            H = mid - 1
        else:
            L = mid + 1
        tries += 1
    return mid + 1

def main():
    tc = int(stdin.readline())
    for _ in range(tc):
        n, k = (int(i) for i in stdin.readline().split())
        p = 0       # priority
        meds = []
        minFreq = float('inf')
        for i in range(n):
            name, freq = stdin.readline().split()
            freq = int(freq)
            minFreq = min(freq, minFreq)
            meds.append((freq, p, name))
            p += 1
        t_max = bsta(meds, k, 1, minFreq * k)

        for i in range(n):
            f = meds[i][0]
            for m in range(2, t_max // f + 1):
                meds.append((m * f, meds[i][1], meds[i][2]))
        heapq.heapify(meds)
        for i in range(k):
            m = heapq.heappop(meds)
            stdout.write('{} {}\n'.format(m[0], m[2]))

main()