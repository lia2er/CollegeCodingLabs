#include <iostream>
#include <math.h>
#include <iomanip>

int main(){
  float m[3] = {-1.85, 2.39, 3.65};
  float z,
        q = 2.8;

  start_compute:
  if (q <= 5.4){
    std::cout << std::fixed << std::setprecision(2) 
      << "q = " << q << std::endl;
    for(int i = 0; i < 3; i++){
      z = m[i] + (exp(m[i]/m[i])-q)/(1-m[i]);
      std::cout << std::fixed << std::setprecision(2)
        << "z = " 
        << z << "\tm[" << i << "] = "
        << m[i]
        << std::endl;
    }
    q += 1.3;
  goto start_compute;
  } else goto end;
  end:
  return 0;
}
