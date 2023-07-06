#include <iostream>
using namespace std;

int main(){
    int large{0};
    int small{0};

    cout << "Welcome to Frank's Carpet Cleaning Service\nCharges:\n\t35€ per small room\n\t35€ per large room\nSalex tax rate is 6%\nEstimates are valid for 30 days" << endl;
    cout << "Enter the amount of small rooms to be cleaned" << endl;
    cin >> small;
    cout << "Enter the amount of large rooms to be cleaned" << endl;
    cin >> large;

    cout << "\nEstimate for the carpet cleaning service" << endl;
    cout << "Number of small rooms: " << small << "\nNumber of large rooms: " << large << endl;
    cout << "Price per small room: " << 25 << "€" << "\n Price per large room: " << 35 << "€" << endl;
    cout << "Cost: " << large*35+small*25 << "€\nTax: " << 0.06*(large*35+small*25) << "€" << endl;
    cout << "=======================================================" << endl;
    cout << "Total estimate: " << (large*35+small*25)+(0.06*(large*35+small*25)) << "€\nThis estimate is valid for 30 days";


    return 0;
}