#include<iostream>

using namespace std;
int fact = 1;
int factorial(int x);

int main(){
    int y = factorial(5);

    cout << "The factorial of 5 is "<< y << endl;

}

int factorial(int x){
    //int fact = 1; 
    if(x == 1){
        return (fact);
    }

    fact = fact * x;
    // This is an impelentation of a code that I wrote in th exam: Finals
    // I ended up writting this as it is.
    // But I missed out in enclosing the factorial down here in a return.

   return(factorial(x - 1));
}