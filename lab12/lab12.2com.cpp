				            // Підключення заголовкових файлів для:
#include <iostream> // - функцій потоків вводу/виводу
#include <math.h>   // - математичних функцій
#include <iomanip>  // - керування потоками введення/виведення

int main(){ // початок головної функції
  float m[3] = {-1.85, 2.39, 3.65}; // ініціалізація масиву m з 3 елементів
   float z, // оголошення змінної z
        q = 2.8; // ініціалізація змінної q

  start_compute: // створення label start_compute для оператора goto
  if (q <= 5.4){ // умовний оператор
    std::cout << std::fixed << std::setprecision(2) // виведення даних
      << "q = " << q << std::endl;                  // в консоль
    for(int i = 0; i < 3; i++){
      z = m[i] + (exp(m[i]/m[i])-q)/(1-m[i]); // обчислення за формулою
      std::cout << std::fixed << std::setprecision(2) // виведення даних 
        << "z = "                                     // в консоль
        << z << "\tm[" << i << "] = "
        << m[i]
        << std::endl;
    }
    q += 1.3; // додавання до змінної q 1.3
  goto start_compute; // використання goto для переходу на label start_compute
  } else goto end; // інакше перехід на label end
  end: // створення label  end для оператора goto
  return 0; // повернення виконання функції
} // кінець головної функції

