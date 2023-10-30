#include<iostream>
/* This is a c++ implementation of the algorithm that was developed
 *  in class to read 100 numbers and print the largest
 *
 */
using namespace std;

int main(){
  double largest = 0;
  int count = 0, Numb = 0;

  while(count < 100){
    cout << "Enter a number: ";
    cin >> Numb;

    if (Numb > largest){
	largest = Numb;
      }

    count++;
  }

  cout << "The Largest number enterd is " << largest << "\n";

}
