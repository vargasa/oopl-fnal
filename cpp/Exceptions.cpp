// --------------
// Exceptions.c++
// --------------

// https://en.cppreference.com/w/cpp/error/exception

#include <cassert>   // assert
#include <cstring>   // strcmp
#include <iostream>  // cout, endl
#include <stdexcept> // domain_error
#include <string>    // string

using namespace std;

int f (bool b) {
    if (b)
        throw domain_error("abc");
    return 0;}

void test1 () {
    try {
        assert(f(false) == 0);
        }
    catch (domain_error& e) {
        assert(false);}}

void test2 () {
    try {
        f(true);
        assert(false);
        }
    catch (domain_error& e) {
//      assert(       e                == "abc");   // error: no match for ‘operator==’ in ‘e == "abc"’
//      assert(       e.what()         != "abc");   // warning: comparison with string literal results in unspecified behavior
        assert(strcmp(e.what(), "abc") == 0);
        assert(string(e.what())        == "abc");}}

void test3 () {
    domain_error x("abc");
    logic_error& y = x;
    exception&   z = y;
    assert(&x == &z);}

int main () {
    cout << "Exceptions.c++" << endl;
    test1();
    test2();
    test3();
    cout << "Done." << endl;
    return 0;}
