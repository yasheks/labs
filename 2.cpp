
#include <iostream>
#include<conio.h>
#include<clocale>
#include<cmath>
int main(int argc, char** argv) {
  setlocale(LC_CTYPE,"");
  int a1,a2,n;
  printf("Введите первое число:");
  scanf("%d",&a1);
  printf("Введите второе число:");
  scanf("%d",&a2);
  printf("Введите номер искомого слагаемого(n,n>2):");
  scanf("%d",&n);
  if (n<=2){
    printf("надо больше 2");
    return 1;
  }
  float an;
  float pred1=a2;
  float pred2=a1;
  
  for(int i=3;i<n;i++){
    an=pred1/10+2*pred2;
    pred2=pred1;
    pred1=an;
    printf("слагаемое а=%f\n",an);
  }
  return 0;
}
    
  
  номер 2
#include <iostream>
#include<conio.h>
#include<clocale>
#include<cmath>
int main(int argc, char** argv) {
  setlocale(LC_CTYPE,"");
  float alpha,n;
  printf("Введите угол:");
  scanf("%f",&alpha);
  printf("Введите конец:");
  scanf("%f",&n);
  float sigma1,sigma2;  
  for(int i=1;i<=n;i++){
    sigma1=(sin(i*alpha)/(pow(i,2)));
    sigma2+=sigma1;
  }
  printf("сумма=%f",sigma2);
  return 0;
}

номер 3
#include <iostream>
#include<conio.h>
#include<clocale>
#include<cmath>
int main(int argc, char** argv) {
  setlocale(LC_CTYPE,"");
  int a,b,h;
  printf("Введите начальное значение x:");
  scanf("%d",&a);
  printf("Введите начальное значение x:");
  scanf("%d",&b);
  printf("Введите шаг:");
  scanf("%d",&h);
  printf("%d,%d,%d",a,b,h);
  if (a>=b){
    printf("ты просто нулевый чел, меняй");
    return 1;
  } 
  printf("\nРезультаты Табуляции функции\n");
  printf("------------------------------\n");
  printf("     x          |         y   \n");
  printf("------------------------------\n");
  double x=a;
  int sc=0;
  const int mxs=1000;
  while (x<= b && sc <mxs){
    double y;
    if (x>=0 && x<10){
      if (x==0.0){
        printf("%fl  | не определена\n",x);
      }
      else{
        y=8*pow(x,3)+pow(x,2);
        printf("%fl  | %fl\n",x,y);
      }
    }
    else if (x>=-5 && x<0){
        if (x==0.0){
        printf("%fl  | не определена\n",x);
      }
      else{
        y=x/(x+3);
        printf("%fl  | %fl\n",x,y);
      }
      
    }
    x+=h;
    sc++;
    if (sc>=mxs){
      printf("\nДостигнуто максимальное количество шагов\n");
    }  
  }
  return 0;
  
}
