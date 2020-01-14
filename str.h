///////////////////////////////////////////////////////////////////
//  str.h      -  header file for string class                   //
//                                                               //
//                                                               //
//  Language:     Visual C++                                     //
//                                                               //
//                                                               //
//  Author:       Simuk Arya                                     //
//                Syracuse University                            //
//                MSEE 2020, siarya@syr.edu                      //
///////////////////////////////////////////////////////////////////
/*
    Class Operations:
    =================
    
    This class displays type of operators and functions you can use
    to design a class in C++. This is a demo to have a deep understanfing
    of class design in c++.

    Public Interface:
    =================
    str s;                  construct an empty string;
    str s(15);              construct empty string that holds 15 chars
    str s1 = s;             construct s1 as a copy of s
    s1 = s2;                assign the value of s2 to the string s1
    s1[2] = 'a';            modify the 3rd character of s1
    char ch = s1[3];        read the 4th character of s1
    s1 += 'z';              append the character 'z'
    s1 += s2;               append the string s2 to the string s1
    s3 = s1 + s2;           concatenate s1 with s2 and assign to s3
    int len = s1.size();    get the number of characters held by s1
    s1.flush();             clear contents of s1, leaving empty string
    in >> s;                assign a string read from in to s
    out << s;               write a string to output stream;
*/
//

/*
    Maintenance History:
    ====================
    
    ver 1.0 :January 14,2020;
    - first release

*/



#pragma once
#define Test_string
#include<iostream>
using namespace std;

class str
{
public:
	char* array;
private:
	int len, max;                     // max=len+1;
public:
	str(int n = 10);                  // sized constructor;
	str(str& obj);                    // copy constructor;
	str(str&& obj);                   // move constructor;
	~str();							  // destructor;
	str operator=(const str& obj);          // copy assignment; 
	str operator=(str&& obj);		  // move constructor;
	char& operator[](int n);			  // index operator;
	str operator+=(char ch);		  // append character;
	str operator+=(const str& obj);   // append string;
	str operator+(const str& obj);    // concatenate string;
	int size() const;
	void flush();                     // clear string contents
};

ostream& operator<<(ostream& out, const str& obj);

istream& operator>>(istream& out, const str& obj);

inline int str::size() const { return len; }                // number of chars

inline void str::flush() { len = 0; }         // remove chars, but not storage