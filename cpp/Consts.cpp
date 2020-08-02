// ----------
// Consts.c++
// ----------

// https://www.cplusplus.com/doc/tutorial/constants/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void test1 () {
    int i = 2;
    ++i;
    assert(i == 3);}

void test2 () {
//  const int ci;     // error: uninitialized const 'ci'
    const int ci = 4;
//  ++ci;             // error: increment of read-only variable 'ci'
    assert(ci == 4);}

void test3 () {
    // read/write, many-location pointer
    // mutable int, mutable pointer
          int i  = 2;
    const int ci = 3;
    int*      p;
    p = &i;
    ++*p;
    assert(i == 3);
//  p = &ci;        // error: invalid conversion from 'const int*' to 'int*'
    assert(ci);}

void test4 () {
    // read-only, many-location pointer
    // immutable int, mutable pointer
          int  i  = 2;
    const int  ci = 3;
    const int* pc;
    pc = &ci;
//  ++*pc;                         // error: increment of read-only location
//  int* p = pc;                   // error: invalid conversion from 'const int*' to 'int*'
    int* p = const_cast<int*>(pc);
    assert(p == pc);
//  ++*p;                          // undefined
    pc = &i;                       // ?
    p = const_cast<int*>(pc);
    ++*p;
    assert(i == 3);}

void test5 () {
    // read/write, one-location pointer
    // mutable int, immutable pointer
          int  i  = 2;
    const int  ci = 3;
//  int* const cp;       // error: uninitialized const 'cp'
//  int* const cp = &ci; // error: invalid conversion from 'const int*' to 'int*'
    int* const cp = &i;
//  ++cp;                // error: cannot assign to variable 'cp' with const-qualified type 'int *const'
    ++*cp;
    assert(i == 3);
    assert(ci);}

void test6 () {
    // read-only, one-location pointer
    // immutable int, immutable pointer
          int        i   = 2;
    const int        ci  = 3;
//  const int* const cpc;       // error: uninitialized const 'cpc'
    const int* const cpc = &ci;
    const int* const cqc = &i;
//  ++cqc;                      // error: cannot assign to variable 'cqc' with const-qualified type 'const int *const'
//  ++*cqc;                     // error: increment of read-only location
    assert(cpc);
    assert(cqc);}

void test7 () {
    // read/write reference
    // mutable int
          int i  = 2;
    const int ci = 3;
//  int&      r;      // error: 'r' declared as reference but not initialized
//  int&      r = ci; // error: invalid initialization of reference of type 'int&' from expression of type 'const int'
    int&      r = i;
    ++r;
    assert(i == 3);
    assert(ci);}

void test8 () {
    // read-only reference
    // immutable int
          int  i  = 2;
    const int  ci = 3;
//  const int& rc;      // error: 'rc' declared as reference but not initialized
    const int& rc = ci;
    const int& sc = i;
//  ++sc;               // error: increment of read-only reference 'sc'
    assert(rc);
    assert(sc);}

int main () {
    cout << "Consts.c++" << endl;
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
