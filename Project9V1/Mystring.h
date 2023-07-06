#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment

    //Overloaded operators assignment
    Mystring operator-(); //To lower case
    //Comparinson operators
    bool operator==(const Mystring &obj) const;
    bool operator!=(const Mystring &obj) const;
    bool operator<(const Mystring &obj) const;
    bool operator>(const Mystring &obj) const;

    Mystring operator+(const Mystring &obj) const;   //Concatenate strings
    Mystring &operator+=(const Mystring &obj);       //Add to concatenated strings

    Mystring operator*(size_t count) const;                    //Concatenate strings n times
    Mystring &operator*=(size_t count); //Concatenate string n times and return Mystring

    Mystring &operator++(); //pre-increment
    Mystring operator++(int); //post-increment

    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_