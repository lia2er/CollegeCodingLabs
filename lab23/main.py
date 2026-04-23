# створення функції
def Min(a, b, c=None, d=None):
    # в змінну запишеться результат умовного оператора
    result = a if a < b else b
    
    # перевірка чи змінна має зміст
    if c is not None:
        # в змінну запишеться результат умовного оператора
        result = result if result < c else c
        
    # перевірка чи змінна має зміст
    if d is not None:
        # в змінну запишеться результат умовного оператора
        result = result if result < d else d
        
    # поверняння значення результату
    return result

# виведення різних випадків цієї функції
print(Min(10, 20))          
print(Min(1, -6, -5))      
print(Min(-53, 35, 23, 4))  

print(Min(9.4, 3.6))          
print(Min(1.2, -6.2, -5.5))      
print(Min(-53.5, 35.2, 23.9, 4.3))
