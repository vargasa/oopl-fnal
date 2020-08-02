#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // unique_ptr
#include <string>   // string
#include <vector>   // vector

using namespace std;

struct A {
    virtual string f () = 0;
    virtual ~A () {}};

struct B : A {
    string f () {
        return "B::f()";}};

struct C : A {
    string f () {
        return "C::f()";}};

void test1 () {
    vector<B> x(2, B());
    assert(x[0].f() == "B::f()");
    assert(&x[0] != &x[1]);}

void test2 () {
    vector<C> x(2, C());
    assert(x[0].f() == "C::f()");
    assert(&x[0] != &x[1]);}

void test3 () {
//  vector<A>  x(2, B());   // error: invalid new-expression of abstract class type 'A'
//  vector<A*> x(2, B());   // error: no matching function for call to 'std::vector<A*>::vector(int, B)'
    vector<A*> x(2, new B);
    assert(x[0] == x[1]);}  // ???

void test4 () {
    vector<A*> x;
    x.push_back(new B);
    x.push_back(new C);
    assert(x[0]->f() == "B::f()");
    assert(x[1]->f() == "C::f()");
    assert(x[0] != x[1]);
    delete x[0];
    delete x[1];}

void test5 () {
    vector<unique_ptr<A>> x;
    x.push_back(unique_ptr<A>(new B));
    x.push_back(unique_ptr<A>(new C));
    assert(x[0]->f() == "B::f()");
    assert(x[1]->f() == "C::f()");
    assert(x[0] != x[1]);}

int main () {
    cout << "UniquePtrs.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    cout << "Done." << endl;
    return 0;}
