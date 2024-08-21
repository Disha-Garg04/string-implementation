#ifndef MYSTRING_H  //if not defined
#define MYSTRING_H  //defined using MACROS

#include <iostream>

class MyString {

private:
    char *data; //pointer to char array data
    int length; // size of my string

public:
    // default ctor
    MyString();

    // parameterized ctor
    MyString(const char *str);

    //copy ctor
    MyString(const MyString &other);

    // dtor
    ~MyString();

    // To get size of the string
    int size() const;

    // Check if string is empty
    bool empty() const;

    // Append string
    void append(const MyString &other);

    // Erase substring
    void erase(size_t pos, size_t len);

    // Return C-style string
    const char *c_str() const;
    
    // OPERATORS

    // Slicing
    char operator[](int index);

    // Concatenation (+=) operator
    MyString &operator+=(const MyString &other);

    // find substring
    int find(const MyString &substr) const;

    // overload insertion operator << for easy output
    friend std::ostream&operator<<(std::ostream&os, const MyString &str);

};

#endif //MYSTRING_H