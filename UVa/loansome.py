def BuildRate(dura, n):
    drate = [0.0] * (dura + 1)
    for _ in range(n):
        month, rate = input().split()
        month = int(month)
        rate = float(rate)
        drate[month] = rate

    curr_rate = drate[0]
    for i, v in enumerate(drate):
        if v == 0.0:
            drate[i] = curr_rate
        else:
            curr_rate = v

    return drate

while True:
    dura, downpay, loan, rates = input().split()
    dura = int(dura)
    if dura < 0: break

    downpay = float(downpay)
    loan = float(loan)
    rates = int(rates)
    rate_table = BuildRate(dura, rates)
    base_value = (downpay + loan) * (1.0 - rate_table[0])
    month = 0
    owe = loan
    payment = loan / dura

    if owe < base_value:
        print('0 months')
        continue

    while owe > base_value:
        #print('month:{} owe:{} value:{}'.format(month,owe,base_value))
        owe -= payment
        month += 1
        base_value *= (1 - rate_table[month])
    fmt = '{} month' + ('s' if month > 1 else '')
    print(fmt.format(month))



