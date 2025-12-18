#include <iostream>
using namespace std;

int main(){
  const int size = 12; // Розмір масиву
  int x[size] = {5,-3,4,2,7,-9,1,4,6,7,3,2};
  int min = 0; // Змінна для збереження мін. числа
  
  // Виведення масиву до зміни
  cout << "\nМасив до заміни:\n";
  for (int i = 0; i < size; i++) cout << x[i] << ", ";
  
  // Знаходження найменшого елементу перебором масиву
  for (int i = 1; i < size; i++) 
    if (x[i] < x[min]) min = i;
  
  // Заміна елементів на 1
  for (int i = min + 1; i < size; i++) x[i] = 1;
  
  // Виведення результату
  cout << "\nМасив після заміни:\n";
  for (int i = 0; i < size; i++) cout << x[i] << ", ";

  return 0;
}
