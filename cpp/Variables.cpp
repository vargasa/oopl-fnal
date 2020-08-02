// -------------
// Variables.c++
// -------------

// https://en.cppreference.com/w/cpp/language/pointer

#include <cassert>   // assert
#include <iostream>  // cout, endl

using namespace std;

void test1 () {
    int i = 2;
    int v = i;
    ++v;
    assert(i  == 2);
    assert(v  == 3);
    assert(&i != &v);}

void test2 () {
    int  j = 2;
    int* p;
//  p = j;             // error: invalid conversion from 'int' to 'int*' [-fpermissive]
    p = &j;
    ++*p;
    assert(j  == 3);
    assert(*p == 3);
    assert(p  == &j);}

void test3 () {
    int  k = 2;
//  int& r;            //  error: 'r' declared as reference but not initialized
//  int& r = &k;       // error: invalid conversion from 'int*' to 'int' [-fpermissive]
    int& r = k;
    ++r;
    assert(k  == 3);
    assert(r  == 3);
    assert(&r == &k);}

void test4 () {
    int   i = 2;
    int*  p = &i;
    int*& r = p;
    ++*r;
    assert(i  == 3);
    assert(*p == 3);
    assert(*r == 3);
    assert(&r == &p);}

int main () {
    cout << "Variables.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    cout << "Done." << endl;
    return 0;}
