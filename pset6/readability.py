# getting the input
e = input("Text: ")
# find how many letters we have in the sentence
harf = len(e)-(e.count(" ")+e.count(".")+e.count("!")+e.count("?"))
# finding the sentences
gomle = e.count(". ") + e.count("!") + e.count("?") + 1
# finding the words
kalame = len(e.split())
# do the maths :)
L = (harf * 100) / (kalame)
S = (gomle * 100) / (kalame)
AV = 0.0588 * L - 0.296 * S - 15.8
# round the answear
q = round(AV)
# find the grades:)
if (q >= 16):
    print("Grade 16+")

elif (q < 1):
    print("Before Grade 1")

else:
    print("Grade", q)
