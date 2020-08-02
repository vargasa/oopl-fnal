// ----------------
// ClassMethods.c++
// ----------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
    T        iv = 0;
    static T cv;

    void im ()
        {}

    void cim () const
        {}

    static void cm () {
//      ++iv;                     // error: invalid use of member 'A<T>::iv' in static member function
        ++cv;

//      assert(&cv == &this->cv); // error: 'this' is unavailable for static member functions
//      im();                     // error: cannot call member function 'void A<T>::im() [with T = int]' without object
//      cim();                    //  error: cannot call member function 'void A<T>::cim() const [with T = int]' without object
        }};

template <typename T>
T A<T>::cv = 0;

void test () {
    assert(A<int>::cv == 0);

    A<int>::cm();
    assert(A<int>::cv == 1);

    A<int> x;
    x.cm();
    assert(A<int>::cv == 2);

    const A<int> y;
    y.cm();
    assert(A<int>::cv == 3);}

int main () {
    using namespace std;
    cout << "ClassMethods.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
