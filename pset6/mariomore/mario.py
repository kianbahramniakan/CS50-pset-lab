while True:
    e = int(input("Height: "))
    if e > 0 and e <= 8:
        break

for i in range(0 , e):
    zz = ' ' * (e - (i + 1))
    q = '#' * (i + 1)
    print(zz + q + "  " + q)
