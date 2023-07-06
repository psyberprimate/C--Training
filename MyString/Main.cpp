#include <iostream>
#include <vector>
#include "MString.h"

int main(){


    // MString lars{"Larss"};
    // MString mole{"mole"};

    // MString stooge = lars;
    // lars.display();
    // mole.display();

    // std::cout << (lars == mole) << std::endl;
    // std::cout << (lars == stooge) << std::endl;

    // lars.display();
    // MString lars2 = -lars;
    // lars2.display();

    // MString stooges = lars + "MOLE";

    // MString two_moles = mole + " " + "EE" ;

    // stooges.display();
    // two_moles.display();

    // MString hey{"Hello"};
    // hey = MString{"Hola"};
    // hey = "Bonjour";

    // MString empty;
    // MString yay("YAY");
    // MString nay{yay};

    // MString yay("YAYNAY");
    // MString nay;
    // nay = yay;
    // nay = "This is a test YAY"; 

 //   empty.display();
//   yay.display();
//    nay.display();

    MString larry {"Larry"};
    larry.display();
    larry = -larry;
    larry.display();

    
    MString moe{"Moe"};
    MString stooge = larry;

    std::cout << (larry == moe) << std::endl;
    std::cout << (larry == stooge) << std::endl;


    return 0;
}