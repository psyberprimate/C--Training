#ifndef _MSTRING_H_
#define _MSTRING_H_


class MString{

    friend std::ostream &operator<<(std::ostream &os, const MString &source);
    friend std::istream &operator>>(std::istream &in, MString &source);

    private:
        char *str;
    public:
        MString();  //No-args constructor
        MString(const char *s); // Overloaded constructor
        MString(const MString &source); // Copy constructor
        MString(MString &&source); // ; Move constructor
        ~MString(); //Destructor

        MString &operator=(const MString &source);//Overload asssignment operator - Copy assignment
        MString &operator=(MString &&source);     //Move assignment

        void display() const;
        int get_length() const; //getters
        const char *get_str() const;
};
#endif