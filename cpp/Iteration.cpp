// -------------
// Iteration.c++
// -------------

// http://en.cppreference.com/w/cpp/language/for
// http://en.cppreference.com/w/cpp/language/range-for

#include <algorithm> // equal
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <iterator>  // begin, end
#include <list>      // list
#include <map>       // map
#include <set>       // set
#include <sstream>   // ostringstream
#include <utility>   // pair
#include <vector>    // vector

using namespace std;

void test1 () {
    int i = 0;
    int s = 0;
    while (i != 10) {
        s += i;
        ++i;}
    assert(i == 10);
    assert(s == 45);}

void test2 () {
    int i = 0;
    int s = 0;
    do {
        s += i;
        ++i;}
    while (i != 10);
    assert(i == 10);
    assert(s == 45);}

void test3 () {
    int s = 0;
    for (int i = 0; i != 10; ++i)
        s += i;
//  assert(i == 10);              // error: name lookup of 'i' changed for new ISO 'for' scoping
    assert(s == 45);}

void test4 () {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    int s = 0;
    for (int i = 0, j = 0; i != 3; ++i, ++j)
        s += a[i] + b[j];
    assert(s == 27);}

void test5 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int v : a)
        s += v;
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test6 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int v : a) {
        s += v;
        ++v;}                                   // ?
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test7 () {
    int  a[] = {2, 3, 4};
    int  s   = 0;
    int* b   = begin(a);
    int* e   = end(a);
    while (b != e) {
        int v = *b;
        s += v;
        ++v;                                    // ?
        ++b;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test8 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (auto v : a) {
        s += v;
        ++v;}                                   // ?
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test9 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int& r : a) {
        s += r;
        ++r;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({3, 4, 5})));}

void test10 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (auto& r : a) {
        s += r;
        ++r;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({3, 4, 5})));}

void test11 () {
    list<int> x = {2, 3, 4};
    int       s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test12 () {
    list<int>           x = {2, 3, 4};
    int                 s = 0;
    list<int>::iterator b = begin(x);           // x.begin()
    list<int>::iterator e = end(x);             // x.end()
    while (b != e) {
        list<int>::iterator::value_type v = *b;
        s += v;
        ++b;}
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test13 () {
    set<int> x = {2, 3, 4};
    int      s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test14 () {
    set<int>           x = {2, 3, 4};
    int                s = 0;
    set<int>::iterator b = begin(x);           // x.begin()
    set<int>::iterator e = end(x);             // x.end()
    while (b != e) {
        set<int>::iterator::value_type v = *b;
        s += v;
        ++b;}
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test15 () {
    set<int> x = {2, 3, 4};
    int      s = 0;
//  for (      int& r : x)                              // error: binding reference of type 'int&' to 'const int' discards qualifiers
    for (const int& r : x)
        s += r;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test16 () {
    map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int            s = 0;
    for (pair<char, int> v : x)
        s += v.second;
    assert(s == 9);}

void test17 () {
    map<char, int>           x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int                      s = 0;
    map<char, int>::iterator b = begin(x);                       // x.begin()
    map<char, int>::iterator e = end(x);                         // x.end()
    while (b != e) {
        map<char, int>::iterator::value_type v = *b;
        s += v.second;
        ++b;}
    assert(s == 9);}

void test18 () {
    map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int            s = 0;
//  for (pair<      char, int>& p : x)                 // error: non-const lvalue reference to type 'pair<char, [...]>' cannot bind to a value of unrelated type 'const pair<__key_type, [...]>'
    for (pair<const char, int>& p : x)
        s += p.second;
    assert(s == 9);}

void test19 () {
    ostringstream     out;
    const vector<int> x = {2, 3, 4};
    for (size_t i = 0; i != x.size(); ++i)
        out << x[i] << " \n"[i == (x.size() - 1)];
    assert(out.str() == "2 3 4\n");}

int main () {
    cout << "Iteration.c++" << endl;
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
    test15();
    test16();
    test17();
    test18();
    test19();
    cout << "Done." << endl;
    return 0;}
