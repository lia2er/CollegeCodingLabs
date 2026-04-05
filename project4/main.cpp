#include <iostream>

using namespace std;

void setArray(int arr[]){
  for(int i = 0; i < 5; i++){
    cout << "Enter digit: ";
    cin >> arr[i];
  }
}

void printArray(int arr[]){
  cout << endl;
  for(int i = 0; i < 5; i++)
    cout << arr[i] << '\t';
}

void Sum(int a, int b) {
  cout << "Your sum is: " << a+b << endl;
}

void Sum(int arr[], int brr[]){
  for(int i = 0; i < 5; i++)
    cout << arr[i] + brr[i] << '\t';
}

void BubbleSort(int arr[], int size){
  for (int i = 0; i < size - 1; i++) 
    for (int j = 0; j < size - i - 1; j++) 
      if (arr[j] > arr[j + 1]) 
        swap(arr[j], arr[j + 1]);
  printArray(arr);
}
int main(){
  int M1[5], M2[5];
  setArray(M1);
  setArray(M2);
  Sum(M1, M2);
  BubbleSort(M1, 5);
  BubbleSort(M2, 5);

  return 0;
}
