// -------------------
// InstanceMethods.c++
// -------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
    T        iv = 0;
    static T cv;

    void im () {
        ++iv;
        ++cv;

        assert(&iv == &this->iv);
        assert(&cv == &this->cv);

        cim();
        cm();}

    void cim () const
        {}

    static void cm ()
        {}};

template <typename T>
T A<T>::cv = 0;

void test () {
//  A<int>::im(); // error: cannot call member function 'void A<T>::im() [with T = int]' without object

    A<int> x;
    assert(x.iv == 0);
    assert(x.cv == 0);

    x.im();
    assert(x.iv == 1);
    assert(x.cv == 1);

    const A<int> y;
//  y.im();         //  error: passing 'const A<int>' as 'this' argument discards qualifiers
    }

int main () {
    using namespace std;
    cout << "InstanceMethods.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
