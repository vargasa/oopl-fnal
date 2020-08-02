// -----------------------
// FunctionOverloading.c++
// -----------------------

// https://www.cplusplus.com/doc/tutorial/functions2/

// ad-hoc compile-time polymorphism

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <iostream> // cout, endl
#include <string>   // string

using namespace std;

string f1 (int) {              // l-value or r-value
    return "f1(int)";}

//string f1 (const int) {      // error: redefinition of "string f1(int)"
//    return "f1(const int)";}

void test1 () {
    int       i  = 2;
    const int ci = 3;
    assert(f1(i)  == "f1(int)");
    assert(f1(ci) == "f1(int)");
    assert(f1(4)  == "f1(int)");}



string f2 (int&) {      // non-const l-value
    return "f2(int&)";}

void test2 () {
    int       i  = 2;
    const int ci = 3;
    assert(f2(i)  == "f2(int&)");
//  f2(ci);                       // error: no matching function for call to 'f2'
//  f2(4);                        // error: no matching function for call to 'f2'
    assert(ci);
    }



string f3 (const int&) {      // l-value or r-value
    return "f3(const int&)";}

void test3 () {
    int       i  = 2;
    const int ci = 3;
    assert(f3(i)  == "f3(const int&)");
    assert(f3(ci) == "f3(const int&)");
    assert(f3(4)  == "f3(const int&)");}



string f4 (int&&) {      // r-value
    return "f4(int&&)";}

void test4 () {
    int       i  = 2;
    const int ci = 3;
//  assert(f4(i)  == "f4(int&&)");  // error: no matching function for call to 'f4'
//  assert(f4(ci) == "f4(int&&)");  // error: no matching function for call to 'f4'
    assert(f4(4)  == "f4(int&&)");
    assert(i);
    assert(ci);}



string f5 (int&) {            // non-const l-value
    return "f5(int&)";}

string f5 (const int&) {      // const l-value or r-value
    return "f5(const int&)";}

void test5 () {
    int       i  = 2;
    const int ci = 3;
    assert(f5(i)  == "f5(int&)");
    assert(f5(ci) == "f5(const int&)");
    assert(f5(4)  == "f5(const int&)");}



string f6 (int&) {       // non-const l-value
    return "f6(int&)";}

string f6 (int&&) {      // r-value
    return "f6(int&&)";}

void test6 () {
    int       i  = 2;
    const int ci = 3;
    assert(f6(i)  == "f6(int&)");
//  f6(ci);                         // error: no matching function for call to 'f6'
    assert(f6(4)  == "f6(int&&)");
    assert(ci);}



string f7 (const int&) {      // l-value
    return "f7(const int&)";}

string f7 (int&&) {           // r-value
    return "f7(int&&)";}

void test7 () {
    int       i  = 2;
    const int ci = 3;
    assert(f7(i)  == "f7(const int&)");
    assert(f7(ci) == "f7(const int&)");
    assert(f7(4)  == "f7(int&&)");}



string f8 (int&) {            // non-const l-value
    return "f8(int&)";}

string f8 (const int&) {      // const l-value
    return "f8(const int&)";}

string f8 (int&&) {           // r-value
    return "f8(int&&)";}

void test8 () {
    int       i  = 2;
    const int ci = 3;
    assert(f8(i)  == "f8(int&)");
    assert(f8(ci) == "f8(const int&)");
    assert(f8(4)  == "f8(int&&)");}

int main () {
    cout << "FunctionOverloading.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    cout << "Done." << endl;
    return 0;}
