while True:
    queries = int(input())
    if queries == 0: break
    dx, dy = [int(i) for i in input().split()]
    for _ in range(queries):
        rx, ry = [int(i) for i in input().split()]
        if rx == dx or ry == dy:
            print('divisa')
        elif rx > dx and ry > dy:
            print('NE')
        elif rx > dx and ry < dy:
            print('SE')
        elif rx < dx and ry > dy:
            print('NO')
        elif rx < dx and ry < dy:
            print('SO')



