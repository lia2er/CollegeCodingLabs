size = 2 # ініціалізація змінної size
sentence = [""] * size # ініціалізація масиву на size елементів типу string
for i in range(size): # цикл for (для і в діапазоні size)
    sentence[i] = input("Enter a sentence: ") # запис в елемент масиву
                                              # символьного рядка

for i in range(size): # цикл for
    words = sentence[i].split() # ініціалізація змінної word, split() - розбиває 
                                # рядок sentence[i] на список

    # tuple unpacking, перехресне присвоєння значень елементів списку words
    # word[0] - перше слово, word[-1] - останнє слово
    # lower() - переведення в нижній регістр
    # capitalize() - переведення в верхній регістр
    words[0], words[-1] = words[-1].capitalize(), words[0].lower()
    sentence[i] = " ".join(words) # join() - з`єднує елементи списку words в 
                                  # рядок sentence[i], з роздільником - пробілом
    print("New sentence is: ", sentence[i]) # виведення нового рядка
