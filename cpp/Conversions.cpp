// ---------------
// Conversions.c++
// ---------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
class A {
    private:
        T _u;
        T _v;

    public:
        A (const T& u) :
                _u (u),
                _v ()
            {}

        A (const T& u, const T& v) :
                _u (u),
                _v (v)
            {}};

void test1 () {
//  A<int> x;          // error: no matching function for call to 'A<int>::A()'
    A<int> x = 2;      // A<int> x(2);
    A<int> y = {2, 3}; // A<int> y({2, 3}); A<int> y(2, 3);
    A<int> z = y;      // A<int> z(y);
    x = 4;
    y = {5, 6};
    assert(&z);}

void f1 (const A<int>&) {}

void test2 () {
    A<int> x = 2;
    f1(x);
    f1(A<int>(2));
    f1(2);

    A<int> y = {2, 3};
    f1(y);
    f1(A<int>(2, 3));
    f1({2, 3});}

void f2 (int) {}

void test3 () {
    f2(2);
    A<int> x = 2;
//  f2(x);        // error: cannot convert 'A<int>' to 'int'
    assert(&x);}

template <typename T>
class B {
    private:
        T _u;
        T _v;

    public:
        explicit B (const T& u) :
                _u (u),
                _v ()
            {}

        explicit B (const T& u, const T& v) :
                _u (u),
                _v (v)
            {}

        explicit B (const B& rhs) :
                _u (rhs._u),
                _v (rhs._v)
            {}

        operator T () {
            return _v;}};

void test4 () {
//  B<int> x = 2;      // error: conversion from 'int' to non-scalar type 'B<int>' requested
    B<int> x(2);

//  B<int> y = {2, 3}; // error: converting to 'B<int>' from initializer list would use explicit constructor 'B<T>::B(const T&, const T&) [with T = int]'
//  B<int> y({2, 3});  // error: converting to 'const B<int>' from initializer list would use explicit constructor 'B<T>::B(const T&, const T&) [with T = int]'
    B<int> y(2, 3);

//  B<int> z = y;      // error: no matching function for call to 'B<int>::B(B<int>&)'
    B<int> z(y);

//  x = 4;             // error: no match for 'operator=' (operand types are 'B<int>' and 'int')
//  y = {5, 6};        // error: converting to 'const B<int>' from initializer list would use explicit constructor 'B<T>::B(const T&, const T&) [with T = int]'

    assert(&z);}

void g1 (const B<int>&) {}

void test5 () {
    B<int> x(2);
    g1(x);
    g1(B<int>(2));
//  g1(2);            // error: invalid initialization of reference of type 'const B<int>&' from expression of type 'int'

    B<int> y(2, 3);
    g1(y);
    g1(B<int>(2, 3));
//  g1({2, 3});       // error: converting to 'B<int>' from initializer list would use explicit constructor 'B<T>::B(const T&, const T&) [with T = int]'
    }

void g2 (int) {}

void test6 () {
    g2(2);
    B<int> x(2);
    g2(x);       // g2(x.operator T())
    assert(&x);}

int main () {
    using namespace std;
    cout << "Conversions..c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    cout << "Done." << endl;
    return 0;}
