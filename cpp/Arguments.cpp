// -------------
// Arguments.c++
// -------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void by_value (int v) {
    ++v;}

void test1 () {
    const int i = 2;
    by_value(i);
    assert(i == 2);}



void by_address (int* p) {
    assert(p);
    ++*p;}

void test2 () {
    int j = 3;
    by_address(&j);
    assert(j == 4);
//  const int cj = 5;
//  by_address(&cj);  // error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
//  by_address(185);  // error: invalid conversion from 'int' to 'int*' [-fpermissive]
//  by_address(0);    // Assertion failed: (p), function by_address, file Arguments.c++, line 14.
    }



void by_reference (int& r) {
    ++r;}

void test3 () {
    int k = 4;
    by_reference(k);
    assert(k == 5);
//  const int ck = 6;
//  by_reference(ck);  // error: binding reference of type 'int&' to 'const int' discards qualifiers
//  by_reference(185); // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
//  by_reference(0);   // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    }



int main () {
    cout << "Arguments.c++" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
