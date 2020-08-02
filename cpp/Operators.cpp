// -------------
// Operators.c++
// -------------

// https://en.cppreference.com/w/cpp/language/operators

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

void test1 () {
    int i = 2;
    int j = ++i;    // pre-increment
    assert(i == 3);
    assert(j == 3);
    ++++i;
    assert(i == 5);
    (++i)++;
    assert(i == 7);}

void test2 () {
    int i = 2;
    int j = i++;    // post-increment
    assert(i == 3);
    assert(j == 2);
//  i++++;          // error: lvalue required as increment operand
//  ++(i++);        // error: lvalue required as increment operand}
    }

void test3 () {
    int i = 2;
    int j = -i;      // negation
    assert(i ==  2);
    assert(j == -2);
//  ++-i;            // error: lvalue required as increment operand}
    }

void test4 () {
    int i = 2;
    int j = 3;
    int k = (i = j); // assignment
    assert(i == 3);
    assert(j == 3);
    assert(k == 3);
    ++(i = j);
    assert(i == 4);}

void test5 () {
    int i = 2;
    int j = 3;
    int k = i + j;  // addition
    assert(i == 2);
    assert(j == 3);
    assert(k == 5);
//  ++(i + j);      // error: lvalue required as increment operand}
    }

void test6 () {
    int i = 2;
    int j = 3;
    int k = (i += j); // in-place addition
    assert(i == 5);
    assert(j == 3);
    assert(k == 5);
    ++(i += j);
    assert(i == 9);}

void test7 () {
    int i = 5;
    int j = 2;;
    int k = i / j;   // integer division
    assert(i == 5);
    assert(j == 2);
    assert(k == 2);
//  ++(i / j);       // error: lvalue required as increment operand}
    }

void test8 () {
    int i = 5;
    int j = 2;;
    int k = (i /= j); // integer in-place division
    assert(i == 2);
    assert(j == 2);
    assert(k == 2);
    ++(i /= j);
    assert(i == 2);}

void test9 () {
    int i = 12;
    int j = 10;
    int k = i % j;   // mod
    assert(i == 12);
    assert(j == 10);
    assert(k ==  2);
//  ++(i % j);       // error: lvalue required as increment operand}
    }

void test10 () {
    int i = 12;
    int j = 10;
    int k = (i %= j); // in-place mod
    assert(i ==  2);
    assert(j == 10);
    assert(k ==  2);
    ++(i %= j);
    assert(i ==  3);}

void test11 () {
    int i = 2;
    int j = ~i;       // bit complement
    int k = ~j;
    assert(i ==  2);
    assert(j == -3);
    assert(k ==  2);
//  ++~i;             // error: lvalue required as increment operand}
    }

void test12 () {
    int i = 2;
    int j = 3;
    int k = i << j;  // bit shift left
    assert(i == 2);
    assert(j == 3);
    assert(k == 16);
//  ++(i << j);      // error: lvalue required as increment operand}
    }

void test13 () {
    int i = 2;
    int j = 3;
    int k = (i <<= j); // in-place bit shift left
    assert(i ==  16);
    assert(j ==   3);
    assert(k ==  16);
    ++(i <<= j);
    assert(i == 129);}

void test14 () {
    int i = 10;      // 1010
    int j = 12;      // 1100
    int k = i & j;   // 1000: bit and
    assert(i == 10);
    assert(j == 12);
    assert(k ==  8);
//  ++(i & j);       // error: lvalue required as increment operand}
    }

void test15 () {
    int i = 10;
    int j = 12;
    int k = (i &= j); // in-place bit and
    assert(i ==  8);
    assert(j == 12);
    assert(k ==  8);
    ++(i &= j);
    assert(i ==  9);}

void test16 () {
    int i = 10;      // 1010
    int j = 12;      // 1100
    int k = i | j;   // 1110: bit or
    assert(i == 10);
    assert(j == 12);
    assert(k == 14);
//  ++(i | j);       // error: lvalue required as increment operand}
    }

void test17 () {
    int i = 10;
    int j = 12;
    int k = (i |= j);
    assert(i == 14);
    assert(j == 12);
    assert(k == 14);
    ++(i |= j);
    assert(i == 15);}

void test18 () {
    int i = 10;      // 1010
    int j = 12;      // 1100
    int k = i ^ j;   // 0110: bit exclusive or
    assert(i == 10);
    assert(j == 12);
    assert(k ==  6);
//  ++(i ^ j);       // error: lvalue required as increment operand}
    }

void test19 () {
    int i = 10;
    int j = 12;
    int k = (i ^= j);
    assert(i ==  6);
    assert(j == 12);
    assert(k ==  6);
    ++(i ^= j);
    assert(i == 11);}

void test20 () {
    int i = 10;
    int j = 12;
    i ^= j;
    j ^= i;
    i ^= j;
    assert(i == 12);
    assert(j == 10);}

void test21 () {
    bool a = true;
    bool b = true;
    bool c = false;
    assert(a && b);
    assert(!(a && c));
    assert(a || b);
    assert(a || c);}

void test22 () {
    int a[] = {2, 3, 4};
    assert(a[1] == 3);   // array index
    ++a[1];
    assert(a[1] == 4);}

void test23 () {
    const int a[] = {2, 3, 4};
    assert(a[1] == 3);
//  ++a[1];                    // error: increment of read-only location
    }

int main () {
    cout << "Operators.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();
    test20();
    test21();
    test22();
    test23();
    cout << "Done." << endl;
    return 0;}
