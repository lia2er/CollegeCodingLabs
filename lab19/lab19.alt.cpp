#include <format>
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

int main(){
  int currentYear = stoi(format("{:%Y}", chrono::system_clock::now()));
  int highest = 0,
      i = 0;
  int N, C, T, size;
  cout << "How much oil rigs do we need? ";
  cin >> size;

  struct oil{
    string name;
    int year;
    int price;
    int extracted;
  } oilRigs[size];

  // creating file
  ofstream ofile("NAFTA");
  cout << "Creating file with data\n";
  for(int i = 0; i < size; i++){
    cout << "Enter oil rig name: ";
    cin >> oilRigs[i].name;
    cout << "Enter year when rig was made up: ";
    cin >> oilRigs[i].year;
    cout << "Enter price of oil per tonn: ";
    cin >> oilRigs[i].price;
    cout << "Enter how much of oil was extracted: ";
    cin >> oilRigs[i].extracted;
    ofile << oilRigs[i].name << " " << oilRigs[i].year << " " << oilRigs[i].price << " " << oilRigs[i].extracted << '\n';
    i++;
    cout << "--[Now enter next oil rig info]--\n";
  }
  ofile.close();
  // reading file
  ifstream ifile("NAFTA");
  while(i != 0){
    ifile >> oilRigs.name >> oilRigs.year >> oilRigs.price >> oilRigs.extracted;
    cout << format("So we have %s, %i, %f, %f", oilRigs.name, oilRigs.year, oilRigs.price, oilRigs.extracted);
    i--;
  }
  return 0;
}
