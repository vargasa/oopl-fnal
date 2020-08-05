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
l-value is strong than r-value
*/

++2; // no, r-value is not strong enough

++++i; // yes, l-value must be coming out

x = y;
x = 2;
2 = x; // no
2 = 3; // no

++i = 2; // yes
i++ = 2; // no

int f () {
	return 2;}

f() = 2; // no

/*
the Canvas     quizzes   will have no password after the class
the HackerRank exercises will always have a password of 1234 after the class
	you need a new e-mail every time

Tue/Thu, 2-3pm, I'll have Zoom office hours
I'll put the link in the Slack

make sure you're on Canvas
make sure you're on Slack

these notes will always be on GitLab after the class
*/

/*
values, pointers, references
two tokens:   *, &
two contexts: next to a type, next to a variable
*/

int i = 2;
int v = i;
++v;
cout << i; // 2

int  i = 2;
int* p = i;  // no
int* p = &i; // yes
int* q = &2; // no

float f = 3.4;
int*  r = &f;  // no

cout << p;  // the address of i
cout << *p; // the value   of i: 2
cout << *i; // no
cout << *2; // no

int j = *p; // yes

*p = 3;    // yes, * is returning an l-value
cout << i; // 3

int k = 4;
p  = &k;
p  = k;    // no
*p = &k;   // no

++*p;
cout << k; // 5

float f = 3.4;
p = &f;        // no

int* p, q; // I never do that
int *p, q;

int i;
cout << i; // random value

int* p;
cout << p; // random value

int  i = 2;
int* p = &i;
++*p
cout << i;   // 3
++p;         // yes, but crazy
cout << *p;  // undefined

void f (int* p) {
	++*p;}

int i = 2;
f(&i);
cout << i; // 3

int j = 2;
f(&j);

void f (int i) {
	++i;}

int i = 2;
f(i);
cout << i; // 2

int  i = 2;
int& r = &i; // no
int& r = i;  // yes, this is a reference, r becomes an alias for i
int& r = 2;  // no,  must be an l-value

int  j = 3;
int& s = ++j; // yes
int& t = j++; // no

r = 3;
cout << i; // 3

cout << (&i == &r); // true

/*
no way to associate r with a different int, later
*/

void f (int v) {
	++v;}

int i = 2;
f(i);
cout << i; // 2

void g (int* p) {
	++p;}         // legal, but crazy

int j = 3;
g(j);      // no
g(*j);     // no
g(&j);
cout << j; // 3

void g (int* p) {
	++*p;}

int j = 3;
g(j);      // no
g(*j);     // no
g(&j);
cout << j; // 4

void h (int& r) {
	++*r;}        // no

int k = 4;
h(&k);     // no
h(*k);     // no
h(k);
cout << k; //

void h (int& r) {
	++r;}         // yes

int k = 4;
h(&k);     // no
h(*k);     // no
h(k);
cout << k; // 5

void g (int* p) {
	// necessitates a guard!!!
	assert(p);
	if (!p) {
		// there's a problem}
	++*p;}        // undefined!!!

g(185); // no
g(0);   // yes!!!

int* p = 0;
int* p = nullptr;
cout << p;        // 0

void h (int& r) {
	// no guard needed!!!
	++r;}         // yes

h(185); // no
h(0);   // no

void g (int* p) {
	// necessitates a guard!!!
	assert(p);
	if (!p) {
		// there's a problem}
	int i = 2;
	p = &i;    // perfectly fine to reassign p
	++*p;}

void g (int* p) {
	// necessitates a guard!!!
	assert(p);
	if (!p) {
		// there's a problem}
	++*p;
	++p
	++*p
	++p
	++*p;
	++p;
	++*p; // undefined

int a[] = {2, 3, 4};
g(a); === g(&a[0]);

void h (int& r) {
	++r;
	++*(&r+1); // modify the second element

int a[] = {2, 3, 4};
h(a);                // no
h(*a);

int i = 2;
m(i);      // in C, this can only mean m is getting a copy
	       // in C++, I have no idea what is happening

int  i = 2;
int* p = i;  // no
int* p = &i;

// we would have to cast to allow pointer to point to itself

/*
define two functions:
	pre_incr
	post_incr

constraint
	you're not allowed to use ++!!!
*/

#ifdef TEST0
void test0 () {
    int i = 2;
    int j = pre_incr(i);
    assert(i == 3);
    assert(j == 3);}
#endif

#ifdef TEST1
void test1 () {
    int i = 2;
    int j = pre_incr(pre_incr(i)); // ++++i
    assert(i == 4);
    assert(j == 4);}
#endif

#ifdef TEST2
void test2 () {
    int i = 2;
    int j = post_incr(i);
    assert(i == 3);
    assert(j == 2);}
#endif

#ifdef TEST3
void test3 () {
    int i = 2;
//  post_incr(post_incr(i)); // error: no matching function for call to 'post_incr' // i++++
    assert(i == 2);}
#endif

int& pre_incr (int& r) {
	return r += 1;}

int post_incr (int& r) {
	int t = r;
	r += 1;
	return t;}















































