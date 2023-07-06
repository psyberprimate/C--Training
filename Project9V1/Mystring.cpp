#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// Member method functions

//To lower case
 Mystring Mystring::operator-(){
    char *buff = new char [strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < strlen(str); i++){
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
 }
//Bool = equal true
bool Mystring::operator==(const Mystring &obj) const{
    return (std::strcmp(str, obj.str) == 0);
}
//Bool = equal false
bool Mystring::operator!=(const Mystring &obj) const{
    return !(std::strcmp(str, obj.str) == 0);
}
//Bool = greater than
bool Mystring::operator<(const Mystring &obj) const{
    return (std::strcmp(str, obj.str) < 0);
}
//Bool = less than
bool Mystring::operator>(const Mystring &obj) const{
    return (std::strcmp(str, obj.str) > 0);
}
//Concatenate strings
Mystring Mystring::operator+(const Mystring &obj) const{
    char *buff = new char [strlen(str) + strlen(obj.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, obj.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}
//Add to concatenated string
Mystring &Mystring::operator+=(const Mystring &obj){
    //Mystring str = *this;
    *this = *this + obj;
    return *this;
// the same
/*
        Mystring str;
        str = str + obj;
        return str;
*/
}
//Concatenate the string n times
Mystring Mystring::operator*(size_t count) const{
    size_t len = strlen(str);
    char *buff = new char[len*count + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < count-1; i++){
        std::strcat(buff, str);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}
//Concatenate string n times and return Mystring
Mystring &Mystring::operator*=(size_t count){
      *this = *this * count;
      return *this;
}
//pre-increment
 Mystring &Mystring::operator++(){
    //Mystring str = *this;
    /*char *buff = new char [strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i = 0; i < strlen(str); i++) 
        buff[i] = ;
    return *this; */

    for(size_t i = 0; i < strlen(str); i++) 
        str[i] = std::toupper(str[i]);
    return *this;

 }
//post-increment
 Mystring Mystring::operator++(int){
    Mystring temp (*this);
    operator++();
    return temp;
 }

