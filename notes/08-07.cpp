// -----------
// Fri,  7 Aug
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

struct Mammal {
	int i;};

struct Tiger : Mammal {
	int j;};

int f (...) {
	...
	if (...)
		throw Tiger(...); // throw always copies what it throws
	...}

void g (...) {
	...
	try {
		...}
	catch (Mammal  e) { // compiles, but not useful
		...}
	catch (Mammal* e) { // it could work, but it's inconvenient
		...}
	catch (Mammal& e) {
		...}
	...}

/*
Mon
	l-value vs r-value
	operator overloading
	assertions
	unit tests
	coverage

Wed
	values vs pointers vs references
	exceptions

Fri
	exceptions
	operators
	consts
	arrays
*/

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
        assert(       e.what()         != "abc");   // warning: comparison with string literal results in unspecified behavior
        assert(strcmp(e.what(), "abc") == 0);
        assert(string(e.what())        == "abc");}}

void test3 () {
    domain_error x("abc");
    logic_error& y = x;
    exception&   z = y;
    assert(&x == &z);}

/*
89
	domain_error == char*; // there is no such operator

90
	e.what() -> char*
	char* == char*;        // yes, but it's comparing addresses!!!
*/

int  i = 2;
int* p = &i;

class string {
	private:
		...
	public:
		string (char*) {...}
	}          // maybe they built == to handle a string and a char*, they didn't

string s("abc"); // C++ string

/*
92
	string == char*  // is there an == that takes a string and a char*??? NO
	char* -> string
	string == string // obviously that works
*/

void f (double d) {
	...}

f(2.34);
f(2);    // ok, there's an implicit conversion between int -> double

void f (string t) {
	}

string s("abc");
f(s);
f("abc");        // ok, there's an implicit conversion between char* -> string

/*
if you have a couple of types, A and B
how can you compare an A to a B
1. build an == that takes an A and a B
2. build an implicit conversion either from A -> B or from B -> A
*/

m 5-8
q 9-12
s 13-16

#ifdef TEST0
void test0 () {
    assert(my_strcmp("",    "")    == 0);}
#endif

#ifdef TEST1
void test1 () {
    assert(my_strcmp("abc", "abc") == 0);}
#endif

#ifdef TEST2
void test2 () {
    assert(my_strcmp("abc", "ab")  >  0);}
#endif

#ifdef TEST3
void test3 () {
    assert(my_strcmp("abc", "aba") >  0);}
#endif

#ifdef TEST4
void test4 () {
    assert(my_strcmp("ab",  "abc") <  0);}
#endif

#ifdef TEST5
void test5 () {
    assert(my_strcmp("aba", "abc") <  0);}
#endif

int my_strcmp (const char* a, const char* b) {
    while ((*a != 0) && (*a == *b)) {
        ++a;
        ++b;}
    return (*a - *b);}

/*
the type of "abc" is char*, sometimes called a C string
not to be confused with a C++ string
*/

string s = "abc"; // C++ string, being initialized with a C string (char*)

int i; // doesn't have to be initialized
i = 2;
++i;

const int ci;     // has to be initialized
const int ci = 2;
++ci;             // no

/*
many location, read write pointer
*/

int  i = 2;
int* p = &i;
++*p;

const int ci = 2;
int*      p  = &ci; // no

int j = 3;
p = &j;

/*
many location, read only pointer
*/

int       i  = 2;
const int ci = 2;

const int* pc;       // yes, doesn't have to be initialized
pc = &ci;
++*pc;               // no
cout << *pc;

const int cj = 4;
pc = &cj;
++*pc;               // no

pc = &i;             // yes

void f (A y) {       // read only, but expensive
	...}

A x(...);
f(x);

void f (const A* y) {         // read only, and cheap
					          // f could be evil
	A* z = y;                 // no
	A* z = const_cast<A*>(y); // yes!!!
	...}

A x(...);       // x is read write
f(&x);

const A y(...); // y is read only
f(&y);          // undefined!!!

/*
one location, read write pointer
*/

int       i  = 2;
const int ci = 2;

int* const cp;       // no, has to be initialized
int* const cp = &ci; // no
int* const cp = &i;  // yes

int j = 3;
cp = &j;   // no

++*cp;     // yes
++cp;      // no

int* a = new int[100]; // an array of 100 ints on the heap (free store)
++*a;
++a;
++*a;
delete [] a; // giving it back to the heap (free store), undefined!!!

/*
Python has automatic memory management (garbage collector)
Java same thing

C, C++ are MANUAL memory management
*/

int* const a = new int[100]; // an array of 100 ints on the heap (free store)
++a;                         // no
int* b = a;
++*b;
++b;
++*b;
delete [] a;                 // giving it back to the heap (free store), undefined!!!

delete nullptr; // well defined to do nothing

/*
one location, read only pointer
*/

int       i  = 2;
const int ci = 2;

const int* const cpc;       // no, has to be initialized
const int* const cpc = &ci;
++*cpc;                     // no
++cpc;                      // no

const int* const cqc = &i;
++*cqc;                     // no
++cqc;                      // no

/*
use case
a piece of memory on the heap that we don't want to change
*/

int       i  = 2;
const int ci = 2;

/*
read write reference
*/

int& r;      // no, has to be initialized

int& r = ci; // no
++r;

/*
four kinds of pointers:
	1. T*
	2. const T*
	3. T* const
	4. const T* const
*/

/*
T& is most like T* const
*/

/*
read only reference
*/

int       i  = 2;
const int ci = 2;

const int& r;      // no, has to be initialized

const int& r = ci; // yes
++r;               // no

const int& s = i;  // yes
++s;               // no

/*
two kinds of references
	1. T&       // most like T* const
	2. const T& // most like const T* const
*/

void f (A y) {       // read only, but expensive
	...}

A x(...);
f(x);

void f (const A& y) {         // read only, and cheap
					          // f could be evil
	A& z = y;                 // no
	A& z = const_cast<A&>(y); // yes!!!
	...}

A x(...);       // x is read write
f(x);
