
#include<iostream>

using namespace std;

int rabbit(int n, int t)
{
  int res;

  if(t = 0) {
    return n;
  }

  res = n * 12;

  return(rabbit(n + res, t - 1));
}

int main()
{
  int n;
  int t;

  cout <<"Enter the No. Sunguras: ";
  cin >> n;

  cout << "Sunguras: " << n;
  
  cout << "Enter No of Periods: ";
  cin>> t;
  
  cout << "Periods are : " << t;
  cout << "Hello";

  cout << "The Total Rabbits are " << rabbit(n, t);
  return 0;
}
