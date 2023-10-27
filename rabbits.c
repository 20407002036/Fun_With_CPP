#include<stdio.h>

int rabbit(int n, int t){
  int res;

  if(t = 0) {
    return n;
  }

  res = n * 12;

  rabbit(n + res, t - 1);
}

int main()
{
  int n = 1;
  int t = 5;
  int final;

  // printf("Enter the No. Sunguras: ");
  // scanf("%d",&n);

  // printf("Sunguras %d\n", n);
  
  // printf("Enter No of Periods: ");
  // scanf("%d",&t);
  
  // printf("Periods are : %d\n", t);
  // printf("Hello");

  final = rabbit(n, t);

 printf("The Total Rabbits are %d:",final); 

  return 0;
}
