// підключення заголовкового файлу для
#include <iostream> // потоків вводу/виводу

template <class MyType>
MyType min(MyType a, MyType b){ // створення функції з двома параметрами
  return a < b ? a : b; // повернення результату умовного тернарного оператора
}

template <class MyType>
MyType min(MyType a, MyType b, MyType c){ // перевантаження функції min з трьома параметрами
  return min(a,b) < c ? min(a,b) : c;  // повернення результату умовного тернарного оператора
}

template <class MyType>
MyType min(MyType a, MyType b, MyType c, MyType d){ // перевантаження функції min з чотирма параметрами
  return min(a,b,c) < d ? min(a,b,c) : d; // повернення результату умовного тернарного оператора
}

int main(){
  int a = 5, b = 9, c = 4, d = 1; // ініціалізація змінних з цілими числами
  float af = 3.5, bf = 9.9, cf = 11.3, df = 6.0; // ініціалізація змінних з дійсними числами
  
  std::cout << "Min of " << a << " and " // виведення тексту, змінних і повернене значення функції min
    << b << " is " << min(a,b) << std::endl;
  std::cout << "Min of " << a << ", " << b  // виведення тексту, змінних і повернене значення функції min
    << " and " << c << " is " << min(a,b,c) << std::endl;
  std::cout << "Min of " << a << ", " << b  // виведення тексту, змінних і повернене значення функції min
    << ", " << c << " and " << d << " is " << min(a,b,c) << std::endl;

  std::cout << "Min of " << af << " and "  // виведення тексту, змінних і повернене значення функції min
    << bf << " is " << min(af,bf) << std::endl;
  std::cout << "Min of " << af << ", " << bf  // виведення тексту, змінних і повернене значення функції min
    << " and " << cf << " is " << min(af,bf,cf) << std::endl;
  std::cout << "Min of " << af << ", " << bf  // виведення тексту, змінних і повернене значення функції min
    << ", " << cf << " and " << df << " is " << min(af,bf,cf) << std::endl;
}
