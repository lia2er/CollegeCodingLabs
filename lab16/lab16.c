#include <stdio.h>

int main(){
  char sent[] = "Привіт приват банк аве Цезар, слава всім родам людським";
  char buff;
  int k = 0,
      j = 0;
  while(k < 90){
    buff = sent[k];
    printf("%c", sent[k]);
    k++;

  }
}
