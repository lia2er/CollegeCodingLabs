// підключення заголовкових файлів для:
#include <format> // функції format для форматування рядків
#include <iostream> // функцій потоків вводу/виводу
#include <fstream> // для функцій файлових потоків
#include <chrono> // для функцій отримання поточного часу
#include <string> // для класу string

using namespace std; // використання простору імен std

struct oil{ // створення глобальної структури oil
  string name;
  int year;
  int price;
  int extracted;
} oilRigs, mostExtractedOil; // оголошення деяких змінних струкртури oil

int currentYear = // ініціалізація змінної
    stoi( // переведення рядка в цілочисельний тип
      // отримання поточних даних про час, і застосивання формату :%Y до рядка для отримання року
      format("{:%Y}", chrono::system_clock::now())); 

// попереднє оголошення функцій
void writeFile(int &i);
void doTask(int &i, int T, int C);

int main(){ // головна функція
  int highest = 0, // ініціалізація змінних highest, i 
      i = 0;
  int N, C, T; //  Оголошення змінних N, C, T 

  writeFile(i); // виклик функції з аргументом і
  N = i; // присвоєння змінній N значення змінної i
  cout << "\nWe know " << N << " oil rigs so far\n"; // виведення тексту
  cout << "--[ How young oil rig can be?\n $ "; // виведення підказки
  cin >> T; // отримання вводу з клавіатури і його запис в змінну T
  cout << "--[ What`s the highest acceptable price?\n $ "; // виведення підказки
  cin >> C; // отримання вводу з клавіатури і його запис в змінну C

  doTask(i, T, C); // виклик функції з аргументами i, T, C

  return 0; // синхронізація з препроцесором
} // кінець функції main

// реалізація функції writeFile, де аргументом є вказівник на адресу змінної i
void writeFile(int &i){
  // створення об`єкту ofile("NAFTA") класу ofstream(output file stream)
  ofstream ofile("NAFTA");
  // Нескінченний цикл
  while(true){
    cout << "Enter oil rig name(type \"stop\" when enough): "; // виведення підказки
    cin >> oilRigs.name; // запис вводу з клавіатури в елемент name структури oilRigs
    if(oilRigs.name == "stop") break; // якщо користувач вводить "stop" виконується вихід з циклу
    cout << "Enter year when rig was made up: "; // виведення підказки
    cin >> oilRigs.year; // запис вводу з клавіатури в елемент year структури oilRigs
    cout << "Enter price of oil per tonn: "; // виведення підказки
    cin >> oilRigs.price; // запис вводу з клавіатури в елемент year структури oilRigs
    cout << "Enter how much of oil was extracted: "; // виведення підказки
    cin >> oilRigs.extracted; // запис вводу з клавіатури в елемент year структури oilRigs
    ofile << oilRigs.name << " " // запис в файл oilRigs.name і " "
      << oilRigs.year << " "  // запис в файл oilRigs.year і " "
      << oilRigs.price << " "  // запис в файл oilRigs.price і " "
      << oilRigs.extracted << '\n'; // запис в файл oilRigs.extracted і "\n"
    i++; // інкрементація i
    cout << "--[Now enter next oil rig info]--\n"; // виведення тексту
  }
  ofile.close(); // закриття файлового потоку виводу
}

// реалізація функції doTask, де аргументом є вказівник на адресу змінної i, і змінні T, C
void doTask(int &i, int T, int C){
  // створення об`єкту ifile("NAFTA") класу ifstream(input file stream)
  ifstream ifile("NAFTA");
  // створення об`єкту ofile("B1") класу ofstream(output file stream)
  ofstream ofile("B1");
  // поки лічильник не буде дорівнювати нулю
  while(i != 0){
    // запис в змінні прочитані елементи з файлу NAFTA потоку введення
    ifile >> oilRigs.name >> oilRigs.year >> oilRigs.price >> oilRigs.extracted;
    // перевірка чи oilRigs.price менше C і одночано currentYear - oilRigs.year більше T
    if(oilRigs.price < C and (currentYear - oilRigs.year) > T) 
      ofile << oilRigs.name << '\n'; // Запис імені даного родовища в файл B1
    // пошук родовища з найбільшим видобутком
    if(oilRigs.extracted > mostExtractedOil.extracted) mostExtractedOil = oilRigs;
    i--; // декрементація лічильника
  }
  cout << mostExtractedOil.name << " extracted the most of oil\n"; // виведення тексту
  ofile.close(); // закриття файлового потоку виведення ofile
  ifile.close(); // закриття файлового потоку введення ifile
}
