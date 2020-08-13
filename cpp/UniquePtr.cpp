// -------------
// UniquePtr.c++
// -------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr

#include <cassert>   // assert
#include <iostream>  // cout, endl

using namespace std;

template <typename T>
class my_unique_ptr {
    private:
        T* _p = nullptr;

    public:
        my_unique_ptr () = default;

        explicit my_unique_ptr (T* p) {
            _p = p;}

        my_unique_ptr             (const my_unique_ptr&) = delete;
        my_unique_ptr& operator = (const my_unique_ptr&) = delete;

        ~my_unique_ptr () {
            delete _p;}

        T* get () const {
            return _p;}};

void test1 () {
    my_unique_ptr<A> x;          // default constructor
    assert(x.get() == nullptr);}

void test2 () {
//  my_unique_ptr<A> x = new A; // error: conversion from 'A*' to non-scalar type 'my_unique_ptr<A>' requested
    my_unique_ptr<A> x(new A);  // pointer constructor
    assert(x.get() != nullptr);

int main () {
    cout << "UniquePtr.c++" << endl;
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
