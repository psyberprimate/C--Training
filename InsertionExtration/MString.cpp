#include <iostream>
#include <cstring>
#include "MString.h"

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

//Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const MString &source){
    os << source.str;
    return os;
}
//Overloaded extraction operator
std::istream &operator>>(std::istream &in, MString &source){
    char *buff = new char[1000];
    in >> buff;
    source = MString{buff};
    delete [] buff;
    return in;
}




