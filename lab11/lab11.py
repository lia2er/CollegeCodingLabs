import math

size = 8
vectorX = [0.0] * size
vectorY = [3.4, 3.1, 6.6, 7.2, 2.9, 1.5, 4.2, 5.8]
dobutok = 0.0;
for i in range(size):
    vectorX[i] = 2 * math.sqrt(i+2)
    dobutok += vectorX[i] * vectorY[i]
print(f"Скалярний добуток: {dobutok:.2f}")
