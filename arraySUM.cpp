#include <iostream>

using namespace std;

int main(){
  int sum = 0;
  int a[4];

  // cout << "Enter 1st Numbers\n";
  //cin >> a[0];
  // cout << "Enter 2nd Numbers\n";
  //cin >> a[1];
  //cout << "Enter 3rd Numbers\n";
  //cin >> a[2];
  //cout << "Enter 4th Numbers\n";
  //cin >> a[3];

  for(int i = 0; i <= 3; i++){
    cout << "Enter a Number: ";
    cin >> a[i];
    sum = sum + a[i];
  }

  cout << "Sum = " << sum << endl;

  return (0);

}
