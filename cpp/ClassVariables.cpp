// ------------------
// ClassVariables.c++
// ------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
struct A {
    static int cv;};

template <typename T>
int A<T>::cv = 0;

void test () {
    assert(A<int>::cv  == 0);
    assert(&A<int>::cv != &A<double>::cv);

    A<int> x;
    A<int> y;
    assert(&x.cv == &y.cv);}

int main () {
    using namespace std;
    cout << "ClassVariables.c++" << endl;
    test();
    cout << "Done." << endl;
    return 0;}
