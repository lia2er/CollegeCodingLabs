#include <cmath>    
#include <iomanip>  
#include <iostream> 

int main(){         
  const int size = 8;
                    
  float vectorX[size],   
        dobutok = 0.0f,
        vectorY[size] = {3.4, 3.1, 6.6, 7.2, 2.9, 1.5, 4.2, 5.8};
                        
  for(int i = 0; i < size; i++)
  {                            
    vectorX[i] = 2*sqrt(i+2);  
    dobutok += vectorX[i] * vectorY[i];
    std::cout << i+1 << std::fixed << std::setprecision(2) 
      << "-ої ітерації отримуємо - " << vectorX[i] 
      << " * " << vectorY[i] << " = " << vectorX[i]*vectorY[i]
      << " + " << dobutok << " = " << dobutok
      << std::endl;
  }       

  std::cout << std::fixed << std::setprecision(2) 
      << "Скалярний добуток: " << dobutok << std::endl; 

  return 0;  
}
