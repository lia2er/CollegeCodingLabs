#include <iostream> // заголовковий файл з потоками введення/виведення

  using namespace std; // використання простору імен std

void setArray(int M[]){ // функція для задання масиву
  for(int i = 0; i < 5; i++){
    cout << "Enter digit: ";
    cin >> M[i];
  }
}

void printArray(int M[], int size){ // функція для виведення масиву
  cout << endl;
  for(int i = 0; i < size; i++)
    cout << M[i] << '\t';
  cout << endl;
}

int Sum(int a, int b) { // розрахунок суми
  return a+b;
}

int Sum(int M1[], int M2[]){ // функція для поелементної суми масивів
  int sum;
  for(int i = 0; i < 5; i++)
    sum += M1[i] + M2[i];
  return sum; 
}

void BubbleSort(int M[], int size){ // сортування бульбашкою
  for (int i = 0; i < size - 1; i++) // проходи
    for (int j = 0; j < size - i - 1; j++) // ітерації сортування
      if (M[j] > M[j + 1]) 
        swap(M[j], M[j + 1]); // поміняту елементи місцями
  printArray(M, 5); // виклик функції для друку масиву
}

void InsertElement(int M[], int index, int value){ // функція для вставки елемента в масив
  for(int i = sizeof(M) / sizeof(M[0]) - 1; i > index; i--)
    M[i] = M[i-1]; // зсув/перестановка
  M[index] = value;
}

int main(){
  // оголошення масивів
  int M1[6], M2[6];
  // задання масивів через фунцкції
  setArray(M1);
  setArray(M2);
  // виведення ретексту і поверненого значення функції Sum
  cout << "Sum is: " << Sum(M1, M2) << endl;
  // Сортування масивів
  cout << "Array M1 now sorted: ";
  BubbleSort(M1, 5);
  cout << "Array M2 now sorted: ";
  BubbleSort(M2, 5);
  // вставка елемента в початок масиву
  cout << "Enter value to insert into array: ";
  int value;
  cin >> value;
  InsertElement(M1, 0, value);
  // виведення масиву
  cout << "Inserted element " << value << " in array M1: ";
  printArray(M1, 6);
  return 0;
}
