#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Compl {
  private:
    float x,y;
  public:
    Compl(float X, float Y) : x(X), y(Y) { 
      if ( x == 0 and y == 0) 
        throw "Undefined complex number phase"; 
    }
    // в аргумент подається правий операнд
    Compl operator*(Compl const &c) { 
      return Compl(x * c.x - y * c.y, x * c.y + y * c.x); 
    }

    void print() {cout << "x: " << x << ", y: " << y << endl;} 
    float getX() {return x;} 
    float getY() {return y;} 

    ~Compl() {} 
};

class Fraction {
  private: 
    int m,n; 
  public: 
    Fraction(int M, int N) : m(M), n(N) { 
      if (n == 0) 
        throw "Dividing by zero"; 
    }

    Fraction operator*(Fraction const &c) { 
      return Fraction(m * c.m, n * c.n); 
    }

    void print() {cout << "m: " << m << ", n: " << n << endl;} 
    float getM() {return m;} 
    float getN() {return n;} 

    ~Fraction() {} 
};

template<typename Something> 
Something Mult(Something &a, Something &b) { 
  return a * b; 
}

int main() {
  Compl ac(3.2, 5.9), bc(9.1, 0.2); 
  Fraction af(3,2), bf(9,7); 

  try { 
    cout << "Complex number multiplication(operator):\n"; 
    Compl cc = ac * bc; 
    cc.print(); 
    cout << "Complex number multiplication(function):\n";
    cc = Mult(ac, bc); 
    cc.print(); 

    cout << "Fraction number multiplication(operator):\n"; 
    Fraction cf = af * bf; 
    cf.print(); 
    cout << "Fraction number multiplication(function):\n";
    cf = Mult(af, bf); 
    cf.print(); 
    
    vector<Compl> ComplexV = {
      Compl(3.2, 4.6),
      Compl(2.3, 1.4),
      Compl(9.4, 3.5),
      Compl(5.4, 4.5),
      Compl(3.3, 2.1)};

    vector<Fraction> FractionV = {
      Fraction(3, 4),
      Fraction(2, 1),
      Fraction(9, 5),
      Fraction(5, 4),
      Fraction(3, 2)};

    cout << "Sorted vector of complex numbers: \n";
    sort(ComplexV.begin(), ComplexV.end(), 
        [](Compl &a, Compl &b) {return a.getY() > b.getY();}); 
    
    for(Compl &a : ComplexV) a.print(); 
    cout << endl; 

    cout << "Sorted vector of fractions: \n";
    sort(FractionV.begin(), FractionV.end(), 
        [](Fraction &a, Fraction &b) {return a.getN() < b.getN();}); 

    for(Fraction &a : FractionV) a.print(); 
    cout << endl; 
  }
  catch (const char *s) { 
    cout << s << endl;
  }
}
