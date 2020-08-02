// ------------------
// LocalVariables.c++
// ------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

int f () {
    int i = 2;
    ++i;
    return i;}

int g () {
    static int j = 3;
    ++j;
    return j;}

int main () {
    cout << "LocalVariables.c++" << endl;
    assert(f() == 3);
    assert(f() == 3);

    assert(g() == 4);
    assert(g() == 5);
    cout << "Done." << endl;
    return 0;}
