// -----------
// Fri, 14 Aug
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
Chris
Gennadiy
Marc
*/

void test2 () {
    A            v = 3;
    my_vector<A> x(2, v);
    my_vector<A> y(x);    // this line only
    my_vector<A> z = x;   // copy contructor, too
    }

/*
Wed

dumb array on the stack
	inconsistent initialization
	can't copy
	can't assign
	inconvenient to get size

smart array on the stack: array
	consistent initialization
	can copy
	can assign
	size()

dumb array on the heap
	inconsistent initialization
	can't copy
	can't assign
	can't size
	manual memory management (somewhat address with Valgrind)

unique_ptr
	can't copy
	can't assign
	can't size
	automatic memory management

vector
	consistent initialization
	can copy
	can assign
	size()
	automatic memory management
*/

void test1 () {
	A   x(2);
    int i(2);
    assert(i == 2);

	A   y = 2;
    int j = 2;
    assert(j == 2);

    int k{2};
    assert(k == 2);

    int l = {2};
    assert(l == 2);}



void test2 () {
    int i(2.0);
    assert(i == 2);

    int j = 2.0;
    assert(j == 2);

//  int k{2.0};     // error: narrowing conversion of '2.0e+0' from 'double' to 'int'

//  int l = {2.0};  // error: narrowing conversion of '2.0e+0' from 'double' to 'int'
    }


struct A {
	int i;} // by default, public

class A {
	int i;} // by default, private

struct A3 {
    int i;
    int j;};

A3()
~A3()
A3(const A3&)
A3& operator = (const A3&)

void test3 () {
//  A3 x(2, 3);    // error: no matching function for call to 'A1::A1(int, int)'

    A3 z{2, 3};
    assert(&z);

    A3 t = {2, 3};
    assert(&t);}



struct A4 {
    int i;
    int j;

    A4 (int, int)
        {}};

void test4 () {
    A4 x(2, 3);
    assert(&x);

    A4 z{2, 3};
    assert(&z);

    A4 t = {2, 3};
    assert(&t);}

void f (string t) {
	...}

string s("abc"); // string(const char*),  explicitly; string s = "abc"
f(s);            // string(const string&)
f("abc");        // string(const char*),  implicitly

void f (vector<int> y) {
	...}

vector<int> x(10000); // explicit vector(size_t); vector<int> x = 10000; // NO
f(x);                 // vector(const vector&)
f(10000);             // NO


struct A5 {
    int i;
    int j;

    explicit A5 (int, int)
        {}};

void test5 () {
    A5 x(2, 3);
    assert(&x);

    A5 z{2, 3};
    assert(&z);

//  A5 t = {2, 3}; // error: converting to 'B' from initializer list would use explicit constructor 'B::B(int, int)'
    }



struct A6 {
    int i;
    int j;

    A6 (initializer_list<int>)
        {}};

void test6 () {
//  A6 x(2, 3);    // error: no matching function for call to 'A6::A6(int, int)'

    A6 z{2, 3};
    assert(&z);

    A6 t = {2, 3};
    assert(&t);}



struct A7 {
    int i;
    int j;

    explicit A7 (initializer_list<int>)
        {}};

void test7 () {
//  A7 x(2, 3);   // error: no matching function for call to 'D::D(int)'

    A7 z{2, 3};
    assert(&z);

//  A7 t = {2, 3}; // error: converting to 'D' from initializer list would use explicit constructor 'D::D(std::initializer_list<int>)'
    }



struct A8 {
    int i;
    int j;

    A8 (int)
        {}

    A8 (initializer_list<int>)
        {}

    bool operator == (const A8&) {
    	return true;}};

void test8 () {
    A8 x(2);     // A8(int)
    assert(&x);

    A8 y = 2;    // A8(int)
    assert(&y);

    A8 z{2};     // A8(initializer_list<int>)
    assert(&z);

    A8 t = {2};  // A8(initializer_list<int>)
    assert(&t);}



void test9 () {
    vector<int> x(2);                               // explicit vector<int>(int)
    assert(x.size() == 2);
    assert(equal(begin(x), end(x), begin({0, 0})));

//  vector<int> y = 2;                              // error: conversion from 'int' to non-scalar type 'std::vector<int>' requested

    vector<int> z{2};                               // vector<int>(initializer_list<int>)
    assert(z.size() == 1);
    assert(equal(begin(z), end(z), begin({2})));

    vector<int> t = {2};                            // vector<int>(initializer_list<int>)
    assert(t.size() == 1);
    assert(equal(begin(t), end(t), begin({2})));}

template <typename T, size_t N>
struct my_array {
    friend bool operator == (const my_array& lhs, const my_array& rhs) {
        return equal(lhs.begin(), lhs.end(), rhs.begin());}

    T _crazy_hidden_name[N];

    my_array             ()                = default;
    my_array             (const my_array&) = default;
    my_array& operator = (const my_array&) = default;
    ~my_array            ()                = default;

    T& operator [] (size_t i) {
        return _a[i];}

    const T& operator [] (size_t i) const {
        return _a[i];}

    T* begin () {
        return _a;}

    const T* begin () const {
        return _a;}

    T* end () {
        return _a + N;}

    const T* end () const {
        return _a + N;}

    size_t size () const {
        return N;}};

//  my_array<int, 3> x = {2, 3, 4, 5}; // error: too many initializers for 'my_array<int, 3>'

void test1 () {
    my_array<int, 3> x;
    assert(x.size() == 3);}

void test2 () {
    my_array<int, 3> x = {};
    assert(x.size() == 3);}

void test3 () {
    my_array<int, 3> x = {2};
    assert(x.size() == 3);}

void test4 () {
//  my_array<int, 3> x = {2, 3, 4, 5}; // error: too many initializers for 'my_array<int, 3>'
    my_array<int, 3> x = {2, 3, 4};
    assert(x[1] == 3);
    x[1] = 5;
    assert(x[1] == 5);}

void test5 () {
    const my_array<int, 3> x = {2, 3, 4};
    assert(x[1] == 3);
//  x[1] = 5;                             // error: assignment of read-only location 'x.my_array<int, 3>::operator[](1)'
    assert(x[1] == 3);}

void test6 () {
    const my_array<int, 3> x = {2, 3, 4};
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

void test7 () {
    my_array<int, 3>       x = {2, 3, 4};
    const my_array<int, 3> y = x;
    assert(&*begin(x) != &*begin(y));
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}

void test8 () {
    const my_array<int, 3> x = {2, 3, 4};
    my_array<int, 3>       y = {5, 6, 7};
    y = x;
    assert(&*begin(x) != &*begin(y));
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}

void test9 () {
    const my_array<int, 5> x = {2, 3, 4, 5, 6};
    const my_array<int, 5> y = {2, 3, 4, 5, 6};
    assert(  x == y);
    assert(!(x != y));}

void test10 () {
    const my_array<int, 5> x = {2, 3, 4, 5, 6};
    const my_array<int, 5> y = {2, 3, 4, 5, 7};
    assert(  x != y);
    assert(!(x == y));}

class string {
	friend bool operator == (const string&, const string&);

	private:
		char* _a;
	...
//	bool operator == (const string& rhs) const { // method === member function
//		// we have access to _a
	}

bool operator == (const string& lhs, const string& rhs) { // non-member function
	// we do not have acces to _a
	// with friend declaration in string, we do have access to _a

class iker {
	}

class string {
	friend bool operator == (const string& lhs, const string& rhs) {
		// we do not have acces to _a
		// with friend declaration in string, we do have access to _a

	private:
		char* _a;
	...
	}

/*
== is an example of a symmetric operator
other symmetric operators are:
!=, <, >, <=, >=, +, -, *, /, %
all symmetric should be friend functions
*/

const string s = "abc";  // implicit
const string t = "abc";
cout << (s == t);        // true
cout << s.operator==(t); // true, NOT the ONLY rewrite

cout << (s == "abc");        // true
cout << s.operator==("abc");

cout << ("abc" == t);        // no
cout << "abc".operator       // NO

cout << ("abc" == "abc");     // char* ==, this usually isn't what we want, address comparison
cout << strcmp("abc", "abc");

/*
builtin types
int
float
char
T*
*/

cout << (s == t);
cout << s.operator==(t);  // no
cout << operator==(s, t); // YES

cout << (s == "abc");         // yes
cout << operator==(s, "abc");

cout << ("abc" == t);         // yes
cout << operator==("abc", t);


/*
function or method overloading
change the number of arguments or the types of arguments
*/

void g (int);
void g (float);
void g (int, int)

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


struct A {
    int c = 0; // many cs, one c for each instance of A

    A () {
        ++c;}

    ~A () {
        --c;}};

A x;
A y;
cout << (&(x.c) == &(y.c)); // false

struct A {
    static int c = 0; // only one c that is shared among all instances of A

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c; // the definition of the only c

A x;
A y;
cout << (&(x.c) == &(y.c)); // true

template <typename T>
class unique_ptr {
	private:
		T* _p = nullptr;
	public:
		unique_ptr () = default;

		explicit unique_ptr (T* p) {
			_p = p;}

        unique_ptr (my_unique_ptr&& rhs) { // move constructor
//        	_p = rhs._p;
//       	rhs._p = nullptr;
			swap(_p, rhs._p);}

		unique_ptr& operator = (const unique_ptr&& rhs) { // move assignment
			if (this == &rhs)
				return *this;
//			delete _p;
//			_p = rhs._p;
//			rhs._p = nullptr;
//			unique_ptr that(rhs);       // copy constructor, turned off!!!
			unique_ptr that(move(rhs)); //
			swap(_p, that._p);
			// inside of a non-static method (non-static member function)
			// this is a pointer to the object that the method is invoked on
			return *this;}

		// turn off copy and assignment
		unique_ptr             (const unique_ptr&) = delete;
		unique_ptr& operator = (const unique_ptr&) = delete;

		~unique_ptr () { // destructor
			delete _p;}};

/*
whenever possible try to reuse code
*/

unique_ptr<A> x(new A);
unique_ptr<A> y(x);          // x is an l-value, this is the copy constructor, which is turned off
unique_ptr<A> z(<r-value A>) // this is the move constructor

unique_ptr<A>& foo = x;
x = move(foo);
x.operator=(move(foo)); // this -> x; rhs -> foo

y = move(foo);
y.operator=(move(foo)); // this -> y; rhs -> foo

int i = 2;
int j = 3;
i = j;
int  k = (i = j);
int& r = (i = j); // r becomes an alias for i

void test0 () {
    assert(A::c == 0);
    my_unique_ptr<A> x;         // default constructor
    assert(A::c    == 0);
    assert(x.get() == nullptr);}

void test1 () {
    assert(A::c == 0);
    {
//  my_unique_ptr<A> x = new A; // error: conversion from 'A*' to non-scalar type 'my_unique_ptr<A>' requested
    my_unique_ptr<A> x(new A);  // pointer constructor
    assert(A::c    == 1);
    assert(x.get() != nullptr);
    }
    assert(A::c == 0);}

void test2 () {
    assert(A::c == 0);
    {
    my_unique_ptr<A> x(new A);
    assert(A::c    == 1);
//  my_unique_ptr<A> y = x;       // error: use of deleted function 'my_unique_ptr<T>::my_unique_ptr(const my_unique_ptr<T>&) [with T = A]'
    my_unique_ptr<A> y = move(x); // move constructor, move() moves nothing, move casts to an r-value
    assert(A::c    == 1);
    assert(x.get() == nullptr);
    assert(y.get() != nullptr);
    }
    assert(A::c == 0);}

void test3 () {
    assert(A::c == 0);
    {
    my_unique_ptr<A> x(new A);
    my_unique_ptr<A> y(new A);
    assert(A::c == 2);
//  y = x;                      // error: use of deleted function 'my_unique_ptr<T>& my_unique_ptr<T>::operator=(const my_unique_ptr<T>&) [with T = A]'
    y = move(x);                // move assignment operator
    assert(x.get() == nullptr);
    assert(y.get() != nullptr);
    assert(A::c    == 1);
    }
    assert(A::c == 0);}

class A {
	private:
		int i = 0;

	public:
		bool operator == (const A& rhs) const {
			return i == rhs.i;}

		void f () { // you have access to all of the data of any object of that class
			++i;
			A y;
			++y.i;  // yes

};

A x;
cout << x.i; // no
x.f();




struct A {
    A () = default;

    A (const A&) {               // copy constructor
        cout << "A(const A&) ";}

    A& operator = (const A&) {   // copy assignment
        cout << "=(const A&) ";
        return *this;}};



A f () {
    A x;
    return x;}



void test1 () {
    cout << "1. A copy constructor: ";
    A x;
    A y = x;                           // l-value, A(const A&)
    assert(&y);}

void test2 () {
    cout << "2. A copy elision ";
    A y = f();                         // r-value
    assert(&y);}

void test3 () {
    cout << "3. A copy assignment: ";
    A x;
    A y;
    y = x;}                            // l-value, =(const A&)

void test4 () {
    cout << "4. A copy assignment: ";
    A y;
    y = f();}                          // r-value, =(const A&)



struct B {
    B () = default;

    B (const B&) {               // copy constructor
        cout << "B(const B&) ";}

    B (B&&) {                    // move constructor
        cout << "B(B&&) ";}

    B& operator = (const B&) {   // copy assignment
        cout << "=(const B&) ";
        return *this;}

    B& operator = (B&&) {        // move assignment
        cout << "=(B&&) ";
        return *this;}};



B g () {
    B x;
    return x;}



void test5 () {
    cout << "5. B move constructor: ";
    B x;
    B y = move(x);                     // l-value, B(B&&)
    assert(&y);}

void test6 () {
    cout << "6. B copy/move elision ";
    B y = g();                         // r-value
    assert(&y);}

void test7 () {
    cout << "7. B move assignment: ";
    B x;
    B y;
    y = move(x);}                      // r-value, =(B&&)

void test8 () {
    cout << "8. B move assignment: ";
    B y;
    y = g();}                          // r-value, =(B&&)

/*
overview of the STL containers and how they behave
*/

/*
vector
front-loaded array
1. cost of adding to the back       ~O(1), amortized constant
2. cost of adding to the front      O(N),  linear
3. cost of adding to the middle     O(N),  linear
4. cost of removing from the back   O(1),  constant
5. cost of removing from the front  O(N),  linear
6. cost of removing from the middle O(N),  linear
7. cost of indexing                 O(1),  constant
*/

vector<int> x(10, 2);               // size 10, filled with 2s
cout << x.size();                   // 10
cout << x.capacity();               // 10
vector<int>::iterator b = begin(x);
cout << *b;                         // 2
x.push_back(3);
cout << x.size();                   // 11
cout << x.capacity();               // 20
cout << *b;                         // undefined!!!!!!!

/*
vector is asymmetric, the front is expensive, the back is cheap
vector does NOT have pop_front() or push_front()
when vector grows, it invalidates iterators, pointers, and references

*/

/*
list
doubly-linked list, it has pointers to the first and last node
1. cost of adding to the back       O(1),  constant
2. cost of adding to the front      O(1),  constant
3. cost of adding to the middle     O(1),  constant // if they gave us a pointer to the middle
4. cost of removing from the back   O(1),  constant
5. cost of removing from the front  O(1),  constant
6. cost of removing from the middle O(1),  constant // if they gave us a pointer to the middle
7. cost of indexing                 not available!!!!
*/

/*
list is symmetric
list has both push_front(), push_back(), pop_front(), pop_back, but NO []
when list grows, it does NOT invalidate iterators, pointers, and references
*/

/*
deque
middle-loaded array of arrays!!!
1. cost of adding to the back       ~O(1), amortized constant
2. cost of adding to the front      ~O(1), amortized constant
3. cost of adding to the middle     O(N),  linear
4. cost of removing from the back   O(1),  constant
5. cost of removing from the front  O(1),  constant
6. cost of removing from the middle O(N),  linear
7. cost of indexing                 more expensive than vector, need a divide and a mod
*/

/*
deque is symmetric
deque has both push_front(), push_back(), pop_front(), pop_back, [] is a little more expensive
[] needs a divide and a mod
when deque grows, it does NOT invalidate iterators, pointers, and references
*/
