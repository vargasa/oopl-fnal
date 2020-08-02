// ---------------------
// InstanceVariables.c++
// ---------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
struct A {
    int iv = 0;};

void test () {
//  assert(A<int>::iv == 0); // error: invalid use of non-static data member 'A<int>::iv'

    A<int> x;
    assert(x.iv == 0);

    A<int> y;
    assert(y.iv == 0);

    assert(&x.iv != &y.iv);}

int main () {
    cout << "InstanceVariables.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
