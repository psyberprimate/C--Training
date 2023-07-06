#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(){

    std::string line {};
    int j = 0;
    int k = 0;
    std::cout << "Welcome to the program, enter a string characters to be used in a pyramid" <<std::endl;

    getline(std::cin, line);
    std::cout << "--------------------" << std::endl;
    for(char c: line){
        k += 1;
    }
    for(char c: line){

        for (int i=k-j; i >= 0; i--){
            std::cout << " ";
        }
        for (int i=0; i < j; i++){
            std::cout << line.at(i);
        }
        std::cout << c;
        for (int i=j-1; i >= 0; i--){
            std::cout << line.at(i);
        }       
        std::cout << std::endl;
        std::cout << std::endl;   
        j++;   
    }    
    return 0;
}