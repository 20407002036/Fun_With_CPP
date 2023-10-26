#include<iostream>

using namespace std;

int main(){

  double angle1, angle2, angle3;

  cout << "Enter angle1: ";
  cin >> angle1;

  cout << "Enter angle2: ";
  cin >> angle2;

  angle3 = 180 - angle1 - angle2;

  cout << "Angle3 = " << angle3 << endl;
}
