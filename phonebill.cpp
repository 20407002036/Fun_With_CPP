#include <iostream>
using namespace std;

int calccost(string time, string Network, int min);
int vat(int min, int cost);

int main(){
    string time;
    string Network;
    int min;

    cout << "Enter time of day(Am/Pm)";
    cin >> time;

    cout << "Enter network to contact(Saf/Airtel)";
    cin >> Network;

    cout << "Enter Minutes talked: ";
    cin >> min;

    int pesa = calccost(time,Network,min);

    cout << "The cost is "<< pesa << endl;
    
     }

int calccost(string time, string Network, int min){
    int cost;
    int TotalCost;

    if (Network == "Saf" || Network == "saf")
    {
         if (time == "am" || time == "Am"){
                cost = min * 4;

               TotalCost = vat(min,cost);
            }
        else if (time == "pm" || time == "Pm"){
                cost = min * 3;

               TotalCost = vat(min,cost);
            }
    }
    else{
        cost = min * 5;

       TotalCost = vat(min,cost);
    }

    return(TotalCost);
}

int vat(int min, int cost){
    if (min > 2){
        cost = cost + (0.16 * cost);
    }
    else {
        
    }

    return(cost);
}