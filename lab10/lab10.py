a = int(input("Enter some number: "))

# Переведення числа в текст і отримання довжини 
length = len(str(a))

# Створення нульового масиву
array = [0] * length

for i in range(length - 1, -1, -1):
    array[i] = a % 10   # Запис останньої цифри
    a //= 10            # Перехід до наступної цифри

# Робота з масивом
summ = 0
for i in range(length):
    if array[i] % 2 == 1:   # Зменшення непарних чисел на 1
        array[i] -= 1
    summ += array[i]        # Сумування елементів масиву
    print(array[i], ", ", end="")

print("\nSum is", summ)

