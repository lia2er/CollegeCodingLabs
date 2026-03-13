// Підключення заголовкових файлів:
#include <iostream> // для функцій потоків введення/виведення
#include <string> // для використання класу string і його функцій

using namespace std; // Підключення простору імен std з потоками


int main(){ // головна функція
  int size = 2; // Ініціалізація змінної для збереження розміру масиву
  string sentence[size]; // Оголошення масиву символьних рядків на size елементів

  for(int i = 0; i < size; i++){ // Цикл з лічильником
    cout << "Enter a sentence: "; // Виведення підказки
    getline(cin,sentence[i]); // Читання рядка з буфера cin і запис в елемент масиву
  }

  for(int i = 0; i < size; i++){ // Цикл з лічильником
    int firstWordPos = sentence[i].find_first_of(' '); // Ініціалізація змінної з
                                                       // позицією першого пробілу
    int lastWordPos = sentence[i].find_last_of(' ') + 1;// Ініціалізація змінної з
                                                        // позицією останнього пробілу

    // знаходжу слова по індексу пробілів
    string firstWord = sentence[i].substr(0, firstWordPos); // Ініціалізація рядкової
           // змінної і запис в неї підрядка з sentence[i] від індекса 0 до firstWordPos 
    string lastWord = sentence[i].substr(lastWordPos); // Ініціалізація рядкової
           // змінної і запис в неї підрядка з sentence[i] від індекса lastWordPos
           // до кінця рядка

    firstWord[0] = tolower(firstWord[0]); // переведення першої літери 
                                                // першого слова до нижнього регістру
    lastWord[0] = toupper(lastWord[0]);  // переведення першої літери 
                                               // останнього слова до верхнього регістру

    sentence[i].erase(lastWordPos); // видалення останнього слова з рядка [i] масиву 
                                    // sentence від lastWordPos до кінця рядка
    sentence[i].erase(0, firstWordPos); // видалення першого слова з рядка [i] масиву 
                                        // sentence від 0 до firstWordPos


    sentence[i].insert(0, lastWord); // insert() - вставляє символьний рядок lastWord
                                     // в позицію 0 рядка sentence[i]
    sentence[i].append(firstWord); // append() - приєднує firstWord до кінця рядка sentence[i]
    cout << "New string is: " << sentence[i] << endl; // виведення зміненого рядка і перехід
                                                      // на новий рядок
  }
  return 0; // Синхронізація з препроцесором
}
