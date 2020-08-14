// --------
// Move.c++
// --------

// https://en.cppreference.com/w/cpp/utility/move

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // move

using namespace std;

struct A {
    A () = default;

    A (const A&) {               // copy constructor
        cout << "A(const A&) ";}

    A& operator = (const A&) {   // copy assignment
        cout << "=(const A&) ";
        return *this;}};



A f () {
    A x;
    return x;}



void test1 () {
    cout << "1. A copy constructor: ";
    A x;
    A y = x;                           // l-value, A(const A&)
    assert(&y);}

void test2 () {
    cout << "2. A copy elision ";
    A y = f();                         // r-value
    assert(&y);}

void test3 () {
    cout << "3. A copy assignment: ";
    A x;
    A y;
    y = x;}                            // l-value, =(const A&)

void test4 () {
    cout << "4. A copy assignment: ";
    A y;
    y = f();}                          // r-value, =(const A&)



struct B {
    B () = default;

    B (const B&) {               // copy constructor
        cout << "B(const B&) ";}

    B (B&&) {                    // move constructor
        cout << "B(B&&) ";}

    B& operator = (const B&) {   // copy assignment
        cout << "=(const B&) ";
        return *this;}

    B& operator = (B&&) {        // move assignment
        cout << "=(B&&) ";
        return *this;}};



B g () {
    B x;
    return x;}



void test5 () {
    cout << "5. B move constructor: ";
    B x;
    B y = move(x);                     // r-value, B(&&)
    assert(&y);}

void test6 () {
    cout << "6. B move elision ";
    B y = g();                         // r-value
    assert(&y);}

void test7 () {
    cout << "7. B move assignment: ";
    B x;
    B y;
    y = move(x);}                      // r-value, =(&&)

void test8 () {
    cout << "8. B move assignment: ";
    B y;
    y = g();}                          // r-value, =(B&&)



int main () {
    cout << "Move.c++" << endl;
    test1();
    cout << endl;

    test2();
    cout << endl << endl;

    test3();
    cout << endl;

    test4();
    cout << endl << endl;

    test5();
    cout << endl;

    test6();
    cout << endl << endl;

    test7();
    cout << endl;

    test8();
    cout << endl;
    cout << "Done." << endl;
    return 0;}

/*
Move.c++
1. A copy constructor: A(const A&)
2. A copy elision

3. A copy assignment: =(const A&)
4. A copy assignment: =(const A&)

5. B move constructor: B(B&&)
6. B move elision

7. B move assignment: =(B&&)
8. B move assignment: =(B&&)
Done.
*/
