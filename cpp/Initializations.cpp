// -------------------
// Initializations.c++
// -------------------

// http://en.cppreference.com/w/cpp/language/value_initialization
// http://en.cppreference.com/w/cpp/language/initializer_list
// http://en.cppreference.com/w/cpp/utility/initializer_list

#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <vector>           // vector

using namespace std;

void test1 () {
    int i(2);
    assert(i == 2);

    int j = 2;
    assert(j == 2);

    int k{2};
    assert(k == 2);

    int l = {2};
    assert(l == 2);}



void test2 () {
    int i(2.0);
    assert(i == 2);

    int j = 2.0;
    assert(j == 2);

//  int k{2.0};     // error: narrowing conversion of '2.0e+0' from 'double' to 'int'

//  int l = {2.0};  // error: narrowing conversion of '2.0e+0' from 'double' to 'int'
    }



struct A3 {
    int i;
    int j;};

void test3 () {
//  A3 x(2, 3);    // error: no matching function for call to 'A1::A1(int, int)'

    A3 z{2, 3};
    assert(&z);

    A3 t = {2, 3};
    assert(&t);}



struct A4 {
    int i;
    int j;

    A4 (int, int)
        {}};

void test4 () {
    A4 x(2, 3);
    assert(&x);

    A4 z{2, 3};
    assert(&z);

    A4 t = {2, 3};
    assert(&t);}



struct A5 {
    int i;
    int j;

    explicit A5 (int, int)
        {}};

void test5 () {
    A5 x(2, 3);
    assert(&x);

    A5 z{2, 3};
    assert(&z);

//  A5 t = {2, 3}; // error: converting to 'B' from initializer list would use explicit constructor 'B::B(int, int)'
    }



struct A6 {
    int i;
    int j;

    A6 (initializer_list<int>)
        {}};

void test6 () {
//  A6 x(2, 3);    // error: no matching function for call to 'C::C(int)'

    A6 z{2, 3};
    assert(&z);

    A6 t = {2, 3};
    assert(&t);}



struct A7 {
    int i;
    int j;

    explicit A7 (initializer_list<int>)
        {}};

void test7 () {
//  A7 x(2, 3);   // error: no matching function for call to 'D::D(int)'

    A7 z{2, 3};
    assert(&z);

//  A7 t = {2, 3}; // error: converting to 'D' from initializer list would use explicit constructor 'D::D(std::initializer_list<int>)'
    }



struct A8 {
    int i;
    int j;

    A8 (int)
        {}

    A8 (initializer_list<int>)
        {}

    bool operator == (const A8&) {
    	return true;}};

void test8 () {
    A8 x(2);     // A8(int)
    assert(&x);

    A8 y = 2;    // A8(int)
    assert(&y);

    A8 z{2};     // A8(initializer_list<int>)
    assert(&z);

    A8 t = {2};  // A8(initializer_list<int>)
    assert(&t);}



void test9 () {
    vector<int> x(2);                               // vector<int>(int)
    assert(x.size() == 2);
    assert(equal(begin(x), end(x), begin({0, 0})));

//  vector<int> y = 2;                              // error: conversion from 'int' to non-scalar type 'std::vector<int>' requested

    vector<int> z{2};                               // vector<int>(initializer_list<int>)
    assert(z.size() == 1);
    assert(equal(begin(z), end(z), begin({2})));

    vector<int> t = {2};                            // vector<int>(initializer_list<int>)
    assert(t.size() == 1);
    assert(equal(begin(t), end(t), begin({2})));}



int main () {
    cout << "Initializations.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    cout << "Done." << endl;
    return 0;}
