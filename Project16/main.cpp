// Section 19
// Challenge 3
// Word counter

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "PrintException.h"

void searchFile(const std::string &file_name, const std::string &input);
void compareStrings(const std::string &read_value, const std::string &input, int &count);
void printResults(const std::string &input, const int &count, const int &total_words);

int counter(int &count);

int main() {
    
    std::string file_name = "romeoandjuliet.txt";
    std::string input{};
 
    do{
        std::cout << "Enter a string to search from Romeo and Juliet play:" << std::endl;
        std::cout << "Type a string to search for OR 'Exit' to stop searching for more strings: ";
        std::getline(std::cin, input);

        try {
            searchFile(file_name, input);
        }
        catch(const PrintException &ex){
            std::cerr << ex.what() << std::endl;
        }
    }
    while(input != "Exit" );
    return 0;
}
//Search the file function
void searchFile(const std::string &file_name, const std::string &input){

    int count{0};
    std::string read_string;
    int word_count{0};

    std::ifstream in_file;
    in_file.open(file_name);
    if(!in_file){
        std::cerr << "Problem reading the file" << std::endl;
        throw PrintException();
    }
    while (in_file >> read_string){
        compareStrings(read_string, input, count);
        word_count++;
    }
    printResults(input, count, word_count);
}
//Compare strings function
void compareStrings(const std::string &read_value, const std::string &input, int &count){
    size_t found = read_value.find(input);
    if (found != std::string::npos){
        counter(count);
    }
}
int counter(int &count){
    return count++;
}
void printResults(const std::string &input, const int &count, const int &total_words){
    std::cout << std::endl << "After searching the file for: " << total_words << std::endl;
    std::cout <<"For word: " << input << " : " << count << " search matches" << std::endl;
}