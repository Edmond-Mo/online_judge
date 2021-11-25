from sys import stdin, stdout

def main():
    tc = int(stdin.readline())
    for t in range(tc):
        old = {}
        new = {}
        line = stdin.readline().strip('\n')
        if len(line) > 2:
            line = line[1:-1].split(',')
            for entry in line:
                k, v = entry.split(':')
                old[k] = v
        line = stdin.readline().strip('\n')
        if len(line) > 2:
            line = line[1:-1].split(',')
            for entry in line:
                k, v = entry.split(':')
                new[k] = v
        old_keys = old.keys()
        new_keys = new.keys()
        added_keys = []
        removed_keys = []
        for k in new_keys:
            if k not in old_keys:
                added_keys.append(k)
        for k in old_keys:
            if k not in new_keys:
                removed_keys.append(k)
        changed_keys = []
        for k, v in old.items():
            if k in new_keys and new[k] != v:
                changed_keys.append(k)
        someChange = False
        if added_keys:
            someChange = True
            stdout.write('+' + ','.join(sorted(added_keys)) + '\n')
        if removed_keys:
            someChange = True
            stdout.write('-' + ','.join(sorted(removed_keys)) + '\n')
        if changed_keys:
            someChange = True
            stdout.write('*' + ','.join(sorted(changed_keys)) + '\n')
        if someChange is False:
            stdout.write('No changes\n')
        #if t < tc - 1:
        stdout.write('\n')

main()