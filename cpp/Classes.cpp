// -----------
// Classes.c++
// -----------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
class A {
    private:
        T _u;
        T _v;

    public:
        A () = default;
/*
        A () :
                _u (),
                _v ()
            {}
*/

        A (const T& u) :
                _u (u),
                _v ()
            {}

        A (const T& u, const T& v) :
                _u (u),
                _v (v)
            {}

        A (const A&) = default;
/*
        A (const A& rhs) :
            _u (rhs._u),
            _v (rhs._v)
            {}
*/

        A& operator = (const A&) = default;
/*
        A& operator = (const A& rhs) {
            _u = rhs._u;
            _v = rhs._v;
            return *this;}
*/

        ~A () = default;
/*
        ~A ()
            {}
*/
        };

void test1 () {
    A<int> x;
    A<int> y;
    assert(&x != &y);}

void test2 () {
    A<int> x = 2;
    A<int> y = 3;
    assert(&x != &y);}

void test3 () {
    A<int> x = {2, 3};
    A<int> y = {4, 5};
    assert(&x != &y);}

void test4 () {
    A<int> x = {2, 3};
    A<int> y = x;}

void test5 () {
    A<int> x = {2, 3};
    A<int> y = {4, 5};
    x = y;}

int main () {
    cout << "Classes.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    cout << "Done." << endl;
    return 0;}
