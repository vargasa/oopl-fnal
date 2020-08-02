// ----------------
// ConstMethods.c++
// ----------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
    T        iv = 0;
    static T cv;

    void im ()
        {}

    void cim () const {
//      ++iv;           // error: increment of member 'A<int>::iv' in read-only object
        ++cv;

//      im();           // error: passing 'const A<int>' as 'this' argument discards qualifiers [-fpermissive]
        cm();}

    static void cm ()
        {}};

template <typename T>
T A<T>::cv = 0;

void test1 () {
//  A<int>::cim(); // error: cannot call member function 'void A<T>::cim() const [with T = int]' without object

    A<int> x;
    assert(x.iv == 0);
    assert(x.cv == 0);

    x.cim();
    assert(x.iv == 0);
    assert(x.cv == 1);

    const A<int> y;
    y.cim();}

template <typename T>
class B {
    private:
        T _v;

    public:
        B (const T& v) :
            _v (v)
            {}

        T& get () {
            return _v;}

        const T& get () const {
            return _v;}};

void test2 () {
    B<int> x = 2;
    assert(x.get() == 2);
    x.get() = 3;
    const B<int> y = 3;
    assert(y.get() == 3);
//  y.get() = 4;          // error: assignment of read-only location 'y.B<int>::get()'
    }

int main () {
    using namespace std;
    cout << "ConstMethods.c++" << endl;
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
