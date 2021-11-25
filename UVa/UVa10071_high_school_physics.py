while True:
    try:
        v, t = (int(i) for i in input().split())
        print(v * t * 2)
    except:
        break