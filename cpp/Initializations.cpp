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

struct A {
    A (int, int)
        {}};

void test3 () {
    A x(2, 3);
    assert(&x);

    A z{2, 3};
    assert(&z);

    A t = {2, 3};
    assert(&t);}

struct B {
    explicit B (int, int)
        {}};

void test4 () {
    B x(2, 3);
    assert(&x);

    B z{2, 3};
    assert(&z);

//  B t = {2, 3}; // error: converting to 'B' from initializer list would use explicit constructor 'B::B(int, int)'
    }

struct C {
    C (initializer_list<int>)
        {}};

void test5 () {
//  C x(2);      // error: no matching function for call to 'C::C(int)'

//  C y = 2;     // error: no matching function for call to 'C::C(int)'

    C z{2};
    assert(&z);

    C t = {2};
    assert(&t);}

void test6 () {
//  C x(2, 3);    // error: no matching function for call to 'C::C(int)'

    C z{2, 3};
    assert(&z);

    C t = {2, 3};
    assert(&t);}

struct D {
    explicit D (initializer_list<int>)
        {}};

void test7 () {
//  D x(2);     // error: no matching function for call to 'D::D(int)'

//  D y = 2;    // error: no matching function for call to 'D::D(int)'

    D z{2};
    assert(&z);

//  D t = {2};  // error: converting to 'D' from initializer list would use explicit constructor 'D::D(std::initializer_list<int>)'
    }

void test8 () {
//  D x(2, 3);   // error: no matching function for call to 'D::D(int)'

    D z{2, 3};
    assert(&z);

//  D t = {2, 3}; // error: converting to 'D' from initializer list would use explicit constructor 'D::D(std::initializer_list<int>)'
    }

struct E {
    E (int)
        {}

    E (initializer_list<int>)
        {}

    bool operator == (const E&) {
    	return true;}};

void test9 () {
    E x(2);
    assert(&x);

    E y = 2;
    assert(&y);

    E z{2};
    assert(&z);

    E t = {2};
    assert(&t);}

void test10 () {
    vector<int> x(2);
    assert(x.size() == 2);
    assert(equal(begin(x), end(x), begin({0, 0})));

//  vector<int> y = 2;                              // error: conversion from 'int' to non-scalar type 'std::vector<int>' requested

    vector<int> z{2};
    assert(z.size() == 1);
    assert(equal(begin(z), end(z), begin({2})));

    vector<int> t = {2};
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
    test10();
    cout << "Done." << endl;
    return 0;}
