from sys import stdin, stdout
import sys
sys.setrecursionlimit(10000)
memo = [0] * 5010

def fib(n):
    if n == 0: return 0
    if n == 1: return 1
    if memo[n]: return memo[n]
    memo[n] = fib(n-1) + fib(n-2)
    return memo[n]

for line in stdin:
    n = int(line)
    stdout.write("The Fibonacci number for {} is {}\n".format(n, fib(n)))
