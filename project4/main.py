# функція для задання масиву
def setArray(M):
    for i in range(5):
        M[i] = int(input("Enter digit: "))

# сортування бульбашкою
def BubbleSort(M, size):
    for i in range(size - 1): # проходи
        for j in range(size - i - 1): # ітерації сортування
            if M[j] > M[j + 1]: 
                M[j], M[j + 1] = M[j + 1], M[j] # перестановка елементів місцями
    print(M)

# ініціалізація масивів нулями, на 5 елементів
M1 = [0] * 5
M2 = [0] * 5

# задання масивів через фунцкції
setArray(M1)
setArray(M2)

# виведення тексту і суми елементів списків
print(f"Sum is: {sum(M1 + M2)}")

print(" dadawj dnadkjawn dankwd nawdnwanjkdajkn\t",)
# Сортування масивів
print("Array M1 now sorted: ")
BubbleSort(M1, 5)
print("Array M2 now sorted: ")
BubbleSort(M2, 5)

# отрумання value
value = int(input("Enter value to insert into array: "))
# Вставка value по індексу 0
M1.insert(0, value)

# виведення масиву
print(f"Inserted element {value} in array M1: ")
print(M1)
