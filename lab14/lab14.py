from math import pi, atan2

# print(f"") - виведення форматованого рядка
# {x:.2f} - виведення х з 2 знаками після коми

def angle(x, y): # функція angle з параментрами x,y
  return atan2(y,x) * 180.0 / pi # повернення значень обчислення

x = [4.6, 9.3, 12.3, 6.3] # ініціалізація списків x,y
y = [9.4, 9.5, 7.1, 8.3]
maxAngle = 0 # ініціалізація змінної maxAngle
angles = [0.0] * 4 # ініціалізація списку на 4 елементи
for i in range(4):  # цикл з лічильником
    angles[i] = angle(x[i], y[i]); # виклик функції angle і запис результату
                                   # повернення даних в список angles з індексом i
    if (angles[i] > maxAngle): # знаходження марсимального кута
        maxAngle = angles[i]; # запис максимального кута в змінну maxAngle

for i in range(4):  # цикл з лічильником
    print(f"| x: {x[i]:.2f}\ty: {y[i]:.2f}\tкут: {angles[i]:.2f}")

print(f"Максимальний кут: {maxAngle:.2f}") # виведення значення maxAngle
for i in range(4): # цикл з лічильником
    if angles[i] == maxAngle: # пошук maxAngle в спискові
        print("Координати точки з цим кутом: ") # виведення текстy
        print(f"| x: {x[i]:.2f}\ty: {y[i]:.2f}") # виведення елементів списку

