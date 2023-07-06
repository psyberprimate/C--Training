// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PrintException.h"

void readFile(const std::string &file_name);
void copyString(std::ofstream &out_file, const std::string &str, int &count);

int main() {
    std::string file_name = "romeoandjuliet.txt";

    std::cout << "Entering lines numbers to Romeo and Juliet text" << std::endl;

    try{
        readFile(file_name);
    }
    catch(const PrintException & ex){
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "File copying done ->";
    return 0;
}

void readFile(const std::string &file_name){

    std::string file_name_out = "romeoandjulietLines.txt";
    std::ifstream in_file;
    std::ofstream out_file;

    std::string read_line{};
    int count{1};

    in_file.open(file_name);
    out_file.open(file_name_out);
    if(!in_file){
        std::cerr << "Problem reading the file" << std::endl;
        throw PrintException();
    }
    if(!out_file){
        std::cerr << "Problem opening the file" << std::endl;
        throw PrintException();
    }
    while (std::getline(in_file, read_line)){
        copyString(out_file, read_line, count);
        count++;
    }
    in_file.close();
    out_file.close();
}
void copyString(std::ofstream &out_file, const std::string &str, int &count){
    if (str != ""){
        out_file << count << std::left << std::setw(5) << "." <<  str  << std::endl;
    }
    else{
         out_file << std::endl;
    }
    
}