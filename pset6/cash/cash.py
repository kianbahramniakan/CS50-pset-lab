# get input from user
e = float(input("Change owed: "))
while e < 0:
    e = float(input())
# round the input
cents = round(e * 100)
i = 0
z = cents
# do some math:)
while z >= 25:
    i = i + 1
    z = z - 25
while z >= 10:
    i = i + 1
    z = z - 10
while z >= 5:
    i = i + 1
    z = z - 5
while z >= 1:
    i = i + 1
    z = z - 1
# print the answear
print(i)