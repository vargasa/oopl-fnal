// -------------
// Functions.c++
// -------------

#include <cstdio>

#include <algorithm> // transform
#include <cassert>   // assert
#include <cmath>     // pow
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

int pow1 (int n) {
    return pow(n, 2);}

void test1 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    vector<int>::iterator     p = transform(b, e, x, pow1);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





template <typename T>
T pow2 (T n) {
    return pow(n, 2);}

void test2 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    vector<int>::iterator     p = transform(b, e, x, pow2<int>);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





void test3 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    auto                      f = [] (int n) -> int {return pow(n, 2);};
    vector<int>::iterator     p = transform(b, e, x, f);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





auto pow4 (int& p) {
    return [p] (int n) -> int {return pow(n, p);};}

void test4 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       p = 2;
    auto                      f = pow4(p);
    ++p;
    vector<int>::iterator     q = transform(b, e, x, f);
    assert(q == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





auto pow5 (int& p) {
    return [&p] (int n) -> int {return pow(n, p);};}

void test5 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       p = 1;
    auto                      f = pow5(p);
    ++p;
    vector<int>::iterator     q = transform(b, e, x, f);
    assert(q == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





class pow6 {
    private:
        int _p;

    public:
        pow6 (int& p) :
                _p (p)
            {}

        int operator () (int n) const {
            return pow(n, _p);};};

void test6 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       p = 2;
    auto                      f = pow6(p);
    ++p;
    vector<int>::iterator     q = transform(b, e, x, f);
    assert(q == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





class pow7 {
    private:
        int& _p;

    public:
        pow7 (int& p) :
                _p (p)
            {}

        int operator () (int n) const {
            return pow(n, _p);};};

void test7 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       p = 1;
    auto                      f = pow7(p);
    ++p;
    vector<int>::iterator     q = transform(b, e, x, f);
    assert(q == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}

int main () {
    cout << "Functions.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    cout << "Done." << endl;
    return 0;}
