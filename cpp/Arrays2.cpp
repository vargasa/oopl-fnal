// -----------
// Arrays2.c++
// -----------

#include <cstdio>

#include <algorithm> // copy, count, equal, fill
#include <cassert>   // assert
#include <cstddef>   // ptrdiff_t, size_t
#include <iostream>  // cout, endl
#include <memory>    // unique_ptr
#include <string>    // string
#include <vector>    // vector

using namespace std;

void f (int p[]) {
    assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

void test1 () {
    const ptrdiff_t s = 10;
    const int       v =  2;
    int*  const     a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    assert(count(a, a + s, v) == s);
    assert(a[1] == v);
    f(a);
    assert(a[1] == v + 2);
    delete [] a;}

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

void test2 () {
    const ptrdiff_t s = 10;
    const int       v = 2;
    int* const      a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    assert(count(a, a + s, v) == s);
    assert(a[1] == v);
    g(a);
    assert(a[1] == v + 2);
    delete [] a;}

void test3 () {
    const size_t  s = 10;
    const int     v = 2;
    int*  const   a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* const b = a;
    assert(&a[1] == &b[1]);
    delete [] a;}

void test4 () {
    const size_t  s = 10;
    const int     v = 2;
    int*  const   a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* const x = new int[s];
    copy(a, a + s, x);
    assert( a[1] ==  x[1]);
    assert(&a[1] != &x[1]);
    delete [] a;
    delete [] x;}

void test5 () {
    const size_t s = 10;
    const int    v =  2;
    int*  const  a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* b = new int[s];
    fill(b, b + s, v);
//  b = a;                           // memory leak
    copy(a, a + s, b);
    assert( a[1] ==  b[1]);
    assert(&a[1] != &b[1]);
    delete [] a;
    delete [] b;}

struct A {
    int i;

    string f () {
        return "A::f";}};

struct B : A {
    int j;

    string f () {
        return "B::f";}};

void test6 () {
//  B* const a = new A[10];     // error: invalid conversion from ‘A*’ to ‘B*’
    A* const a = new B[10];     // dangerous
    assert(a[0].f() == "A::f");
//  assert(a[1].f() == "A::f"); // undefined
//  delete [] a;                // undefined
    B* b = static_cast<B*>(a);  // clang-check warning: Potential leak of memory pointed to by 'a'
    assert(b[1].f() == "B::f");
    delete [] b;}               // ~B::B() and ~A::A()

void test7 () {
    const ptrdiff_t   s = 10;
    const int         v =  2;
    unique_ptr<int[]> a(new int[s]);
    fill(a.get(), a.get() + s, v);
    assert(count(a.get(), a.get() + s, v) == s);
    assert(a.get()[1] == v);
    f(a.get());
    assert(a.get()[1] == v + 2);}

void test8 () {
    const size_t s = 10;
    const int    v =  2;
    vector<int>  x(s, v);
    assert(x.size() == s);
    assert(x[0]     == v);
    vector<int> y(x);
    assert( x    ==  y);
    assert(&x[1] != &y[1]);
    vector<int> z(2 * s, v);
    x = z;
    assert( x    ==  z);
    assert(&x[1] != &z[1]);}

void h1 (vector<int>& y) {
    vector<int>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test9 () {
    vector<int> x = {2, 3, 4};
    h1(x);
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}

void h2 (vector<int> y) {
    vector<int>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test10 () {
    vector<int> x = {2, 3, 4};
    h2(x);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

int main () {
    cout << "Arrays2.c++" << endl;
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
