#include <iostream>
using namespace std;

int main(){

  int A[] = {2,8,5,3,9,4,1};

  for(int i = 0; i <= 6; i++){
    for(int j = i +1 ; j <= 6; j++){
      if(A[i] > A[j]){
	int temp;
	
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
      }
    //  cout<< A[j] << " ";
    }

//cout<< A[i] << " ";
  }

  for(int x = 0; x <= 6; x++){
   cout<< A[x] << " ";

  }
}
