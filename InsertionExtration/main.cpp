#include <iostream>
#include "MString.h"

int main(){

    MString larry {"Larry"};
    MString moe{"Moe"};
    MString curly;

    std::cout << "Enter the third name: ";

    std::cin >> curly;
    
    std::cout << "The three names are: " << larry << ", " << moe << ", and " << curly << std::endl;

    std::cout << "Enter the three names separated by a space: ";
    std::cin >> larry >> moe >> curly;

    std::cout << "The three names are: " << larry << ", " << moe << ", and " << curly << std::endl;

    return 0;
}