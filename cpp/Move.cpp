// --------
// Move.c++
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // move

using namespace std;

template <typename T>
struct A {
    A () {
        cout << "A() ";}

    A (const A&) {               // copy constructor
        cout << "A(const A&) ";}

    A (A&&) {                    // move constructor
        cout << "A(A&&) ";}

    A& operator = (const A&) {   // copy assignment
        cout << "=(const A&) ";
        return *this;}

    A& operator = (A&&) {        // move assignment
        cout << "=(A&&) ";
        return *this;}

    ~A() {
        cout << "~A() ";}};



template <typename T>
struct B {
    A<T> _x;                       // containment

    B () :
            _x () {
        cout << "B() ";}

    B (const B& rhs) :
            _x (rhs._x) {
        cout << "B(const B&) ";}

    B& operator = (const B& rhs) {
        _x = rhs._x;
        cout << "=(const B&) ";
        return *this;}

    ~B() {
        cout << "~B() ";}};

void test1 () {
    cout << "B. copy cntr: ";
    B<int> x;                 // A() B()
    B<int> y = x;             // A(const A&) B(const B&);
    }

void test2 () {
    cout << "B. move cntr: ";
    B<int> x;                 // A() B()
    B<int> y = move(x);       // A(const A&) B(const B&);
    }

void test3 () {
    cout << "B. copy asgn: ";
    B<int> x;                 // A() B()
    B<int> y;                 // A() B()
    y = x;                    // =(const A&) =(const B&)
    }

void test4 () {
    cout << "B. move asgn: ";
    B<int> x;                 // A() B()
    B<int> y;                 // A() B()
    y = move(x);              // =(const A&) =(const B&)
    }



template <typename T>
struct C {
    A<T> _x;                       // containment

    C () :
            _x () {
        cout << "C() ";}

    C (const C& rhs) :
            _x (rhs._x) {
        cout << "C(const C&) ";}

    C (C&& rhs) :
            _x (move(rhs._x)) {
        cout << "C(C&&) ";}

    C& operator = (const C& rhs) {
        _x = rhs._x;
        cout << "=(const C&) ";
        return *this;}

    C& operator = (C&& rhs) {
        _x = move(rhs._x);
        cout << "=(C&&) ";
        return *this;}

    ~C() {
        cout << "~C() ";}};

void test5 () {
    cout << "C. copy cntr: ";
    C<int> x;                 // A() C()
    C<int> y = x;             // A(const A&) C(const C&)
    }

void test6 () {
    cout << "C. move cntr: ";
    C<int> x;                 // A() C()
    C<int> y = move(x);       // A(A&&) C(C&&)
    }

void test7 () {
    cout << "C. copy asgn: ";
    C<int> x;                 // A() C()
    C<int> y;                 // A() C()
    y = x;                    // =(const A&) =(const C&)
    }

void test8 () {
    cout << "C. move asgn: ";
    C<int> x;                 // A() C()
    C<int> y;                 // A() C()
    y = move(x);              // =(A&&) =(C&&)
    }

int main () {
    cout << "Move.c++" << endl;
    test1(); cout << endl;
    test2(); cout << endl;
    test3(); cout << endl;
    test4(); cout << endl << endl;
    test5(); cout << endl;
    test6(); cout << endl;
    test7(); cout << endl;
    test8(); cout << endl;
    cout << "Done." << endl;
    return 0;}

/*
B. copy cntr: A() B() A(const A&) B(const B&) ~B() ~A() ~B() ~A()
B. move cntr: A() B() A(const A&) B(const B&) ~B() ~A() ~B() ~A()
B. copy asgn: A() B() A() B() =(const A&) =(const B&) ~B() ~A() ~B() ~A()
B. move asgn: A() B() A() B() =(const A&) =(const B&) ~B() ~A() ~B() ~A()

C. copy cntr: A() C() A(const A&) C(const C&) ~C() ~A() ~C() ~A()
C. move cntr: A() C() A(A&&) C(C&&) ~C() ~A() ~C() ~A()
C. copy asgn: A() C() A() C() =(const A&) =(const C&) ~C() ~A() ~C() ~A()
C. move asgn: A() C() A() C() =(A&&) =(C&&) ~C() ~A() ~C() ~A()
*/
