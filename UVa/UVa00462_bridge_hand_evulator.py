S, H, D, C = 0, 1, 2, 3
tbl = {'S':S, 'H':H, 'D':D, 'C':C}
suit_names = ['S', 'H', 'D', 'C']

while True:
    try:
        cards = input().split()
        if not cards: continue
        aces = [0] * 4
        kings = [0] * 4
        queens = [0] * 4
        jacks = [0] * 4
        suit_count = [0] * 4
        suit_stopped = [0] * 4
        regular_point = 0
        trump_point = 0
        # rule 1
        for rank, suit in cards:
            suit_count[tbl[suit]] += 1
            if rank == 'A':
                suit_stopped[tbl[suit]] = 1
                aces[tbl[suit]] = 1
                regular_point += 4
            elif rank == 'K':
                kings[tbl[suit]] = 1
                regular_point += 3
            elif rank == 'Q':
                queens[tbl[suit]] = 1
                regular_point += 2
            elif rank == 'J':
                jacks[tbl[suit]] = 1
                regular_point += 1
        # rule 2
        anyKing = False
        for suit, hasKing in enumerate(kings):
            if hasKing:
                if suit_count[suit] <= 1:
                    anyKing = True
                else:
                    suit_stopped[suit] = 1
        if anyKing:
            regular_point -= 1
        
        # rule 3
        anyQueen = False
        for suit, hasQueen in enumerate(queens):
            if hasQueen:
                if suit_count[suit] <= 2:
                    anyQueen = True
                else:
                    suit_stopped[suit] = 1
        if anyQueen:
            regular_point -= 1
        
        # rule 4
        anyJack = False
        for suit, hasJack in enumerate(jacks):
            if hasJack:
                if suit_count[suit] <= 3:
                    anyJack = True
        if anyJack:
            regular_point -= 1
        
        trump_point = regular_point

        for c in suit_count:
            if c == 1:              # rule 6
                regular_point += 2
            elif c == 2:            # rule 5
                regular_point += 1
            elif c == 0:            # rule 7
                regular_point += 2

        if trump_point >= 16 and sum(suit_stopped) == 4:
            print('BID NO-TRUMP')
            continue

        if regular_point < 14:
            print('PASS')
        else:
            most_cards = max(suit_count)
            for suit, count in enumerate(suit_count):
                if count == most_cards:
                    print('BID {}'.format(suit_names[suit]))
                    break

    except EOFError:
        break
