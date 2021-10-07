# AC 0.6s
from sys import stdin, stdout

import re

def main():
    T = int(stdin.readline())
    pat = re.compile(r'[a-z]+')
    for t in range(1, T+1):
        lw = list()
        wordCount = dict()
        firstWordMaxIndex = 0
        order = 0
        while True:
            line = stdin.readline().strip()
            if line == 'END':
                break
            words = re.findall(pat, line)
            for w in words:
                if w not in wordCount:
                    wordCount[w] = 0
                    # first time this word is seen
                    if order > firstWordMaxIndex:
                        firstWordMaxIndex = order
                lw.append(w)
                order += 1

        numWords = len(wordCount.keys())
        # create a sliding window
        end = firstWordMaxIndex
        start = 0
        uniqueCount = 0
        bestLen = 1e9
        bestStart = 1e9
        for i in range(start, end+1):
            wordCount[lw[i]] += 1
            if wordCount[lw[i]] == 1:
                uniqueCount += 1
        while start < len(lw) or end < len(lw):
            if uniqueCount == numWords:
                l = end - start + 1
                if l < bestLen:
                    bestLen = l
                    bestStart = start
                if start < len(lw):
                    wordCount[lw[start]] -= 1
                    if wordCount[lw[start]] == 0:
                        uniqueCount -= 1
                start += 1
            else:
                if end + 1 < len(lw):
                    wordCount[lw[end + 1]] += 1
                    if wordCount[lw[end + 1]] == 1:
                        uniqueCount += 1
                end += 1
                # need to move end to the right to increase unique count
                # so when end is already at the boundary and unique count
                # is below, give up.
                if uniqueCount < numWords and end >= len(lw):
                    break

        stdout.write('Document {}: {} {}\n'.format(t, bestStart + 1, bestStart + bestLen))

main()