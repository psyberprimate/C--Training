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

// non-Member method functions
//Equal
bool operator==(const Mystring &lhs, const Mystring &rhs){
    return ((std::strcmp(lhs.str, rhs.str)) == 0);  
}
//Not Equal
bool operator!=(const Mystring &lhs, const Mystring &rhs){
    return ((std::strcmp(lhs.str, rhs.str)) == 1);  
}
// Larger than
bool operator>(const Mystring &lhs, const Mystring &rhs){
    return ((std::strcmp(lhs.str, rhs.str)) > 0);  
}
// Smaller than
bool operator<(const Mystring &lhs, const Mystring &rhs){
    return ((std::strcmp(lhs.str, rhs.str)) < 0);  
}

//make lowercase
Mystring operator-(const Mystring &obj){
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for(size_t i = 0; i < strlen(buff); i++){
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
//concatenation
Mystring operator+(const Mystring &lhs, const Mystring&rhs){
    char *buff = new char [std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
// Concatenate objects
Mystring &operator+=(Mystring &lhs, const Mystring &rhs){ 
    lhs = lhs + rhs;
    return lhs;
} 
//Concatenate strings n times
Mystring operator*(const Mystring &rhs, size_t count){
    size_t len = strlen(rhs.str);
    char *buff = new char[len*count + 1];
    std::strcpy(buff, rhs.str);
    for (size_t i = 0; i < count-1; i++){
        std::strcat(buff, rhs.str);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}
//Concatenate string n times and return Mystring
Mystring &operator*=(Mystring &lhs, size_t count){
    lhs = lhs * count;
    return lhs;
}
Mystring operator++(const Mystring &lhs){
    for(size_t i = 0; i < strlen(lhs.str); i++) 
        lhs.str[i] = std::toupper(lhs.str[i]);
    return lhs;
}
Mystring operator++(const Mystring &lhs, int){
    Mystring temp = lhs;
    operator++(lhs);
    return temp;
}