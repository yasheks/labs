#include <iostream>
#include <clocale>
#include <math.h>
//6.2

void enter(int n, int m, int mas[20][20]){
  
  for (int i = 0; i < n; i++){
      for (int j = 0; j<m; j++){
        printf("введите число: ");
        scanf("%d", &mas[i][j]);
        printf("\n");
        
    }
  }
  
}

void print_matix(int n, int m, int mas[20][20]){
  printf("ваш массив: \n");
  for (int i = 0; i < n; i++){
      for (int j = 0; j<m; j++){
        
        printf("%d\t", mas[i][j]);
        
        
        
    }
    printf("\n");
  }
}

int fsum(int n, int m, int mas[20][20]){
  int suma = 0;
  for (int i = 0; i < n; i++){
      for (int j = 0; j<m; j++){
        suma += mas[i][j];    
        
    }
    
  }
  return suma;
}

int fmaxi(int n, int m, int & x, int & y, int mas[20][20]){
  int maxi = mas[0][0];
  
  for (int i = 0; i < n; i++){
      for (int j = 0; j<m; j++){
        if(mas[i][j] > maxi){
          maxi = mas[i][j];
          x = i + 1;
          y = j + 1;
      }
        
        
      }
  }
  return maxi;
}



int main()
{
  int mas[20][20], n, m, suma, maxi, x=1, y=1;
    setlocale(LC_CTYPE, "");
    printf("введите кол-во строчек в массиве: ");
    scanf("%d", &n);
    printf("введите кол-во столбиков в массиве: ");
    scanf("%d", &m);
    enter(n, m, mas);
    print_matix(n, m, mas);
    printf("общая сумма всех элементов = %d\n", fsum(n, m, mas));
    
    maxi = fmaxi(n, m, x, y, mas);
    
    printf("самое большое число = %d\n его координаты x и y - (%d, %d) \n его адрес - %d", maxi, x, y, &maxi);
    
    
    
    
  
    return 0;


}

