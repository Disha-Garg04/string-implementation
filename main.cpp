#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

int main () {

    MyString s("Codehelp is best");
    // cout<< s[0]<< endl;  -> will give error as we have not defined indexing yet
    cout<< s[0]<< endl;
    cout<<s.find("best") << endl;

    MyString a = "Hello";
    MyString b = " Duniya";

    // a += b;
    // cout<<a<<endl;

    b.append(" appending");

    b.erase(8,2);

    cout<<b<<endl;

    return 0;
}