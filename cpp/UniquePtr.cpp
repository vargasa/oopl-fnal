// -------------
// UniquePtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <algorithm> // swap
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <utility>    // move

using namespace std;

template <typename T>
class my_unique_ptr {
    private:
        T* _p = nullptr;

    public:
        my_unique_ptr () = default;

        explicit my_unique_ptr (T* p) {
            _p = p;}

        my_unique_ptr (const my_unique_ptr&) = delete;

        my_unique_ptr (my_unique_ptr&& rhs) {
            swap(_p, rhs._p);}

        my_unique_ptr& operator = (const my_unique_ptr&) = delete;

        my_unique_ptr& operator = (my_unique_ptr&& rhs) {
            if (this == &rhs)
                return *this;
            my_unique_ptr that(move(rhs));
            swap(_p, that._p);
            return *this;}

        ~my_unique_ptr () {
            delete _p;}

        T* get () const {
            return _p;}};

struct A {
    static int c; // number of current A instances

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

void test0 () {
    assert(A::c == 0);
    my_unique_ptr<A> x;         // default constructor
    assert(A::c    == 0);
    assert(x.get() == nullptr);}

void test1 () {
    assert(A::c == 0);
    {
//  my_unique_ptr<A> x = new A; // error: conversion from 'A*' to non-scalar type 'my_unique_ptr<A>' requested
    my_unique_ptr<A> x(new A);  // pointer constructor
    assert(A::c    == 1);
    assert(x.get() != nullptr);
    }
    assert(A::c == 0);}

void test2 () {
    assert(A::c == 0);
    {
    my_unique_ptr<A> x(new A);
    assert(A::c    == 1);
//  my_unique_ptr<A> y = x;       // error: use of deleted function 'my_unique_ptr<T>::my_unique_ptr(const my_unique_ptr<T>&) [with T = A]'
    my_unique_ptr<A> y = move(x); // move constructor
    assert(A::c    == 1);
    assert(x.get() == nullptr);
    assert(y.get() != nullptr);
    }
    assert(A::c == 0);}

void test3 () {
    assert(A::c == 0);
    {
    my_unique_ptr<A> x(new A);
    my_unique_ptr<A> y(new A);
    assert(A::c == 2);
//  y = x;                      // error: use of deleted function 'my_unique_ptr<T>& my_unique_ptr<T>::operator=(const my_unique_ptr<T>&) [with T = A]'
    y = move(x);                // move assignment operator
    assert(x.get() == nullptr);
    assert(y.get() != nullptr);
    assert(A::c    == 1);
    }
    assert(A::c == 0);}

int main () {
    cout << "UniquePtr.c++" << endl;
    test0();
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
