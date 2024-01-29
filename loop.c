#include <stdio.h>

int main(){
  int i = 0;
  /* The main reason I wrote this was to check the loop, what if I give a condition where the i is now 0 and i is greater than 10.
     turns out if the initial value is off loop, nothing hapens , the for loop is never executed
   */
  for(i = 0; i >10; i++){
    printf("The value is %d", i);
  }

}
