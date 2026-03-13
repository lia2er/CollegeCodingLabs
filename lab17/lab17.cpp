#include <iostream>
#include <string>

using namespace std;

int main(){
  string sentence1, sentence2;
  cout << "Enter A sentence: ";
  getline(cin, sentence1);
  cout << "Now we need a new one: ";
  getline(cin, sentence2);
  int n = sentence1.rfind(' ');
  string word = sentence1.substr(n+1);
  int letPos = sentence2.find(word);
  if(letPos != sentence2.npos){
    sentence2.erase(letPos, word.length());
    cout << "Our new sentece: ";
    cout << sentence2 << endl;
  }
  else cout << "There`s no such word\n";

  return 0;
}
