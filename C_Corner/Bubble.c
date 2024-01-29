#include <stdio.h>


int main(void){
  int a[] = {12, 23, 54, 0 , 97, 34, 198, 200};
  int length = 8;


  for (int i = 0; i < length; i++){
    // This just moves the position.

    for (int j = 0; j < (length - 1); j++){
      if (a[j] > a[j + 1]){
	int temp = a[j];
	a[j] = a[j + 1];
	a[j + 1] = temp;
      }

    }
  }

  for(int i = 0; i < length; i++){

    printf("Valie at a[%d] = %d\n", i, a[i]);
  }
}
