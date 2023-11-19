#include<iostream>
/*
 * This is a c++ implementation of the class work algorithm that was developed
 * during a class that could be used in a hospital setup to get the
 * heights of the attendees and at the end of the day,
 * the system would be able to give the highest Tallest, shortest, Count of the
 * patients and Average of the heights taken.
 */

using namespace std;

int main(){

  double sum = 0;
  double tallest = 0;
  double shortest = 100;
  int count = 0;
  string ans;
  double height;
  double average;

  while (1){
    cout << "Is There a patient? Yes(y) or No(n): ";
    cin >> ans;

    if (ans == "y" || ans == "Yes"){
      cout << "Enter Patient weight: ";
      cin >> height;
 
      count++;
      sum = sum + height;

      if (height > tallest){
	tallest = height;
	  }
      if (height < shortest){
	shortest = height;
      }

    }
    else if (ans == "n" || ans == "No"){

      break;
    }
    else{
      cout << "Invalid input...\n";
    }
  }
    average = sum / count;


    cout << "Shortest = " << shortest << "\nTallest = " << tallest << "\nAvarage height = " << average << "\nCount = " << count << "\n";

  

}
