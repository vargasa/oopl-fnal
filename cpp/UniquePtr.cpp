// -------------
// UniquePtr.c++
// -------------

// https://en.cppreference.com/w/cpp/memory/unique_ptr
// https://stackoverflow.com/questions/21355037/why-does-unique-ptr-take-two-template-parameters-when-shared-ptr-only-takes-one

#include <cassert>    // assert
#include <functional> // function
#include <iostream>   // cout, endl
#include <memory>     // default_delete, unique_ptr

using namespace std;

struct A {
    static int c; // number of current A instances

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

void test1 () {
    assert(A::c == 0);
    {
//  unique_ptr<A> x = new A; // error: conversion from 'A*' to non-scalar type 'std::unique_ptr<A>' requested
    unique_ptr<A> x(new A);
    assert(A::c    == 1);
    assert(x.get() != nullptr);
    }                            // destructor
    assert(A::c == 0);}

void test2 () {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A);
    assert(A::c    == 1);
//  unique_ptr<A> y = x;       // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]'
//  unique_ptr<A> y(x);        // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]'
    unique_ptr<A> y = move(x); // move constructor
    assert(A::c    == 1);
    assert(x.get() == nullptr);
    assert(y.get() != nullptr);
    }
    assert(A::c == 0);}

void test3 () {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A);
    unique_ptr<A> y(new A);
    assert(A::c == 2);
//  x = y;                      // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]'
    x = move(y);                // move assignment
    assert(A::c    == 1);
    assert(x.get() != nullptr);
    assert(y.get() == nullptr);
    }
    assert(A::c == 0);}

void test4 () {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A);
    assert(A::c == 1);
    A* p = x.release();
    assert(A::c == 1);
    assert(x.get() == nullptr);
    delete p;
    assert(A::c == 0);
    }
    assert(A::c == 0);}

void test5 () {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A);
    assert(A::c == 1);
    x.reset();
    assert(A::c == 0);
    assert(x.get() == nullptr);
    }
    assert(A::c == 0);}

void test6 () {
    assert(A::c == 0);
    {
    unique_ptr<A> x(new A);
    assert(A::c == 1);
    x.reset(new A());
    assert(A::c == 1);
    assert(x.get() != nullptr);
    }
    assert(A::c == 0);}

void test7 () {
    assert(A::c == 0);
    {
//  unique_ptr<A> x(new A[2]); // error: conflicting declaration 'std::unique_ptr<A []> x'
    unique_ptr<A[]> x(new A[2]);
    assert(A::c == 2);
    }
    assert(A::c == 0);}

int main () {
    cout << "UniquePtr.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    cout << "Done." << endl;
    return 0;}
