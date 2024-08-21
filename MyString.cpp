#include "MyString.h"
#include <cstring> //strcpy jaise functions hote hain isi mei

// definitions of all the functions declared in MyString.h

// MyString::MyString() -> This means MyString class k MyString function ko implement krna hai
// Default Constructor
MyString::MyString() {
    data = new char[1];
    length = 0;
    data[0] = '\0'; //Basic implementation of string
}

// Parameterized ctor
MyString::MyString(const char *str) {
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data, str);
}


//  Copy Constructor
MyString::MyString(const MyString &other){
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);
}


//  Destructor
MyString::~MyString(){
    delete[] data;
}

// get size
int MyString::size() const {
    return length;
}

// Empty 
bool MyString:: empty() const {
    return length == 0;
}

// Append string
void MyString::append(const MyString &other)
{
    *this += other;
}

const char *MyString:: c_str() const {
    return data;
}


// ( << ) operator
std::ostream&operator<<(std::ostream&os, const MyString &str){
    os << str.c_str();
    return os;
}


// Subscript operator []
char MyString::operator[](int index){
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// Concatenation (+=) operator
MyString &MyString::operator+=(const MyString &other)
{
    char *newData = new char[length + other.length + 1];
    strcpy(newData, data);
    strcat(newData, other.data);

    // Free old memory and assign new data
    delete[] data;
    data = newData;
    length += other.length;

    return *this;
}

// find substring
int MyString:: find(const MyString &substr) const {
    if(substr.length > length) {
        return -1;
    }
    for(int i =0; i<= length - substr.length; i++) {
        int j;
        for(j=0; j<substr.length; j++){ //substr pr loop chlega
            if(data[i + j] != substr.data[j]) {  //jahan bhi dono unequal aagye hum break krdenge
                break;
            }
        }

        if( j== substr.length){
            return i;
        }
    }

}

// Erase substring
void MyString::erase(size_t pos, size_t len) {
    if (pos >= length) {
        throw std::out_of_range("Position out of range");
    }
    
    if (len == 0) {
        return;
    }
    
    if (len > length - pos) {
        len = length - pos; // Erase till the end if len exceeds the string length from pos
    }

    // Calculate new length
    size_t newLength = length - len;
    
    // Create new data array
    char *newData = new char[newLength + 1];
    
    // Copy characters before 'pos'
    strncpy(newData, data, pos);
    
    // Copy characters after 'pos + len'
    strcpy(newData + pos, data + pos + len);
    
    // Null-terminate the new string
    newData[newLength] = '\0';
    
    // Delete old data and replace with new data
    delete[] data;
    data = newData;
    
    // Update length
    length = newLength;
}

// // Assignment operator
// MyString &MyString::operator=(const MyString &other)
// {
//     if (this == &other)
//     {
//         return *this; // Return *this to deal with self-assignment
//     }

//     // Free existing resources
//     delete[] data;

//     // Copy data from other string
//     data = new char[other.length + 1];
//     length = other.length;
//     strcpy(data, other.data);

//     return *this;
// }

