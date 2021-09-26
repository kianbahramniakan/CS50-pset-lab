from csv import reader, DictReader
from sys import argv
# print the error
if len(argv) < 3:
    print("usage error, dna.py sequence.txt database.csv")
    exit()
with open(argv[2]) as qqq:
    z = reader(qqq)
    for row in z:
        zz = row
dna = zz[0]
zq = {}
# make a code to find (I'm iranian and i cant write too much english well)
with open(argv[1]) as peoplefile:
    qq = reader(peoplefile)
    for row in qq:
        po = row
        po.pop(0)
        break
for item in po:
    zq[item] = 1
for key in zq:
    l = len(key)
    tm = 0
    tp = 0
    for i in range(len(dna)):
        while tp > 0:
            tp -= 1
            continue
        if dna[i: i + l] == key:
            while dna[i - l: i] == dna[i: i + l]:
                tp += 1
                i += l
            if tp > tm:
                tm = tp
    zq[key] += tm

with open(argv[1], newline='') as peoplefile:
    qq = DictReader(peoplefile)
    for person in qq:
        mc = 0
        for dna in zq:
            if zq[dna] == int(person[dna]):
                mc += 1
        if mc == len(zq):
            print(person['name'])
            exit()
    print("No match")