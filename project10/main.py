# реалізація класу Compl
class Compl:
    def __init__(self, x, y): # ініціалізація конструктора
        if x == 0 and y == 0: # перевірка значень
            # кидаємо виняток ValueError
            raise ValueError("Undefined complex number phase")
            
        self.x = x
        self.y = y

    def __mul__(self, other): # перевантаження оператора множення
        return Compl(self.x * other.x - self.y * other.y, 
                     self.x * other.y + self.y * other.x)

    def print(self): # метод для друку даних
        print(f"x: {self.x}, y: {self.y}")

# реалізація класу Fraction
class Fraction:
    def __init__(self, m, n): # ініціалізація конструктора
        if n == 0: # перевірка значення
            raise ValueError("Dividing by zero")
            
        self.m = m
        self.n = n

    def __mul__(self, other): # перевантаження оператора множення
        return Fraction(self.m * other.m, self.n * other.n)

    def print(self): # метод для друку даних
        print(f"m: {self.m}, n: {self.n}")

# ініціалізація об`єктів
ac = Compl(3.2, 5.9)
bc = Compl(9.1, 0.2)

af = Fraction(3, 2)
bf = Fraction(9, 7)

try:  # `спроба` виконати код в блоці
    print("Complex number multiplication:")
    cc = ac * bc # ініціалізація об`єкта cc з добутком (через перевантажений оператор)
    cc.print() # друк цього об`єктa
    
    print("Fraction number multiplication(operator):")
    cf = af * bf # ініціалізація об`єкта cf з добутком (через перевантажений оператор)
    cf.print() # друк цього об`єктa
    
    # ініціалізація списків
    complex_v = [
        Compl(3.2, 4.6),
        Compl(2.3, 1.4),
        Compl(9.4, 3.5),
        Compl(5.4, 4.5),
        Compl(3.3, 2.1)
    ]

    fraction_v = [
        Fraction(3, 4),
        Fraction(2, 1),
        Fraction(9, 3),
        Fraction(5, 4),
        Fraction(3, 2)
    ]

    print("Sorted vector of complex numbers: ")
    # Сортування через lambda-функцію, сортування за спаданням 
    complex_v.sort(key=lambda c: c.y, reverse=True)
    
    for c in complex_v: # цикл з ітерацією через весь список
        c.print() # звернення до методу print()

    print("Sorted vector of fractions: ")
    # Сортування за зростанням (аналог a.getN() < b.getN())
    fraction_v.sort(key=lambda f: f.n)
    
    for f in fraction_v: # цикл з ітерацією через весь список
        f.print() # звернення до методу print()

except ValueError as e: # блок для обробки помилок
    print(e) # виведення рядка помилки

