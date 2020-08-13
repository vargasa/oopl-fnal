// ---------
// Array.c++
// ---------

// https://en.cppreference.com/w/cpp/container/array

#include <algorithm> // equal
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <utility>   // !=

using namespace std;

using rel_ops::operator!=;

template <typename T, size_t N>
struct my_array {
    friend bool operator == (const my_array& lhs, const my_array& rhs) {
        return equal(lhs.begin(), lhs.end(), rhs.begin());}

    T _a[N];

    my_array             ()                = default;
    my_array             (const my_array&) = default;
    my_array& operator = (const my_array&) = default;
    ~my_array            ()                = default;

    T& operator [] (size_t i) {
        return _a[i];}

    const T& operator [] (size_t i) const {
        return _a[i];}

    T* begin () {
        return _a;}

    const T* begin () const {
        return _a;}

    T* end () {
        return _a + N;}

    const T* end () const {
        return _a + N;}

    size_t size () const {
        return N;}};

void test1 () {
    my_array<int, 3> x;
    assert(x.size() == 3);}

void test2 () {
    my_array<int, 3> x = {};
    assert(x.size() == 3);}

void test3 () {
    my_array<int, 3> x = {2};
    assert(x.size() == 3);}

void test4 () {
//  my_array<int, 3> x = {2, 3, 4, 5}; // error: too many initializers for 'my_array<int, 3>'
    my_array<int, 3> x = {2, 3, 4};
    assert(x[1] == 3);
    x[1] = 5;
    assert(x[1] == 5);}

void test5 () {
    const my_array<int, 3> x = {2, 3, 4};
    assert(x[1] == 3);
//  x[1] = 5;                             // error: assignment of read-only location 'x.my_array<int, 3>::operator[](1)'
    assert(x[1] == 3);}

void test6 () {
    const my_array<int, 3> x = {2, 3, 4};
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test7 () {
    my_array<int, 3>       x = {2, 3, 4};
    const my_array<int, 3> y = x;
    assert(&*begin(x) != &*begin(y));
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}

void test8 () {
    const my_array<int, 3> x = {2, 3, 4};
    my_array<int, 3>       y = {5, 6, 7};
    y = x;
    assert(&*begin(x) != &*begin(y));
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}

void test9 () {
    const my_array<int, 5> x = {2, 3, 4, 5, 6};
    const my_array<int, 5> y = {2, 3, 4, 5, 6};
    assert(  x == y);
    assert(!(x != y));}

void test10 () {
    const my_array<int, 5> x = {2, 3, 4, 5, 6};
    const my_array<int, 5> y = {2, 3, 4, 5, 7};
    assert(  x != y);
    assert(!(x == y));}

int main () {
    cout << "Array.c++" << endl;
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
