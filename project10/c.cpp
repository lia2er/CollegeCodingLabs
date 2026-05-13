// підключення заголовкових файлів для:
#include <iostream> // потоків вводу/виводу
#include <vector> // динамічних масивів/векторів

using namespace std; // використання простору імен std

// реалізація класу Compl
class Compl {
  private: // вміст private доступний тільки всередині цього класу
    float x,y; // оголошення змінних
  public: // до вмісту public можна звернутись через об`єкт
    Compl(float X, float Y) : x(X), y(Y) { // ініціалізація конструктора через список ініціалізації
      if ( x == 0 and y == 0) // перевірка значеннь
        throw "Undefined complex number phase"; // кидає виняток в вигляді рядка
    }

    Compl operator*(Compl const &c) { // перевантаження оператора множення
      return Compl(x * c.x - y * c.y, x * c.y + y * c.x); // повернення значення
    }

    void print() {cout << "x: " << x << ", y: " << y << endl;} // метод для друку даних
    float getX() {return x;} // метод для отримання x
    float getY() {return y;} // метод для отримання y

    ~Compl() {} // деструктор
};

// реалізація класу Fraction
class Fraction {
  private: // вміст private доступний тільки всередині цього класу
    int m,n; // оголошення змінних
  public: // до вмісту public можна звернутись через об`єкт
    Fraction(int M, int N) : m(M), n(N) { // ініціалізація конструктора через список ініціалізації
      if (n == 0) // перевірка значення
        throw "Dividing by zero"; // кидає виняток в вигляді рядка
    }

    Fraction operator*(Fraction const &c) { // перевантаження оператора множення
      return Fraction(m * c.m, n * c.n); // повернення значення
    }

    void print() {cout << "m: " << m << ", n: " << n << endl;} // метод для друку даних

    float getM() {return m;} // метод для отримання m
    float getN() {return n;} // метод для отримання n

    ~Fraction() {} // деструктор
};

template<class Something> // шаблонна функція з типом Something
Something Mult(Something &a, Something &b) { // 2 параметри заголовкового типу
  return a * b; // повернення добутку
}

int main() {
  Compl ac(3.2, 5.9), bc(9.1, 0.2); // ініціалізація об`єктів класу Comp
  Fraction af(3,2), bf(9,7); // ініціалізація об`єктів класу Fraction

  try { // `спроба` виконати код в блоці

    cout << "Complex number multiplication(operator):\n"; // друк тексту
    Compl cc = ac * bc; // ініціалізація об`єкта cc з добутком інших об`єктів
    cc.print(); // друк цього об`єктa
    cout << "Complex number multiplication(function):\n";
    cc = Mult(ac, bc); // виклик функції для добутку і присвоєння її результату сс
    cc.print(); // друк об`єктa сс

    cout << "Fraction number multiplication(operator):\n"; // друк тексту
    Fraction cf = af * bf; // ініціалізація об`єкта cf з добутком інших об`єктів
    cf.print(); // друк цього об`єктa
    cout << "Fraction number multiplication(function):\n";
    cf = Mult(af, bf); // виклик функції для добутку і присвоєння її результату сf
    cf.print(); // друк об`єктa сf
    
    // ініціалізація векторів відповідних типів
    vector<Compl> ComplexV = {
      Compl(3.2, 4.6),
      Compl(2.3, 1.4),
      Compl(9.4, 3.5),
      Compl(5.4, 4.5),
      Compl(3.3, 2.1)};

    vector<Fraction> FractionV = {
      Fraction(3, 4),
      Fraction(2, 1),
      Fraction(9, 3),
      Fraction(5, 4),
      Fraction(3, 2)};

    cout << "Sorted vector of complex numbers: \n";
    sort(ComplexV.begin(), ComplexV.end(), // сортування від початку вектора до кінця
        [](Compl &a, Compl &b) // предикант з lambda-функцією 
        {return a.getY() > b.getY();}); // порівнює отримані значення і повертає bool
                                        
    for(Compl &a : ComplexV) // цикл з ітерацією через весь вектор
      a.print(); // звернення до методу print(), об`єкта `а`
    cout << endl; // перехід на новий рядок

    cout << "Sorted vector of fractions: \n";
    sort(FractionV.begin(), FractionV.end(), // сортування від початку вектора до кінця 
        [](Fraction &a, Fraction &b) // предикант з lambda-функцією 
        {return a.getN() < b.getN();}); // порівнює отримані значення і повертає bool

    for(Fraction &a : FractionV) // цикл з ітерацією через весь вектор
      a.print(); // звернення до методу print(), об`єкта `а`
    cout << endl; // перехід на новий рядок
  }
  catch (const char *s) { // блок для обробки помилок
    cout << s << endl; // виведення рядка помилки
  }
}
