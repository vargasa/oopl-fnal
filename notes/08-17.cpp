// -----------
// Mon, 17 Aug
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
Glenn
Kyle
Marc
Matti
*/

template <typename T>
class A {
    private:
        T _v;

    public:
        A (const T& v) :
            _v (v)
            {}

        bool operator == (const A& rhs) const {
            return _v == rhs._v;}};

void f () {
    A<int> x = 2;
    cout << (x == 2)        << " ";
    cout << x.operator==(2) << endl;

    cout << (2 == x) << endl;
    cout << 2.                // no

int i;
int j = 2;

struct A {
	int _i;

	A (int i) {
		_i = i;}}; // int assignment

A x(2);  // A(int)
A y = 3; // A(int)

struct A {
	const int _i;

	A (int i) {
		_i = i;}}; // no

	A (int i) :    // member initialization list, only in constructor for initialization
		_i(i)
		{}};

A x(2);  // A(int)
A y = 3; // A(int)

struct A {
	int& _i;

	A (int i) {
		_i = i;}}; // no

	A (int i) :    // member initialization list, only in constructor for initialization
		_i(i)
		{}};

A x(2);  // A(int)
A y = 3; // A(int)

struct B {
	B () = delete;};

struct A {
	B _x;

	A (B x) {
		_x = x;}}; // no

	A (B x) :      // member initialization list, only in constructor for initialization
		_x(x)
		{}};

struct B {};

/*
B()
B(const B&)
=(const B&)
~B()
*/

struct A {
	B _x;

	A (B x) {      // B()
		_x = x;}}; // =(const B&)

	A (B x) :      // member initialization list, only in constructor for initialization
		_x(x)      // B(const B&)
		{}};

/*
containers
*/

/*
overview of the STL containers and how they behave
*/

/*
vector
front-loaded array
best at indexing
1. cost of adding to the back       ~O(1), amortized constant
2. cost of adding to the front      O(N),  linear
3. cost of adding to the middle     O(N),  linear
4. cost of removing from the back   O(1),  constant
5. cost of removing from the front  O(N),  linear
6. cost of removing from the middle O(N),  linear
7. cost of indexing                 O(1),  constant
*/

/*
list
doubly-linked list, it has pointers to the first and last node
best at insertions/deletions in the middle cheap
1. cost of adding to the back       O(1),  constant
2. cost of adding to the front      O(1),  constant
3. cost of adding to the middle     O(1),  constant // if they gave us a pointer to the middle
4. cost of removing from the back   O(1),  constant
5. cost of removing from the front  O(1),  constant
6. cost of removing from the middle O(1),  constant // if they gave us a pointer to the middle
7. cost of indexing                 not available!!!!
*/

/*
deque
middle-loaded array of arrays!!!
best at growing
1. cost of adding to the back       ~O(1), amortized constant
2. cost of adding to the front      ~O(1), amortized constant
3. cost of adding to the middle     O(N),  linear
4. cost of removing from the back   O(1),  constant
5. cost of removing from the front  O(1),  constant
6. cost of removing from the middle O(N),  linear
7. cost of indexing                 more expensive than vector, need a divide and a mod
*/

template <typename T, typename C = deque<T>>
class stack {
	private:
		C _c};

/*
stack, a container adapter
LIFO: last in, first out
push  -> push_back
pop   -> pop_back
top   -> back,     returns T& and const T&
size  -> size
empty -> empty
*/

stack<int> x;              // what backing container by default? deque
stack<int, vector<int>> y;
stack<int, deque<int>>  z;
stack<int, list<int>>   t;

template <typename T, typename C = deque<T>>
class queue {
	private:
		C _c};

/*
queue, a container adapter
FIFO: first in, first out
push  -> push_back
pop   -> pop_front
front -> front     returns T& and const T&
back  -> back      returns T& and const T&
size  -> size
empty -> empty
*/

queue<int> x;              // what backing container by default? deque
queue<int, vector<int>> y; // no
queue<int, deque<int>>  z;
queue<int, list<int>>   t;

template <typename T, typename C = vector<T>>
class priority_queue {
	private:
		C _c};

/*
priority_queue, a container adapter
FIFO: first in, first out
push  -> push_back (more work)
pop   -> pop_front (more work)
top   -> back      (more work), only returns const T&
size  -> size
empty -> empty
*/

priority_queue<int> x;              // what backing container by default? vector
priority_queue<int, vector<int>> y;
priority_queue<int, deque<int>>  z;
priority_queue<int, list<int>>   t; // no

/*
set           (binary tree)
unordered_set (hashtable)
a bunch of keys
no duplicate keys
insert,       can't insert a duplicate key
remove
find          only returns const K&
*/

/*
map           (binary tree)
unordered_map (hashtable)
a bunch of keys and values
no duplicate keys, but we can have duplicate values
insert,       can't insert a duplicate key
remove
find          only returns const K&, V& and const K&, const V&
*/

void test1 () {
    int i = 0;
    int s = 0;
    while (i != 10) { // might not execute the body
        s += i;
        ++i;}
    assert(i == 10);
    assert(s == 45);}

void test2 () {
    int i = 0;
    int s = 0;
    do {              // executes body at least once
        s += i;
        ++i;}
    while (i != 10);
    assert(i == 10);
    assert(s == 45);}

for (int i = 0; i != 10; ++i)
	s += i;

{
int i = 0;
while (i != 10) {
	s += i;
	++i;}
}

void test3 () {
    int s = 0;
    for (int i = 0; i != 10; ++i)
        s += i;
//  assert(i == 10);              // error: name lookup of 'i' changed for new ISO 'for' scoping
    assert(s == 45);}

void test4 () {
    const int a[] = {2, 3, 4};
    const int b[] = {5, 6, 7};
    int s = 0;
    for (int i = 0, j = 0; i != 3; ++i, ++j)
        s += a[i] + b[j];
    assert(s == 27);}

Ram<int> x(...);

for (int v : x) { what does Ram need to have
	???}

Ram<int>::iterator b = begin(x);
Ram<int>::iterator e = end(x);
while (b != e) {
	int v = *b;
	???
	++b;}

void test5 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int v : a)      // for each loop
        s += v;
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test6 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int v : a) {                           // v is a copy of the element
        s += v;
        ++v;}                                   // ?
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test7 () {
    int  a[] = {2, 3, 4};
    int  s   = 0;
    int* b   = begin(a);
    int* e   = end(a);
    while (b != e) {
        int v = *b;                             // v is a copy of the element
        s += v;
        ++v;                                    // ?
        ++b;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test8 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (auto v : a) {
        s += v;
        ++v;}                                   // ?
    assert(s == 9);
    assert(equal(a, a + 3, begin({2, 3, 4})));}

void test9 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (int& r : a) {
        s += r;
        ++r;}                                   // r is NOT a copy
    assert(s == 9);
    assert(equal(a, a + 3, begin({3, 4, 5})));}

void test10 () {
    int a[] = {2, 3, 4};
    int s   = 0;
    for (auto& r : a) {
        s += r;
        ++r;}
    assert(s == 9);
    assert(equal(a, a + 3, begin({3, 4, 5})));}

void test11 () {
    list<int> x = {2, 3, 4};
    int       s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

template <typename T>
struct Yujing {
	struct iterator {
		...}
	iterator begin () {
		...}
	iterator end () {
		...}};

Yujing<int> x(...);
for (int v : x) {
	???}

Yujing<int>::iterator b = begin(x); // x.begin();

void test12 () {
    list<int>           x = {2, 3, 4};
    int                 s = 0;
    list<int>::iterator b = begin(x);           // x.begin()
    list<int>::iterator e = end(x);             // x.end()
    while (b != e) {
        list<int>::iterator::value_type v = *b;
        s += v;
        ++b;}
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test13 () {
    set<int> x = {2, 3, 4};
    int      s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test14 () {
    set<int>           x = {2, 3, 4};
    int                s = 0;
    set<int>::iterator b = begin(x);           // x.begin()
    set<int>::iterator e = end(x);             // x.end()
    while (b != e) {
        set<int>::iterator::value_type v = *b;
        s += v;
        ++b;}
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test15 () {
    set<int> x = {2, 3, 4};
    int      s = 0;
//  for (      int& r : x)                              // error: binding reference of type 'int&' to 'const int' discards qualifiers
    for (const int& r : x)
        s += r;
    assert(s == 9);
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

pair<int, int> p(2, 3);
cout << p.first;        // 2
cout << p.second;       // 3

void test16 () {
    map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int            s = 0;
    for (pair<char, int> v : x)
        s += v.second;
    assert(s == 9);}

void test17 () {
    map<char, int>           x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int                      s = 0;
    map<char, int>::iterator b = begin(x);                       // x.begin()
    map<char, int>::iterator e = end(x);                         // x.end()
    while (b != e) {
        map<char, int>::iterator::value_type v = *b;
        s += v.second;
        ++b;}
    assert(s == 9);}

void test18 () {
    map<char, int> x = {{'a', 2}, {'b', 3}, {'c', 4}};
    int            s = 0;
//  for (pair<      char, int>& p : x)                 // error: non-const lvalue reference to type 'pair<char, [...]>' cannot bind to a value of unrelated type 'const pair<__key_type, [...]>'
    for (pair<const char, int>& p : x)
        s += p.second;
    assert(s == 9);}

/*
2 3 4 // you don't want a space after the 4
*/

void test19 () {
    ostringstream     out;
    const vector<int> x = {2, 3, 4};
    for (size_t i = 0; i != x.size(); ++i)
    	out << x[i] << " ";                        // a space after 4
        out << x[i] << " \n"[i == (x.size() - 1)]; // no space after 4
    assert(out.str() == "2 3 4\n");}



/*
transform is a lot like copy
*/

template <typename II, typename OI>
OI copy (II b1, II e1, OI b2) {
    while (b1 != e1) {
        *b2 = *b1;
        ++b1;
        ++b2;}
    return b2;}

template <typename II, typename OI, typename UF>
OI transform (II b1, II e1, OI b2, UF f) {       // UF has to be a unary function
    while (b1 != e1) {
        *b2 = f(*b1);
        ++b1;
        ++b2;}
    return b2;}

int pow1 (int n) {
    return pow(n, 2);}

void test1 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
//    vector<int>::iterator     p = copy(b, e, x);
    vector<int>::iterator     p = transform(b, e, x, pow1);      // pow1 has to be a unary function
    /*
    II -> list<int>::const_iterator
    OI -> vector<int>::iterator
    UF -> int (*) (int) in C; function<int (int)> in C++
    */
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





template <typename T>
T pow2 (T n) {
    return pow(n, 2);}

void test2 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    vector<int>::iterator     p = transform(b, e, x, pow2<int>);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





int pow1 (int n) {
    return pow(n, 2);}

/*
unfortunately there is no lambda type that we can use
there is an implementation dependent lambda type
*/

void test3 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    auto                      f = [] (int n) -> int {return pow(n, 2);}; // a lambda expression
    int (*f) int                = [] (int n) -> int {return pow(n, 2);}; // yes, sometimes ok
    function<int (int)>       f = [] (int n) -> int {return pow(n, 2);}; // yes, expensive in space
    vector<int>::iterator     p = transform(b, e, x, f);
    assert(p == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





auto pow4 (int& p) {
    return [p] (int n) -> int {return pow(n, p);};} // a closure by value

void test4 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       p = 2;
    auto                      f = pow4(p);
    ++p;
    vector<int>::iterator     q = transform(b, e, x, f);
    assert(q == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





auto pow5 (int& p) {
    return [&p] (int n) -> int {return pow(n, p);};} // a closure by reference

void test5 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       p = 1;
    auto                      f = pow5(p);
    ++p;
    vector<int>::iterator     q = transform(b, e, x, f);
    assert(q == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}



/*
function object
*/

class pow6 {
    private:
        int _p;        // same as a closure by value

    public:
        pow6 (int p) :
                _p (p) // didn't have to use the member initialization list
            {}

        int operator () (int n) const {
            return pow(n, _p);};};

pow6 f(2);
cout << f(5); // 25

cout << pow6(5);    // no
cout << pow6(2)(5); // 25

void test6 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       p = 2;
    auto                      f = pow6(p);
    ++p;
    vector<int>::iterator     q = transform(b, e, x, f);
    assert(q == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}





class pow7 {
    private:
        int& _p;        // same as a closure by reference

    public:
        pow7 (int& p) :
                _p (p)  // have to use the member initialization list
            {}

        int operator () (int n) const {
            return pow(n, _p);};};

void test7 () {
    const list<int>           ix = {2, 3, 4};
    vector<int>               oy(5);
    list<int>::const_iterator b = begin(ix);
    list<int>::const_iterator e = end(ix);
    vector<int>::iterator     x = begin(oy) + 1;
    int                       p = 1;
    auto                      f = pow7(p);
    ++p;
    vector<int>::iterator     q = transform(b, e, x, f);
    assert(q == begin(oy) + 4);
    assert(equal(begin(oy), end(oy), begin({0, 4, 9, 16, 0})));}

struct A {
	int i;}   // non-static data member, one per instance

cout << A::i; // no

A x;
A y;
cout << (&(x.i) == &(y.i)); // false

template <typename T>
struct A {
    int iv = 0;};

void test () {
//  assert(A<int>::iv == 0); // error: invalid use of non-static data member 'A<int>::iv'

    A<int> x;
    assert(x.iv == 0);

    A<int> y;
    assert(y.iv == 0);

    assert(&x.iv != &y.iv);}

struct A {
	static int i;} // static data member, one per class, only declares it

int A::i = 0;      // defines it, automatically initialized to zero for built in types
				   // default constructs user types

cout << A::i;      // yes

template <typename T>
struct A {
    static int cv;};   // static data member, one per T

template <typename T>
int A<T>::cv = 0;

void test () {
    assert(A<int>::cv  == 0);
    assert(&A<int>::cv != &A<double>::cv);

    A<int> x;
    A<int> y;
    assert(&x.cv == &y.cv);}

template <typename T>
struct A {
    T        iv = 0; // this would require 0 to be a valid value for T
    static T cv;     // only declares

    void im () {     // method, member function, non-static, needs an instance
        ++iv;
        ++cv;

		// this is a pointer
		cout << this.iv;     // no
		cout << *this.iv;    // no, . has a higher precedence than *
		cout << (*this).iv;  // yes
		cout << this->iv;    // yes

        assert(&iv == &this->iv); // &(this->iv); -> has a higher precedence than &
        assert(&cv == &this->cv);

        cim();
        cm();}

    void cim () const
        {}

    static void cm ()
        {}

    static void foo () const // no
    	{}

template <typename T>
T A<T>::cv = 0;       // defines, also requires 0 to be a valid value for T

void test () {
//  A<int>::im(); // error: cannot call member function 'void A<T>::im() [with T = int]' without object

    A<int> x;
    assert(x.iv == 0);
    assert(x.cv == 0);

    x.im();            // this -> x
    assert(x.iv == 1);
    assert(x.cv == 1);

	A<int> z;
	z.im();            // this ->z

    const A<int> y;
//  y.im();         //  error: passing 'const A<int>' as 'this' argument discards qualifiers
    }

template <typename T>
struct A {
    T        iv = 0;
    static T cv;

    void im ()
        {}

    void cim () const
        {}

    static void cm () {           // static member function, does NOT need an instance
//      ++iv;                     // error: invalid use of member 'A<T>::iv' in static member function
        ++cv;

//      assert(&cv == &this->cv); // error: 'this' is unavailable for static member functions
//      im();                     // error: cannot call member function 'void A<T>::im() [with T = int]' without object
//      cim();                    //  error: cannot call member function 'void A<T>::cim() const [with T = int]' without object
        }};

template <typename T>
T A<T>::cv = 0;

void test () {
    assert(A<int>::cv == 0);

    A<int>::cm();            // invoking a static method with no instance
    assert(A<int>::cv == 1);

    A<int> x;
    x.cm();                  // sometimes in a template this might be useful
    assert(A<int>::cv == 2);

    const A<int> y;
    y.cm();
    assert(A<int>::cv == 3);}

template <typename T>
struct A {
    T        iv = 0;
    static T cv;

    void im ()
        {}

    void cim () const { // non-static, need an instance
//      ++iv;           // error: increment of member 'A<int>::iv' in read-only object
        ++cv;

//      im();           // error: passing 'const A<int>' as 'this' argument discards qualifiers [-fpermissive]
        cm();}

    static void cm ()
        {}};

template <typename T>
T A<T>::cv = 0;

void test1 () {
//  A<int>::cim(); // error: cannot call member function 'void A<T>::cim() const [with T = int]' without object

    A<int> x;
    assert(x.iv == 0);
    assert(x.cv == 0);

    x.cim();
    assert(x.iv == 0);
    assert(x.cv == 1);

    const A<int> y;
    y.cim();}

template <typename T>
class B {
    private:
        T _v;

    public:
        B (const T& v) :
            _v (v)
            {}

        T& get () {
            return _v;}

        const T& get () const {
            return _v;}};

void test2 () {
    B<int> x = 2;
    assert(x.get() == 2);
    x.get() = 3;
    const B<int> y = 3;
    assert(y.get() == 3);
//  y.get() = 4;          // error: assignment of read-only location 'y.B<int>::get()'
    }


template <typename T>
class my_complex {
	friend T real (...) {
		...}

	friend T imag (...) {
		...}

	friend my_complex conj (my_complex) {
		...}

	friend bool operator == (my_complex, my_complex) {
		...}

	friend my_complex operator + (my_complex, my_complex) {
		...}

	private:
		T _real;
		T _imag;

	public:
		my_complex ()     {...}
		my_complex (T)    {...}
		my_complex (T, T) {...}

		? operator += (my_complex)
	}

struct A {};

/*
A()
A(const A&)
=(const A&)
~A()
*/

#ifdef TEST0
void test0 () {
    const my_complex<int> x; // default constructor
    assert(real(x) == 0);    // it doesn't say x.real() == 0
    assert(imag(x) == 0);
    }
#endif

#ifdef TEST1
void test1 () {
    const my_complex<int> x = 2; // one-arg constructor
    assert(real(x) == 2);
    assert(imag(x) == 0);}
#endif

#ifdef TEST2
void test2 () {
    const my_complex<int> x(2, 3); // two-arg constructor
    assert(real(x) == 2);
    assert(imag(x) == 3);}
#endif

#ifdef TEST3
void test3 () {
    const my_complex<int> x(2, 3);
    assert(x == my_complex<int>(2, 3));  // equality   operator
    assert(x != my_complex<int>(4, 5));} // inequality operator
#endif

#ifdef TEST4
void test4 () {
    const my_complex<int> x = 2;
    assert(x == 2);  // x.operator==(2); // no; operator==(x, 2)
    assert(2 == x);} // 2.operator==(x); // no; operator==(2, x)
#endif

#ifdef TEST5
void test5 () {
    const my_complex<int> x(2, 3);
    my_complex<int>       y = x;   // copy constructor
    assert(x == y);}
#endif

#ifdef TEST6
void test6 () {
    my_complex<int>       x(2, 3);
    const my_complex<int> y(4, 5);
    my_complex<int>&      z = (x = y);   // copy assignment operator
    assert(z  == my_complex<int>(4, 5));
    assert(&x == &z);}
#endif

#ifdef TEST7
void test7 () {
    my_complex<int>       x(2, 3);
    const my_complex<int> y(4, 5);
    my_complex<int>&      z = (x += y);   // in-place plus operator; x.operator+=(y)
    assert(z  == my_complex<int>(6, 8));
    assert(&x == &z);}
#endif

#ifdef TEST8
void test8 () {
    const my_complex<int> x(2, 3);
    const my_complex<int> y(4, 5);
    const my_complex<int> z = (x + y);    // plus operator; operator+(x, y)
    assert(z == my_complex<int>(6, 8));}
#endif

#ifdef TEST9
void test9 () {
    const my_complex<int> x(2, 3);
    const my_complex<int> y = conj(x);    // conjugation
    assert(x == my_complex<int>(2,  3));
    assert(y == my_complex<int>(2, -3));}
#endif

template <typename T>
class my_complex {
    friend bool operator == (const my_complex& lhs, const my_complex& rhs) {
        return (lhs._r == rhs._r) && (lhs._i == rhs._i);}

    friend T real (const my_complex& v) {
        return v._r;}

    friend T imag (const my_complex& v) {
        return v._i;}

    friend my_complex operator + (my_complex lhs, const my_complex& rhs) {
        return lhs += rhs;}

    friend my_complex conj (my_complex v) {
        return {v._r, -v._i};}

    private:
        T _r = T();
        T _i = T();

    public:
        my_complex () = default;

        my_complex (const T& r) :
                _r (r)
            {}

        my_complex (const T& r, const T& i) :
                _r (r),
                _i (i)
            {}

        my_complex             (const my_complex&) = default;
        my_complex& operator = (const my_complex&) = default;
        ~my_complex            ()                  = default;

        my_complex& operator += (const my_complex& rhs) {
            _r += rhs._r;
            _i += rhs._i;
            return *this;}};
