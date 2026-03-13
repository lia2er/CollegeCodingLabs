#include <iostream>

using namespace std;

int main(){
  const char sentence[] = "Hi, absolute number wasn`t found, user got banned, a b c";
  int n = 0;
  cout << "Our text is: \n" << sentence << endl; 
  while(sentence[n] != '\0'){
    if(sentence[n] == 'a' and sentence[n+1] == ' ' and sentence[n+2] == 'b') 
      cout << "Found a and b, at position of " << n+1 << endl;
    if(sentence[n] == 'a' and sentence[n+1] == 'b') 
      cout << "Found ab, at position of " << n+1 << endl;
    if(sentence[n] == 'b' and sentence[n+1] == 'a') 
      cout << "Found ba, at position of " << n+1 << endl;
    n++; // лічильник літер
  }
  return 0;
}
