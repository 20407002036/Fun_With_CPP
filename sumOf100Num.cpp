#include<iostream>
/*
 * This is the c++ implementation of the algorithm that sums
 *  any 100 Numbers given by the user
 *
 */
using namespace std;

int main(){
  int sum = 0;
  int count = 0;
  int i;

  while(count < 100){
    cout << "Enter a Number: ";
    cin >> i;

    sum = sum + i;
    count += 1;

  }

  cout << "Sum = " << sum <<"\n";


}
