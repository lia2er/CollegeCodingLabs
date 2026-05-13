class Compl:
    def __init__(self, x, y):
        if x == 0 and y == 0:
            raise ValueError("Undefined complex number phase")
        self.x = x
        self.y = y

    def __mul__(self, other):
        return Compl(self.x * other.x - self.y * other.y, self.x * other.y + self.y * other.x)

    def print(self):
        print(f"x: {self.x}, y: {self.y}")

class Fraction:
    def __init__(self, m, n):
        if n == 0:
            raise ValueError("Dividing by zero")
        self.m = m
        self.n = n

    def __mul__(self, other):
        return Fraction(self.m * other.m, self.n * other.n)

    def print(self):
        print(f"m: {self.m}, n: {self.n}")

ac = Compl(3.2, 5.9)
bc = Compl(9.1, 0.2)

af = Fraction(3, 2)
bf = Fraction(9, 7)

try:
    print("Complex number multiplication:")
    cc = ac * bc
    cc.print()
    
    print("Fraction number multiplication(operator):")
    cf = af * bf
    cf.print()
    
    complex_v = [
        Compl(3.2, 4.6),
        Compl(2.3, 1.4),
        Compl(9.4, 3.5),
        Compl(5.4, 4.5),
        Compl(3.3, 2.1)
    ]

    fraction_v = [
        Fraction(3, 3),
        Fraction(2, 1),
        Fraction(9, 3),
        Fraction(5, 2),
        Fraction(3, 2)
    ]

    print("Sorted vector of complex numbers: ")
    complex_v.sort(key=lambda c: c.y, reverse=True)
    
    for c in complex_v:
        c.print()

    print("Sorted vector of fractions: ")
    fraction_v.sort(key=lambda f: f.n)
    
    for f in fraction_v:
        f.print()

except ValueError as e:
    print(e)
