#include "MString.h"
#include <cstring>
#include <iostream>


//Default constructor
MString::MString(): str{nullptr}{
    str= new char[1];
    *str='\0';
}
//Overload constructor
MString::MString(const char *s) : str{nullptr}{
    if(s == nullptr){
        str = new char[1];
        *str ='\0';
    }else{
        str = new char[std::strlen(s)+1];
        std::strcpy(str,s);
    }
}
//Copy constructor
MString::MString(const MString &source) : str{nullptr}{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
}
//Move constructor
MString::MString(MString &&source) : str(source.str){
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}

//Destructor
MString::~MString(){
    if(str ==nullptr){
        std::cout << "Calling destructor for MString: " << str <<std::endl;
    }
    else{
        std::cout << "Calling destructor for MString: " << str <<std::endl;
    }
    delete[] str;
}
//Copy assignment
MString &MString::operator=(const MString &source){
    std::cout << "Copy assignment" << std::endl;
    if(this == &source){
        return *this;
    }
    delete [] this->str; //str //or
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(this->str,source.str); //(str,source.str);
    return *this;
}
//Move assignment
MString &MString::operator=(MString &&source){
    std::cout << "Using move assignment" << std::endl;
    if(this == &source)
        return *this;
    delete [] str;
    str = source.str;
    source.str = nullptr;
    return *this;

}
//Print
void MString::display() const{
    std::cout << str << " : " << get_length() << std::endl;
}
//get Length
int MString::get_length() const {return std::strlen(str);}
//string getter
const char *MString::get_str() const{return str;}

//To lower case
//WHEN FRIEND method is on these are off
// MString MString::operator-(){
//     char *tmp = new char[std::strlen(str) + 1];
//     std::strcpy(tmp, str);
//     for (size_t i = 0; i < std::strlen(tmp); i++)
//         tmp[i] = std::tolower(tmp[i]);
//     MString temp {tmp};    
//     delete [] tmp;
//     return temp;
//  }
//  //Concatentate
// MString MString::operator+(const MString &source) const{
//     char *tmp = new char [std::strlen(str) + std::strlen(source.str) + 1];
//     std::strcpy(tmp, str);
//     std::strcat(tmp, source.str);
//     MString temp {tmp};
//     delete [] tmp;
//     return temp;

// }
// //Compare strings
// bool MString::operator==(const MString &source) const{
//     return (std::strcmp(str, source.str) == 0);
// }
// void MString::display() const{
//     std::cout << str << ": " << get_length() << std::endl;
// }
// int MString::get_length() const{
//     return std::strlen(str);
// }
// const char *MString::get_str() const{
//     return str;
// }

//Friend methods
//Equality
bool operator==(const MString &lhs, const MString &rhs){
    return ((std::strcmp(lhs.str, rhs.str)) == 0);  
}
//make lowercase
MString operator-(const MString &obj){
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for(size_t i = 0; i < strlen(buff); i++){
        buff[i] = std::tolower(buff[i]);
    }
    MString temp {buff};
    delete [] buff;
    return temp;
}
//concatenation
MString operator+(const MString &lhs, const MString&rhs){
    char *buff = new char [std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    MString temp {buff};
    delete [] buff;
    return temp;
}