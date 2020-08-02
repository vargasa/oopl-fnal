// ---------
// Types.c++
// ---------

// https://en.cppreference.com/w/cpp/language/types

#include <cassert>       // assert
#include <deque>         // deque
#include <iostream>      // cout, endl
#include <list>          // list
#include <map>           // map
#include <queue>         // priority_queue, queue
#include <set>           // set
#include <stack>         // stack
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <vector>        // vector

using namespace std;

void test1 () {
    bool b = true;
    assert(sizeof(b) ==  1);}

void test2 () {
    char c = 'a';
    assert(sizeof(c) ==  1);}

void test3 () {
    short s = 2;
    assert(sizeof(s) ==  2);}

void test4 () {
    int i = 2;
    assert(sizeof(i) ==  4);}

void test5 () {
    long l = 2l;
    assert(sizeof(l) ==  8);}

void test6 () {
    long long ll = 2ll;
    assert(sizeof(ll) == 8);}

void test7 () {
    float f = 2.34F;
    assert(sizeof(f) == 4);}

void test8 () {
    double d = 2.34;
    assert(sizeof(d) == 8);}

void test9 () {
    long double ld = 2.34l;
    assert(sizeof(ld) == 16);}

void test10 () {
    char a[] = "abc";
    assert(sizeof(a) == 4 * sizeof(char));}

void test11 () {
    int a[] = {2, 3, 4};
    assert(sizeof(a) == 3 * sizeof(int));}

void test12 () {
    vector<int> x;                                               // front loaded array
    assert(x.size() == 0);
    vector<int> y(10, 2);
    assert(y.size() == 10);
    vector<int> z = {2, 3, 4};
    assert(z.size() == 3);}

void test13 () {
    deque<int> x;                                                // middle loaded array of arrays
    assert(x.size() == 0);
    deque<int> y(10, 2);
    assert(y.size() == 10);
    deque<int> z = {2, 3, 4};
    assert(z.size() == 3);}

void test14 () {
    list<int> x;                                                 // doubly-linked list
    assert(x.size() == 0);
    list<int> y(10, 2);
    assert(y.size() == 10);
    list<int> z = {2, 3, 4};
    assert(z.size() == 3);}

void test15 () {
    stack<int> x;                                                // LIFO backed by a vector, list, or deque
    assert(x.size() == 0);}

void test16 () {
    queue<int> x;                                                // FIFO backed by a list or deque
    assert(x.size() == 0);}

void test17 () {
    priority_queue<int> x;                                       // binary heap backed by a vector or deque
    assert(x.size() == 0);}

void test18 () {
    set<int> x = {2, 3, 4};                                      // red-black binary search tree
    assert(x.size() == 3);}

void test19 () {
    unordered_set<int> x = {2, 3, 4};                            // hash table
    assert(x.size() == 3);}

void test20 () {
    map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};           // red-black binary search tree
    assert(x.size() == 3);}

void test21 () {
    unordered_map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}}; // hash table
    assert(x.size() == 3);}

template <typename T>
struct A {
    int    i;
    double d;
    T      x;};

void test22 () {
    A<int> x = {2, 3.45, 6};
    assert(sizeof(x) == 24);}

void test23 () {
    A<double> x = {2, 3.45, 6.78};
    assert(sizeof(x) == 24);}

void test24 () {
    A<A<int>> x = {2, 3.45, {2, 3.45, 6}};
    assert(sizeof(x) == 40);}

int main () {
    cout << "Types.c++" << endl;
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
    test20();
    test21();
    test22();
    test23();
    test24();
    cout << "Done." << endl;
    return 0;}
