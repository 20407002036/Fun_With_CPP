#include<iostream>
using namespace std;

int factorial(int);
int main(){
  int num;
  cout << "Enter a positive integer: ";
  cin >> num;

  if (num < 0)
    cout << "this is not a positive number";
  else
    cout << num << "factorial is " << factorial(int);
  endl;

int factorial(int num)
{
  int fact;

  if(num <= 1) return 1;

  fact = num * factorial(num - 1);
  return fact;
}
