sentence1 = input("Enter A sentence: ")
sentence2 = input("Let`s get another one: ")
lastWord = sentence1.split()[-1]
if lastWord in sentence2:
    sentence2 = sentence2.replace(lastWord, "").strip()
    print(sentence2)
else:
    print("There`s no such word")
    
