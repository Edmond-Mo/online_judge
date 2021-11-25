from sys import stdin, stdout

def main():
    comp = {'<', '>', '<=', '>=', '='}
    p, g = (int(i) for i in stdin.readline().split())
    h = {}
    for i in range(p):
        party, per = stdin.readline().split()
        h[party] = round(float(per), 1)
    for j in range(1, g+1):
        state = 0
        guess = stdin.readline().strip().split()
        w = 0
        total = 0.0
        correct = False 
        while state != 2:
            if state == 0:
                if guess[w] == '+':
                    total += h[guess[w-1]]
                elif guess[w] in comp:
                    total += h[guess[w-1]]
                    state = 1
            elif state == 1:
                total = round(total, 1)
                value = round(float(guess[w]), 1)
                if guess[w-1] == '<' and total < value:
                    correct = True
                elif guess[w-1] == '>' and total > value:
                    correct = True
                elif guess[w-1] == '<=' and total <= value:
                    correct = True
                elif guess[w-1] == '>=' and total >= value:
                    correct = True
                elif guess[w-1] == '=' and total == value:
                    correct = True
                state = 2
            w += 1

        if correct:
            stdout.write('Guess #{} was correct.\n'.format(j))
        else:
            stdout.write('Guess #{} was incorrect.\n'.format(j))

main()