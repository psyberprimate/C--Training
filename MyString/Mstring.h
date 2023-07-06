#ifndef _MSTRING_H_
#define _MSTRING_H_

class MString{
    //WHEN FRIEND method is on class methods operators are off
    friend bool operator==(const MString &lhs, const MString &rhs);
    friend MString operator-(const MString &obj);
    friend MString operator+(const MString &lhs, const MString &rhs);

    private:
        char *str;
    public:
        MString();
        MString(const char *s);
        MString(const MString &source);
        MString(MString &&source);
        ~MString();

        MString &operator=(const MString &source);//Overload asssignment operator
        MString &operator=(MString &&source);     //Move assignment
        
        // MString operator-();                      //make lowercase - Unary operator - 
        // MString operator+(const MString &source) const; //concatenate
        // bool operator==(const MString &source) const; //Equal assignment

        void display() const;
        int get_length() const;
        const char *get_str() const;
};
#endif