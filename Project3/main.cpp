#include <iostream>
#include <vector>
using namespace std;

int main (){

    int number_of_cents {0};

    const int dollar {100};
    const int quarter {25};
    const int dime {10};
    const int nickel {5};
    const int penny {1};

    int balance{0};
    int dollars{0};
    int quarters{0};
    int dimes{0};
    int nickels{0};
    int pennies{0};

    cout << "Enter the amount of cents you have: " << endl;
    cin >> number_of_cents;

    dollars = number_of_cents/dollar;
    quarters = (number_of_cents%dollar)/quarter;
    dimes = ((number_of_cents%dollar)%quarter)/dime;
    nickels = (((number_of_cents%dollar)%quarter)%dime)/nickel;
    pennies = ((((number_of_cents%dollar)%quarter)%dime)%nickel)/penny;

    cout << "You can provide this change as follows: " << endl;

    cout << "Dollars : " << dollars << endl;
    cout << "Quarters : " << quarters << endl;
    cout << "Dimes : " << dimes << endl;
    cout << "Nickels : " << nickels << endl;
    cout << "Pennies : " << pennies << endl;

    return 0;
}