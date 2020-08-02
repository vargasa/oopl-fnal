// -----------
// Arrays1.c++
// -----------

// https://en.cppreference.com/w/cpp/container/array

#include <cstdio>

#include <algorithm> // copy, equal
#include <array>     // array
#include <cassert>   // assert
#include <iostream>  // cout, endl

using namespace std;

void test1 () {
    int a[] = {2, 3, 4};
    assert(*a == a[0]);
    assert(a  == &a[0]);
    assert(sizeof(a)     != sizeof(&a[0]));
    assert(sizeof(a)     == 12);
    assert(sizeof(&a[0]) == 8);
//  ++a;                                    // error: lvalue required as left operand of assignment
    ++a[1];
    ++*(a + 1);
    assert(a[1]     == 5);
    assert(*(a + 1) == 5);
//  assert(a[3]     == 0);                  // undefined
//  assert(*(a + 3) == 0);                  // undefined
    }

void test2 () {
    const size_t s    = 10;
    const int    a[s] = {2, 3, 4};
    assert(sizeof(a) == 40);
    assert(a[1]      ==  3);
    assert(*(a + 1)  ==  3);
    assert(a[s - 1]  ==  0);
//  ++a;                           // error: lvalue required as left operand of assignment
//  ++a[1];                        // error: increment of read-only location
    }

void test3 () {
    const size_t s = 10;
//  const int    a[s];       // error: uninitialized const 'a'
    int a[s];
    assert(sizeof(a) == 40);
//  assert(a[0]      ==  0); // undefined
    }

void test4 () {
    const size_t s    = 10;
    const int    a[s] = {};
    assert(sizeof(a) == 40);
    assert(a[0]      ==  0);}

void test5 () {
    int a[] = {2, 3, 4};
    int b[] = {2, 3, 4};
    assert(a != b);
    assert(equal(a, a + 3, b));
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

void test6 () {
    int a[] = {2, 3, 4};
//  int b[] = a;                    // error: initializer fails to determine size of 'b'
    int* b  = a;
    assert(a         == b);
    assert(sizeof(a) != sizeof(b));
    assert(sizeof(a) == 12);
    assert(sizeof(b) ==  8);
    ++b[1];
    assert(equal(a, a + 3, begin({2, 4, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

void test7 () {
    int          a[] = {2, 3, 4};
    const size_t s   = sizeof(a) / sizeof(a[0]);
    int b[s];
    copy(a, a + s, b);
    assert(a != b);
    assert(equal(a, a + s, b));
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

void test8 () {
    int a[] = {2, 3, 4};
    int b[] = {5, 6, 7};
//  b = a;                                     // error: invalid array assignment
    const size_t s = sizeof(a) / sizeof(a[0]);
    copy(a, a + s, b);
    assert(a != b);
    assert(equal(a, a + s, b));
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

void f (int p[]) {
    assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

void test9 () {
    int a[] = {2, 3, 4};
    f(a);
    assert(equal(a, a + 3, begin({2, 5, 4})));}

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

void test10 () {
    int a[] = {2, 3, 4};
    g(a);
    assert(equal(a, a + 3, begin({2, 5, 4})));}

void test11 () {
    array<int, 3> x = {2, 3, 4};
    assert(x.size() == 3);
    assert(x[1]     == 3);
    array<int, 3> y(x);
    assert( x    ==  y);
    assert(&x[1] != &y[1]);}

void test12 () {
    array<int, 3> x = {2, 3, 4};
    array<int, 3> y = {5, 6, 7};
    x = y;
    assert( x    ==  y);
    assert(&x[1] != &y[1]);}

void h1 (array<int, 3>& y) {
    array<int, 3>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test13 () {
    array<int, 3> x = {2, 3, 4};
    h1(x);
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}

void h2 (array<int, 3> y) {
    array<int, 3>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test14 () {
    array<int, 3> x = {2, 3, 4};
    h2(x);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

int main () {
    cout << "Arrays1.c++" << endl;
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
    test12();
    test13();
    test14();
    cout << "Done." << endl;
    return 0;}
