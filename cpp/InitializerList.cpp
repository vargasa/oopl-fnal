// -------------------
// InitializerList.c++
// -------------------

// http://en.cppreference.com/w/cpp/utility/initializer_list

#include <cstdio>

#include <algorithm>        // equal
#include <cassert>          // assert
#include <initializer_list> // initializer_list
#include <iostream>         // cout, endl
#include <vector>           // vector

using namespace std;

void test1 () {
    initializer_list<int> x;
    assert(x.size() == 0);

    initializer_list<int> y();

    initializer_list<int> z{};
    assert(z.size() == 0);

    initializer_list<int> t = {};
    assert(t.size() == 0);}

void test2 () {
//  initializer_list<int> x(2);  // error: no matching function for call to 'std::initializer_list<int>::initializer_list(int)'

//  initializer_list<int> y = 2; // error: conversion from 'int' to non-scalar type 'std::initializer_list<int>' requested

    initializer_list<int> z{2};
    assert(z.size() == 1);

    initializer_list<int> t = {2};
    assert(t.size() == 1);}

void test3 () {
    initializer_list<int> z{2, 3};
    assert(z.size() == 2);

    initializer_list<int> t = {2, 3};
    assert(t.size() == 2);}

void test4 () {
    initializer_list<int> x = {2, 3, 4};
    initializer_list<int> y = x;
    assert(equal(begin(x), end(x), begin(y)));}

void test5 () {
    initializer_list<int> x = {2, 3, 4};
    initializer_list<int> y = {5, 6};
    x = y;                                      // well-defined
    assert(equal(begin(x), end(x), begin(y)));}

void test6 () {
    initializer_list<int> x = {2, 3, 4};
//  x = {5, 6};                          // warning: assignment from temporary initializer_list does not extend the lifetime of the underlying array [-Winit-list-lifetime]
    assert(&x);}

void test7 () {
    initializer_list<int> x = {2, 3, 4};
    initializer_list<int> y = {2, 3, 4};
//  assert(x == y);                             //  error: no match for 'operator==' (operand types are 'std::initializer_list<int>' and 'std::initializer_list<int>')
    assert(equal(begin(x), end(x), begin(y)));}

void test8 () {
    initializer_list<int> x = {2, 3, 4};
    vector<int>           y = x;
    assert(equal(begin(x), end(x), begin(y)));}

void test9 () {
    vector<int>           x = {2, 3, 4};
    initializer_list<int> y = {5, 6};
    x = y;
//  y = x;                                       // error: no match for 'operator=' (operand types are 'std::initializer_list<int>' and 'std::vector<int>')
    assert(equal(begin(x), end(x), begin(y)));}

void test10 () {
    vector<int> x = {2, 3, 4};
    x = {5, 6};
    assert(equal(begin(x), end(x), begin({5, 6})));}

void test11 () {
    vector<int> x = {2, 3, 4};
//  assert(x == {2, 3, 4});          // error: macro "assert" passed 3 arguments, but takes just 1
    assert(x == vector({2, 3, 4}));}

int main () {
    cout << "InitializerList.c++" << endl;
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
    test11();
    cout << "Done." << endl;
    return 0;}
