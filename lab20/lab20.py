from dataclasses import dataclass # підключення dataclass з бібліотеки dataclasses
from math import sqrt # підключення sqrt з бібліотеки math

@dataclass # декоратор який генерує необхідний для класу код
class Coords: # створення класу Coords зі зміннини x,y,z типу int
    x: int
    y: int
    z: int

def coordLength(p: Coords): # визначення функції coordLength з параметром Coords
    return int(sqrt(p.x * p.x + p.y * p.y + p.z * p.z)) # повернення значення типу int

def bubble_sort(points): #  визначення функції для сортування бульбашкою
    n = len(points) # отримання довжини points і запис в змінну n
    for i in range(n - 1): # цикл в діапазоні від 0 до n-1
        for j in range(n - i - 1): # цикл в діапазоні від 0 до n-i-1
            if coordLength(points[j]) > coordLength(points[j + 1]): # порівняння значень
                points[j], points[j + 1] = points[j + 1], points[j] # навхресне присвоєння

N = 5 # ініціалізація змінної зі значенням 5
points = []  # ініціалізація списку

for i in range(N): # цикл від і до N
    # отримання вводу, розбивка його на список і присвоєння його змінним x,y,z
    x, y, z = input("Enter some coordinates (x y z): ").split()
    x, y, z = int(x), int(y), int(z) # переведення змінних в тип int
    points.append(Coords(x, y, z)) # додати до списку points об`єкту Coords з значеннями x,y,z

bubble_sort(points) # виклик функції сортування з аргументом points

print("Our coordinates:") # виведення тексту
print(f"{'X':>5}|{'Y':>5}|{'Z':>5}|") # виведення форматованого рядка з 5 відступами зліва
print(f"{'-'*5}|{'-'*5}|{'-'*5}|") # множення символу друкує символ стільки раз
for p in points: # перебір списку
    print(f"{p.x:>5}|{p.y:>5}|{p.z:>5}|") # виведення змінних об`єкту p класу Coords і 5 відступів

pairs = [] # ініціалізація списку
for i in range(N): # цикл від і до N
    for j in range(i + 1, N): # цикл від і+1 до N
        if points[i].x == points[j].x: # перевірка на рівність
            pairs.append((points[i], points[j])) # доповнення списку pairs цими об`єктами

if pairs: # якщо pairs щось містить
    print("Points that have the same X coordinate:") # виведення тексту
    for a, b in pairs: # ітерації змінних a,b через список pairs
        print(f"{a.x} {a.y} {a.z}") # виведення цих змінних через форматований рядок
        print(f"{b.x} {b.y} {b.z}") # виведення цих змінних через форматований рядок
        print() # виведення нового рядка

