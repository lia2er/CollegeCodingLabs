#include <iostream>

int main(){
  int a;
  std::cout << "Enter some number: "; 
  std::cin >> a;

  int temp = a;
  int len = 0;
  
  // Отримання довжини числа
  while (temp){
    temp /= 10;
    len++;
  }

  int array[len];
  
  // Створення масиву з чисел
  for(int i = len-1; i >= 0; i--){
    array[i] = a % 10;  // Запис останньої цифри
    a /= 10;            // Перехід до наступної цифри
  }

  // Робота з масивом
  int sum = 0;
  for(int i = 0; i < len; i++) {
    if(array[i]%2==1)  // Зменшення непарних чисел на 1
      array[i]-=1;
    sum+=array[i];     // Сумування елементів масиву
    std::cout << array[i] << ", ";
    }
  std::cout << "\nSum is " << sum;
  return 0;
}
