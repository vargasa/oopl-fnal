// -----------
// Mon, 10 Aug
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
Glenn:  1-3
Kevin:  4-6
Kyle:   7-9
Marc:  10-12
*/

char a   = "abc"; // no
char a[] = "abc"; // an      array, type of a is still char*
char b[] = "abc"; // another array, type of b is still char*
cout << (a == b);

const char* p = "abc"; // a pointer to an array of char, still char*
const char* q = "abc"; // a pointer to an array of char, still char*
cout << (p == q);      // true, cached literal C string

int i = 2;
int i = 3; // no

p = ...
*p = ...; // no

cout << p[0];
p[0] = ...;   // no

int       i  = 2;
const int ci = 3;

int* p;
p = &i;
p = &ci; // no

const int* p; // doesn't have to be initialized
p = &ci;
++*p;         // no

/*
1. p can only point to a const int
2. p can point to any int, but the int is not modifiable through p ***
*/

p = &i;
++*p;         // no

void f (T y) { // copy of x, expensive
	...}

T x(...);
f(x);     // x is protected

void f (const T* y) { // cheap
	...}

T x(...);
f(&x);    // x is protected, in the absence of evil

void f (const T& y) { // cheap
	...}

T x(...);
f(x);     // x is protected, in the absence of evil

const int& r = ...;
int&       s = r;   // no, can't decrease protection

int&       r = ...;
const int& s = r;   // yes, can increase protection

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

/*
non-zero is true
non-null is true
*/

/*
arrays on the stack
memory is automatically managed
*/

void test1 () {
    int a[] = {2, 3, 4};
    assert(*a == a[0]);                     // dual nature a, you can deference, and you can index
    assert(a  == &a[0]);
    assert(sizeof(a)     != sizeof(&a[0]));
    assert(sizeof(a)     == 12);            // size of array of 3 ints of 4 bytes each
    assert(sizeof(&a[0]) == 8);             // size of an address, on 64 bit machine, is 8 bytes
//  ++a;                                    // error: lvalue required as left operand of assignment
    ++a[1];                                 // int* const a, like that
    ++*(a + 1);
    assert(a[1]     == 5);
    assert(*(a + 1) == 5);
//  assert(a[3]     == 0);                  // undefined
//  assert(*(a + 3) == 0);                  // undefined
    }

void test2 () {
    const size_t s    = 10;
    const int    a[s] = {2, 3, 4}; // only have to initialize some of it
    assert(sizeof(a) == 40);
    assert(a[1]      ==  3);
    assert(*(a + 1)  ==  3);
    assert(a[s - 1]  ==  0);
//  ++a;                           // error: lvalue required as left operand of assignment
//  ++a[1];                        // error: increment of read-only location
    }

struct T {};

// what we get for free
{
T x;     // T's default constructor, only if NO other constructor was defined
T y = x; // T's copy    constructor
x = y;   // T's copy    assignment
}        // T's destructor runs for x and y

T a[] = {2, 3, 4};

/*
what must T have?
	int constructor
*/

struct T {
	T (int) {...}};

T x = 2; // T's int constructor

int s  = 10;
int a[s] = {2, 3, 4}; // O(n), linear effort
T   a[s] = {2, 3, 4}; // O(n), linear effort, T(int), 3 times, T(), 7 times

/*
what must T have?
	int     constructor
	default constructor
*/

// isn't enough
struct T {
	T (int) {...}};

// is enough
struct T {
	T ()    {...}
	T (int) {...}};

void test3 () {
    const size_t s = 10;
//  const int    a[s];       // error: uninitialized const 'a'
    int a[s];
    assert(sizeof(a) == 40);
//  assert(a[0]      ==  0); // undefined values, not undefined behavior
    }

int s = 10;
int a[s];   // O(1), constant effort

T a[s];     // O(n), linear   effort, T(), s times

void test4 () {
    const size_t s    = 10;
    const int    a[s] = {};
    assert(sizeof(a) == 40);
    assert(a[0]      ==  0);}

int s = 10;
const int a[s] = {}; // O(n), linear effort
const T   a[s] = {}; // O(n), linear effort, T(), s times

void test5 () {
    int a[] = {2, 3, 4};
    int b[] = {2, 3, 4};
    assert(a != b);                             // int* comparison
    assert(equal(a, a + 3, b));
    assert(equal(a, b));                        // no, don't know how big
    assert(equal(a, b, 3));                     // no
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

/*
C++ algorithms
	equal
	copy
	fill
	reverse
	...
*/

bool equal (int* b1, int* e1, int* b2) {        // end means one past the last
	...}

cout << equal(x+5, x+10, y+15);

/*
what is the smallest that x could be?
	10
what is the smallest that y could be?
	20
*/

bool equal (int* b1, int* e1, int* b2) {        // end means one past the last
	...}

int a[] = {2, 3, 4};
int b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // true

bool equal (double* b1, double* e1, double* b2) { // end means one past the last
	...}

double a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // no

/*
templates
*/

template <typename T>
bool equal (T* b1, T* e1, T* e2) {
	...}

int a[] = {2, 3, 4};
int b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T -> int

double a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T -> double

int    a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // no

template <typename T1, typename T2
bool equal (T1* b1, T1* e1, T2* e2) {
	...}

int a[] = {2, 3, 4};
int b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1, T2 -> int

double a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1, T2 -> double

int    a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1 -> int, T2 -> double

/*
C++ containers
	vector
	deque
	list
	...
*/

class list {
	...
	class iterator {
		...}
	...};

list<int>           x = {2, 3, 4};              // doubly-linked list
int*                b = <beginning of the list> // it wouldn't work, because ++b would not be the second element
list<int>::iterator b = begin(x);
cout << *b;                                     // 2
++b;
cout << *b;                                     // 3
++b;
cout << *b;                                     // 4
++b;
cout << *b;                                     // undefined

template <typename T1, typename T2
bool equal (T1* b1, T1* e1, T2* e2) {
	...}

int a[] = {2, 3, 4};
int b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1, T2 -> int

double a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1, T2 -> double

int    a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1 -> int, T2 -> double

list a = {2, 3, 4};
list b = {2, 3, 4};
cout << equal(a, a + 3, b);                // no
cout << equal(begin(a), end(a), begin(b)); // no

template <typename T1, typename T2
bool equal (T1 b1, T1 e1, T2 e2) {
	...}

int a[] = {2, 3, 4};
int b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1, T2 -> int*

double a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1, T2 -> double*

int    a[] = {2, 3, 4};
double b[] = {2, 3, 4};
cout << equal(a, a + 3, b); // T1 -> int*, T2 -> double*

list<int> a = {2, 3, 4};
list<int> b = {2, 3, 4};
cout << equal(a, a + 3, b);                // no
cout << equal(begin(a), end(a), begin(b)); // T1, T2 -> list<int>::iterator

list<int>  a = {2, 3, 4};
deque<int> b = {2, 3, 4};
cout << equal(a, a + 3, b);                // no
cout << equal(begin(a), end(a), begin(b)); // T1 -> list<int>::iterator, T2 -> deque<int>::iterator

/*
write our own containers
*/

template <typename T>
class kres_container {
	...
	class iterator {
		...}
	...};

kres_container<int> a = {2, 3, 4};
deque<int>          b = {2, 3, 4};
cout << equal(a, a + 3, b);                // no
cout << equal(begin(a), end(a), begin(b)); // T1 -> kres_container<int>::iterator, T2 -> deque<int>::iterator

#ifdef TEST0
void test0 () {
    const int  a[] = {2, 3, 4};
    const int  b[] = {0, 2, 3, 4, 0};
    const int* b1  = begin(a);
    const int* e1  = end(a);
    const int* b2  = begin(b);
    assert(!my_equal(b1, e1, b2));}
#endif

#ifdef TEST1
void test1 () {
    const int  a[] = {2, 3, 4};
    const int  b[] = {0, 2, 3, 4, 0};
    const int* b1  = begin(a);
    const int* e1  = end(a);
    const int* b2  = begin(b) + 1;
    assert(my_equal(b1, e1, b2));}
#endif

#ifdef TEST2
void test2 () {
    const list<int>             x  = {2, 3, 4};
    const vector<int>           y  = {0, 2, 3, 4, 0};
    list<int>::const_iterator   b1 = begin(x);
    list<int>::const_iterator   e1 = end(x);
    vector<int>::const_iterator b2 = begin(y) + 1;
    assert(my_equal(b1, e1, b2));}
#endif

forward_list<int>           x = {2, 3, 4};
forward_list<int>::iterator b = begin(x);
cout << *b;
++b;
cout << *b;
--b;        // no
cout << (b != e);
cout << (b <  e); // no

list<int>           x = {2, 3, 4};
list<int>::iterator b = begin(x);
cout << *b;
++b;
cout << *b;
--b;        // yes
b += 1;     // no
b += 10;    // no
cout << (b <  e); // no

vector<int>           x = {2, 3, 4};
vector<int>::iterator b = begin(x);
cout << *b;
++b;
cout << *b;
--b;        // yes
b += 1;     // yes
b += 10;    // yes
cout << (b <  e); // yes

template <typename T1, typename T2>
bool equal (T1 b1, T1 e1, T2 b2) {
	while (b1 != e1) {
		if (*b1 != *b2)
			return false;
		++b1;
		++b2;}
	return true;}

template <typename T1, typename T2>
T2 copy (T1 b1, T1 e1, T2 b2) {
	while (b1 != e1) {
		*b2 = *b1;
		++b1;
		++b2;}
	return b2;}

template <typename T1, typename T2>
void fill (T1 b, T1 e, const T2& v) {
	while (b != e) {
		*b = v;
		++b;}}

/*
build our own algorithms
build our own containers
*/

/*
build algorithms that are the require the WEAKEST   iterators
build containers that         provide the STRONGEST iterators
*/

#ifdef TEST0
void test0 () {
    int  a[5]   = {};
    int* b      = begin(a) + 1;
    int* e      = end(a)   - 1;
    const int v = 2;
    my_fill(b, e, v);
    assert(equal(begin(a), end(a), begin({0, 2, 2, 2, 0})));}
#endif

#ifdef TEST1
void test1 () {
    list<int>           x(5);
    list<int>::iterator b = begin(x);
    list<int>::iterator e = end(x);
    const int           v = 2;
    ++b;
    --e;
    my_fill(b, e, v);
    assert(equal(begin(x), end(x), begin({0, 2, 2, 2, 0})));}
#endif



void test6 () {
    int a[] = {2, 3, 4};
//  int b[] = a;                    // error: initializer fails to determine size of 'b'
    int* b  = a;
    assert(a         == b);
    assert(sizeof(a) != sizeof(b));
    assert(sizeof(a) == 12);
    assert(sizeof(b) ==  8);
    ++b[1];
    assert(equal(a, a + 3, begin({2, 4, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

void test7 () {
    int          a[] = {2, 3, 4};
    const size_t s   = sizeof(a) / sizeof(a[0]);
    int b[s];
    copy(a, a + s, b);
    assert(a != b);
    assert(equal(a, a + s, b));
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

void test8 () {
    int a[] = {2, 3, 4};
    int b[] = {5, 6, 7};
//  b = a;                                     // error: invalid array assignment
    const size_t s = sizeof(a) / sizeof(a[0]);
    copy(a, a + s, b);
    assert(a != b);
    assert(equal(a, a + s, b));
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

void f (int p[]) {
    assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

void test9 () {
    int a[] = {2, 3, 4};
    f(a);
    assert(equal(a, a + 3, begin({2, 5, 4})));}

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

void test10 () {
    int a[] = {2, 3, 4};
    g(a);
    assert(equal(a, a + 3, begin({2, 5, 4})));}

void test11 () {
    array<int, 3> x = {2, 3, 4};
    assert(x.size() == 3);
    assert(x[1]     == 3);
    array<int, 3> y(x);
    assert( x    ==  y);
    assert(&x[1] != &y[1]);}

void test12 () {
    array<int, 3> x = {2, 3, 4};
    array<int, 3> y = {5, 6, 7};
    x = y;
    assert( x    ==  y);
    assert(&x[1] != &y[1]);}

void h1 (array<int, 3>& y) {
    array<int, 3>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test13 () {
    array<int, 3> x = {2, 3, 4};
    h1(x);
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}

void h2 (array<int, 3> y) {
    array<int, 3>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test14 () {
    array<int, 3> x = {2, 3, 4};
    h2(x);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}
