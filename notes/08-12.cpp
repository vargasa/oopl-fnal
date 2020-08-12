// -----------
// Wed, 12 Aug
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
Glenn:   1-3
Kurt:    4-5
Pengfei: 6-7
Marc:    8-9
*/

void f (int p[]) {            // compiler will warn about this
    cout << sizeof(p) << " ";
    ++p;
    ++*p;
    p = 0;}

void f (int* p]) {
    cout << sizeof(p) << " ";
    ++p;
    ++*p;
    p = 0;}

struct A {
    A () {                    // default constructor
        cout << "A() ";}

    A (int) {                 // int constructor
        cout << "A(int) ";}};

{
A x;     // default constructor
A y(2);  // int     constructor
A z = 2; // int     constructor

A t(x);  // copy    constructor
A u = x; // copy    constructor

u = x;   // copy    assignment
}        // x, y, z, t, u, all die, destructor

struct A {};

A x;     // default constructor
A y(2);  // no
A z = 2; // no

A t(x);  // copy    constructor
A u = x; // copy    constructor

u = x;   // copy    assignment

struct A {
    A (int) {                 // int constructor
        cout << "A(int) ";}};

A x;     // no
A y(2);  // int     constructor
A z = 2; // int     constructor

A t(x);  // copy    constructor
A u = x; // copy    constructor

u = x;   // copy    assignment

int i = 2; // initialization, i has to NOT exist
i = 2;     // assignment,     i HAS to     exist

A x[2] = {3, 4}; // A(int), A(int), O(n), linear time
A y[2];          // A(),    A(),    O(n), linear time

int z[2];        // O(1), constant time

A   x[2] = {};   // A(), A(), O(n), linear time
int y[2] = {};   // O(n), linear time, guaranteed zeros

/*
reference
	can't move

pointer
	*, ++, --, <, +, -, [], =

an iterator
	what an iterator responds to, depends on the type iterator
	forward_list<int>::iterator
		doesn't respond to --, [], +, -, <
	list<int>::iterator
		doesn't respond to [], +, -, <
	vector<int>::iterator
		same as a pointer
*/

void test5 () {
    int a[] = {2, 3, 4};
    int b[] = {2, 3, 4};
    assert(a != b);
    assert(equal(a, a + 3, b));
    ++b;                                         // no
    int* p = b;
    ++p;                                         // yes
    ++b[1];
    assert(equal(a, a + 3, begin({2, 3, 4})));
    assert(equal(b, b + 3, begin({2, 4, 4})));}

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

A   x[s];      // A(), s times
int x[s];      // nothing
int x[s] = {}; // O(n), guarantee zeros

array<int, s> x;      // O(n), guarantee zeros
array<int, s> x = {}; // O(n), guarantee zeros

void test11 () {
    array<int, 3> x = {2, 3, 4};
    assert(x.size() == 3);
    assert(x[1]     == 3);       // non-const [] operator
    ++x[1];                      // yes, it would the change second element
    assert(*x       == 3);       // no
    array<int, 3> y(x);          // copy constructor, O(n)
    assert( x    ==  y);         // equality,         O(n)
    assert(&x[1] != &y[1]);}

void test11 () {
    const array<int, 3> x = {2, 3, 4};
    assert(x[1]     == 3);             // const [] operator
    ++x[1];                            // no

void test12 () {
    array<int, 3> x = {2, 3, 4};
    array<int, 3> y = {5, 6, 7};
    x = y;                       // copy assignment, O(n)
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

class Ray {...}

array<Ray, 3> x; // default constructor

/*
smart array on the stack, called array
	1. copyable
	2. assignable (=)
	3. size
	4. equality (==)
*/

template <typename T, size_t N>
class array {
	private:
		T _a[N];

	public:
		array () {
			fill(_a, _a + N, T())

		array (initializer_list<T> rhs) {
			copy(begin(rhs), end(rhs), _a);}

		// don't have to do this, it'll still work, it's nice to be explicit
		array             (const array&) = default;
		array& operator = (const array&) = default;

		T* begin () {
			return _a;}

		const T* begin () const {
			return _a;}

		T* end () {
			return _a + N;}

		const T* end () const {
			return _a + N;}

		T& operator [] (size_t i) {
			++_a[i];                            // no
			return _a[i];}

		const T& operator [] (size_t i) const {
			++_a[i];                            // no
			return _a[i];}

		size_t size () {
			return N;}

void f (int p[]) {
    assert(sizeof(p) == 8); // warning: sizeof on array function parameter will return size of 'int *' instead of 'int []'
    ++p;
    ++p[0];
    ++*p;}

int s;
cin >> s; // reading an in from stdin

{
int a[s]; // no
}         // a dies

{
int* p = new int[s]; // yes
}                    // p dies, but the array does NOT

void test1 () {
    const ptrdiff_t s = 10;
    const int       v =  2;
    int*  const     a = new int[s]; // O(1), constant effort undefined
    ++a;                            // no
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    assert(count(a, a + s, v) == s);
    assert(a[1] == v);
    f(a);
    assert(a[1] == v + 2);
    delete [] a;}

void g (int* p) {
    assert(sizeof(p) == 8);
    ++p;
    ++p[0];
    ++*p;}

void test2 () {
    const ptrdiff_t s = 10;
    const int       v = 2;
    int* const      a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    assert(count(a, a + s, v) == s);
    assert(a[1] == v);
    g(a);
    assert(a[1] == v + 2);
    delete [] a;}

void test3 () {
    const size_t  s = 10;
    const int     v = 2;
    int*  const   a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* const b = a;
    assert(&a[1] == &b[1]);
    delete [] a;}

void test4 () {
    const size_t  s = 10;
    const int     v = 2;
    int*  const   a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* const x = new int[s];
    copy(a, a + s, x);
    assert(a == x);               // comparing addresses
    assert(equal(a, a + s, x));   // yes
    assert( a[1] ==  x[1]);
    assert(&a[1] != &x[1]);
    delete [] a;
    delete [] x;}

void test5 () {
    const size_t s = 10;
    const int    v =  2;
    int*  const  a = new int[s];
    assert(sizeof(a) == 8);
    fill(a, a + s, v);
    int* b = new int[s];
    fill(b, b + s, v);
//  b = a;                           // memory leak
    copy(a, a + s, b);
    assert( a[1] ==  b[1]);
    assert(&a[1] != &b[1]);
    delete [] a;
    delete [] b;}

struct A {                // sizeof(A) == 4
    int i;

    string f () {
        return "A::f";}};

struct B : A {            // sizeof(B) == 8
    int j;

    string f () {
        return "B::f";}};

/*
it's ok  to point to a single child      with a parent pointer
it's bad to point to a array of children with a parent pointer
*/

B* p = new A; // no
A* p = new B; // yes
delete p;     // no at runtime, not invoking B's destructor

int a[100];
a[5] = 6;      // going forward in memory 5 times sizeof(int)

double a[100];
a[5] = 6;      // going forward in memory 5 times sizeof(double)

void test6 () {
//  B* const a = new A[10];     // error: invalid conversion from ‘A*’ to ‘B*’
    A* const a = new B[10];     // dangerous
    assert(a[0].f() == "A::f");
//  assert(a[1].f() == "A::f"); // undefined
//  delete [] a;                // undefined
    B* b = static_cast<B*>(a);  // clang-check warning: Potential leak of memory pointed to by 'a'
    assert(b[1].f() == "B::f");
    delete [] b;}               // ~B::B() and ~A::A()

void test7 () {
    const ptrdiff_t   s = 10;
    const int         v =  2;
    unique_ptr<int[]> a(new int[s]);             // not copyable, not assignable
    fill(a.get(), a.get() + s, v);
    assert(count(a.get(), a.get() + s, v) == s);
    assert(a.get()[1] == v);
    f(a.get());
    ++*a.get();
    assert(a.get()[1] == v + 2);}

template <typename T>
class unique_ptr {
	private:
		T* _p = nullptr;

	public:
		unique_ptr (T* p) {
			_p = p;}

		// turn off copy and assignment
		unique_ptr             (const unique_ptr&) = delete;
		unique_ptr& operator = (const unique_ptr&) = delete;

		T* get () {
			return _p;}

		const T* get () const {
			return _p;}

		~unique_ptr () {
			delete _p;}};

/*
smart array on the heap, called vector
	1. automatically manage memory
	2. copyable
	3. assignable (=)
	4. size
	5. equality (==)
*/

void test8 () {
    const size_t s = 10;
    const int    v =  2;
    vector<int>  x(s, v);
    assert(x.size() == s);
    assert(x[0]     == v);
    x[0]++;
    vector<int> y(x);        // copy constructor
    assert( x    ==  y);
    assert(&x[1] != &y[1]);
    vector<int> z(2 * s, v);
    x = z;                   // copy assignment
    /*
    	x has to delete its dumb array on the heap of size 10
    	x has to build a new dumb array on the heap of size 20
    	x has to copy the 20 elements from z
    */
    assert( x    ==  z);
    assert(&x[1] != &z[1]);}

void h1 (vector<int>& y) {
    vector<int>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test9 () {
    vector<int> x = {2, 3, 4};
    h1(x);
    assert(equal(begin(x), end(x), begin({2, 5, 4})));}

void h2 (vector<int> y) {
    vector<int>::iterator p = begin(y);
    ++p;
    ++p[0];
    ++*p;}

void test10 () {
    vector<int> x = {2, 3, 4};
    h2(x);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

int* const a = new int[s];
fill(a, a + s, v);
++*a;                // increment the first element
++a;                 // no
...
delete [] a;
delete [] a;         // undefined

int* const p = new int;
...
delete p;

/*
all the mistakes you can make with delete
	1. never delete
	2. get the brackets wrong
	3. delete twice
	4. delete the wrong address
*/

/*
three ways to solve
	1. be careful with dumb arrays
	2. use vector
	3. use memory checker
*/

/*
Valgrind is a very good memory checker
	1. register all addresses with new
	2. confirm delete will all addresses
	3. the only thing it can do is run alongside a particular on a particular execution path
*/

int i = 2; // 32 bits
int j = 3; // 32 bits
i = j;
cout << (i == j); // true

T i = ...;
T j = ...;
i = j;
cout << (i == j); // true

template <typename T>
class vector {
	private:
		T* _b;
		T* _e1;
		T* _e2;
