// -----------
// Mon,  3 Aug
// -----------

/*
Website
	https://www.oopl.com/fnal/index.html
*/

/*
Instructor: Glenn Downing
*/

/*
Cold Calling
	you're only called ONCE per rotation
	it's totally fine to be wrong, the idea is to discuss and to learn
	I'll use Canvas attendance, whose grade you can ignore
*/

/*
I'll take notes, and I'll put those notes into GitLab
*/

/*
B.S. in physics at Illinois in '75
M.S. in aero/astro at MIT in '77
have been teaching CS at UT Austin since '95
*/

// --

// https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html
// https://en.cppreference.com

#include <iostream> // cout, endl

using namespace fnal;

int main () {
    using namespace std;
    cout << "Nothing to be done." << endl;
    return 0;}

/*
Developed in 1978 by Bjarne Stroustrup of Denmark.
C++ is procedural, object-oriented, statically typed, and not garbage collected.

C++98
C++03
C++11
C++14
C++17
C++20
C++23



% which g++-9
/usr/local/bin/g++-9



% g++-9 --version
g++-9 (Homebrew GCC 9.3.0) 9.3.0



% g++-9 -pedantic -std=c++17 -O3 -Wall -Wextra Hello.c++ -o Hello



% ./Hello
Nothing to be done.
*/

/*
operators and functions
maybe return someting
maybe do     something
*/

int i = 2;
cout << i; // print i

int j = 3;
(cout << i) << j; // print i, j

/*
what is
	cout << i
returning?
*/

int k = (i + j) + j;

i + j; // no, + doesn't do anything, but it does return something, it returns the sum

int k = (i + j);

// in the library
ostream cout...

ostream p = (cout << i);

/*
endl  prints a new line and flushes the output buffer
"\n"  prints only a new line
flush only flushes the output buffer

what does it mean for output to be buffered
*/

/*
operators the fabric of a language
*/

int i = 2;
int j = 3;
int k = (i << j); // bit shift left
// i * 2^j
cout << k;        // 16

i << j; // no
i +  j; // no

/*
there are many meanings to <<
123 -> 1230
1 -> 10
*/

/*
<< with an ostream
1. outputs a value
2. returns the ostream

<< with an int
1. does nothing
2. returns the bit shifted left value
*/

cout << i << j;

int k = (i << j) << j;

i <<= j;
i = (i << j);

/*
<<= with an int
1. modifies it's left hand side
2. return the modified left hand side
*/

int k = (i <<= j) << j; // C, Java, Python

(i + j) = k; // no

/*
l-value
	a value that can be on the left or the right of assignment
	its address can be taken

r-value
	a value that can only be in the right of assignment
	its address can not be taken
*/

k = 2;
2 = k; // no
j = k;

/*
+ on int
1. does nothing
2. returns the sum as an r-value

<< with an int
1. does nothing
2. returns the bit shifted left value as an r-value
*/

(i << j) = k; // no

(i <<= j) = k; // pointless, legal; NO in C, Java, Python

/*
<<= with an int
1. modifies the variable
2. returns the modified variable as an l-value
*/

int f (int i) {
	return i + 1;}

int i = 2;
f(i);         // useless
int j = f(i); // useful

void g (int i) {
	cout << i;}

int i = 2;
g(i);         // useful
int j = g(i); // no

int h (int i) {
	cout << i;
	return i;}

int i = 2;
h(i);         // useful
int j = h(i); // useful

/*
operators are overloaded
<< is defined on
1. int (language)
2. ostream, many times (library), on all of the built-in types (including pointers)
*/

int i = 2;
cout << i;

double d = 3.4;
cout << d;

string s = "abc";
cout << s;

struct Sedrick {...};

Sedrick x(...);

cout << x; // print a Sedrick

/*
<< is not defined on double (language, library)
can we define that?
	NO
*/

/*
<< is defined on int (language)
can we redefine that?
	NO
*/

/*
the only to overload an operator is with a new type, like Sedrick
*/

void* p = ...;
cout << *p;    // no

vector<int> x;
cout << x;     // no

struct A {...};

A x;
cout << x;  // yes, if A overloaded <<

A* p = &x;
cout << *p; // yes, too

cout << p;  // they'll print the address

/*
assertions
*/

/*
Collatz Conjecture
it's about 100 years old
*/

/*
take a pos
if odd
	multiply by 3 and add 1
otherwise
	divide by 2
repeat until 1
*/

/*
always terminates
*/

1
5 16 8 4 2 1
10 5 16 8 4 2 1

/*
the cycle length of  5 is 6
the cycle length of 10 is 7
*/

/*
powers have the quality that repeated division by 2 leaves it even
*/

int cycle_length (int n) {
    assert(n > 0);           // a precondition
    int c = 0;               // initialization, should be 1!!!
    while (n > 1) {
        if ((n % 2) == 0)    // n is even
            n = (n / 2);     // n /= 2;
        else
            n = (3 * n) + 1; // ++(n *= 3), don't want ++n *= 3
        ++c;}
    assert(c > 0);           // a postcondition
    return c;}

void test () {
    assert(cycle_length( 1) == 1);  // test, fails
    assert(cycle_length( 5) == 6);
    assert(cycle_length(10) == 7);}

/*
% g++-9 -pedantic -std=c++17 -O3 -Wall -Weffc++ Assertions.cpp -o Assertions
% ./Assertions
Assertions.c++
Assertion failed: (c > 0), function cycle_length, file Assertions.cpp, line 21.



% g++-9 -pedantic -std=c++17 -O3 -DNDEBUG -Wall -Weffc++ Assertions.cpp -o Assertions
% ./Assertions
Assertions.c++
Done.
*/

/*
assertions are NOT good for testing, because of early failure
unit test frameworks ARE good for testing, Google Test
*/

/*
assertions are NOT good for user errors
exceptions ARE good for user errors
*/

int i = 2; // initialization
i = 2;     // assignment

int i = 2;
int j = ++i;
cout << i << " " << j; // 3 3

int i = 2;
int j = i++;
cout << i << " " << j; // 3 2

++i = 3; // legal, NO in C, Java, Python
i++ = 3; // no

++++i; // sure!
i++++; // no

2++; // no
++2; // no

/*
preincrememt
	1. modifies its variable
	2. returns the modified variable as an l-value

postincrement
	1. modifies its variable
	2. returns the unmodified variable as an r-value
*/

/*
writes a lot!
even before you write the code
run the tests a lot!
*/

#include "gtest/gtest.h" // unit test framework called Google Test

int cycle_length (int n) {
    assert(n > 0);
    int c = 0;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(UnitTestsFixture, test1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(UnitTestsFixture, test2) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST(UnitTestsFixture, test3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% locate libgtest.a
/lusr/lib/libgtest.a



% locate libgtest_main.a
/lusr/lib/libgtest_main.a



% locate libpthread.a
/usr/lib/x86_64-linux-gnu/libpthread.a



% g++-8 -pedantic -std=c++17 -O3 -Wall -Weffc++ -Wextra UnitTests1.cpp -o UnitTests1 -lgtest -lgtest_main -pthread



% ./UnitTests1
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test1
Assertion failed: (c > 0), function cycle_length, file UnitTests1.cpp, line 23.
*/

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(UnitTestsFixture, test1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(UnitTestsFixture, test2) {
    ASSERT_EQ(cycle_length( 5), 5);}

TEST(UnitTestsFixture, test3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% ./UnitTests2
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test1
[       OK ] UnitTestsFixture.test2 (0 ms)
[ RUN      ] UnitTestsFixture.test1
UnitTests2.cpp:30: Failure
Expected equality of these values:
  cycle_length( 5)
    Which is: 6
  5
[  FAILED  ] UnitTestsFixture.test2 (0 ms)
[ RUN      ] UnitTestsFixture.test3
[       OK ] UnitTestsFixture.test3 (0 ms)
[----------] 3 tests from UnitTestsFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] UnitTestsFixture.test2

 1 FAILED TEST
*/

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(UnitTestsFixture, test1) {
    ASSERT_EQ(cycle_length( 1), 1);}

TEST(UnitTestsFixture, test2) {
    ASSERT_EQ(cycle_length( 5), 6);}

TEST(UnitTestsFixture, test3) {
    ASSERT_EQ(cycle_length(10), 7);}

/*
% ./UnitTests3
Running main() from gtest_main.cc
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from UnitTestsFixture
[ RUN      ] UnitTestsFixture.test1
[       OK ] UnitTestsFixture.test1 (0 ms)
[ RUN      ] UnitTestsFixture.test2
[       OK ] UnitTestsFixture.test2 (0 ms)
[ RUN      ] UnitTestsFixture.test3
[       OK ] UnitTestsFixture.test3 (0 ms)
[----------] 3 tests from UnitTestsFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 3 tests.
*/

bool is_prime (int n) {
    assert(n > 0);
    if ((n == 1) || ((n % 2) == 0))
        return false;
    for (int i = 3; i < std::sqrt(n); ++i)
        if ((n % i) == 0)
            return false;
    return true;}

void test0 () {
    assert(!is_prime( 1));}

void test1 () {
    assert(!is_prime( 2));}

void test2 () {
    assert( is_prime( 3));}

void test3 () {
    assert(!is_prime( 4));}

void test4 () {
    assert( is_prime( 5));}

void test5 () {
    assert( is_prime( 7));}

void test6 () {
    assert( is_prime( 9));}

void test7 () {
    assert(!is_prime(27));}

void test8 () {
    assert( is_prime(29));}

/*
bad tests hiding bad code
*/

/*
1-4: Glenn
5-8: Andrew
9-12: David
13-16: Marc
*/

/*
1. run the code as is, confirm success
2. identify (and remember) and fix the broken test
3. run the code again, confirm failure
4. identify (and remember) and fix the broken code
5. run the code again, confirm success
*/

bool is_prime (int n) {
    assert(n > 0);
    if (n == 2)
    	return true;
    if ((n == 1) || ((n % 2) == 0))
        return false;
    for (int i = 3; i < std::sqrt(n) + 1; ++++i)
        if ((n % i) == 0)
            return false;
    return true;}

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(CoverageFixture, test) {
    ASSERT_EQ(cycle_length(1), 1);}

/*
% g++-9 --coverage -pedantic -std=c++17 -O3 -Wall -Weffc++ -Wextra Coverage1.cpp -o Coverage1 -lgtest -lgtest_main -pthread



% ./Coverage1
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.



% ls -al Coverage1.*
-rw-r--r--@ 1 downing  staff   1179 Jun 11 17:55 Coverage1.cpp
-rw-r--r--@ 1 downing  staff   1552 Jun 25 19:40 Coverage1.gcda
-rw-r--r--@ 1 downing  staff  21288 Jun 25 19:40 Coverage1.gcno



% gcov-9 -b Coverage1.cpp | grep -B 2 "cpp.gcov"
File 'Coverage1.cpp'
Lines executed:60.00% of 10
Creating 'Coverage1.cpp.gcov'
*/

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(CoverageFixture, test) {
    ASSERT_EQ(cycle_length(2), 2);}

/*
% g++-9 -fprofile-arcs -ftest-coverage -pedantic -std=c++17 -O3 -Wall -Weffc++ -Wextra Coverage2.cpp -o Coverage2 -lgtest -lgtest_main -pthread



% ./Coverage2
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.



% ls -al Coverage1.*
-rw-r--r--@ 1 downing  staff   1179 Jun 11 17:55 Coverage1.cpp
-rw-r--r--@ 1 downing  staff   1552 Jun 25 19:40 Coverage1.gcda
-rw-r--r--@ 1 downing  staff  21288 Jun 25 19:40 Coverage1.gcno



% gcov-9 Coverage2.cpp | grep -B 2 "cpp.gcov"
File 'Coverage2.cpp'
Lines executed:90.00% of 12
Creating 'Coverage2.cpp.gcov'
*/

int cycle_length (int n) {
    assert(n > 0);
    int c = 1;
    while (n > 1) {
        if ((n % 2) == 0)
            n = (n / 2);
        else
            n = (3 * n) + 1;
        ++c;}
    assert(c > 0);
    return c;}

TEST(CoverageFixture, test) {
    ASSERT_EQ(cycle_length(3), 8);}

/*
% g++-9 -fprofile-arcs -ftest-coverage -pedantic -std=c++17 -O3 -Wall -Weffc++ -Wextra Coverage3.cpp -o Coverage3 -lgtest -lgtest_main -pthread



% ./Coverage3
Running main() from gtest_main.cc
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CoverageFixture
[ RUN      ] CoverageFixture.test
[       OK ] CoverageFixture.test (0 ms)
[----------] 1 test from CoverageFixture (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.



% ls -al Coverage1.*
-rw-r--r--@ 1 downing  staff   1179 Jun 11 17:55 Coverage1.cpp
-rw-r--r--@ 1 downing  staff   1552 Jun 25 19:40 Coverage1.gcda
-rw-r--r--@ 1 downing  staff  21288 Jun 25 19:40 Coverage1.gcno



% gcov-9 -b Coverage3.cpp | grep -B 2 "cpp.gcov"
File 'Coverage3.cpp'
Lines executed:100.00% of 12
Creating 'Coverage3.cpp.gcov'
*/

/*
write tests a lot!
even before you write the code
run the tests a lot!
	continuous integration
make sure you have good coverage
*/
