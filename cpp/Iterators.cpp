// -------------
// Iterators.c++
// -------------

// http://www.cplusplus.com/doc/tutorial/control/

#include <algorithm>    // copy, fill, reverse, sort
#include <cassert>      // assert
#include <forward_list> // forward_list
#include <iostream>     // cout, endl
#include <iterator>     // istream_iterator, ostream_iterator
#include <list>         // list
#include <sstream>      // istringstream, ostringstream
#include <vector>       // vector

using namespace std;

void test1 () {
    istringstream         sin("2 3 4");
    ostringstream         sout;
    istream_iterator<int> b(sin);
    istream_iterator<int> e;
    ostream_iterator<int> x(sout, " ");
    copy(b, e, x);
    assert(sout.str() == "2 3 4 ");}

/*
    ostringstream         sout;
    ostream_iterator<int> b(sout, " ");
    ostream_iterator<int> e(sout);
    const int v = 2;
    fill(b, e, v);                      // error: no matching function for call to '__fill'
*/

void test2 () {
    forward_list<int> x(3);
    const int v = 2;
    fill(begin(x), end(x), v);
    assert(equal(begin(x), end(x), begin({2, 2, 2})));}

/*
    forward_list<int> x = {2, 3, 4};
    reverse(begin(x), end(x));       // error: no matching function for call to '__reverse'
*/

void test3 () {
    list<int> x = {2, 3, 4};
    reverse(begin(x), end(x));
    assert(equal(begin(x), end(x), begin({4, 3, 2})));}

/*
    list<int> x = {2, 3, 4};
    sort(begin(x), end(x));  // error: invalid operands to binary expression ('std::__1::__list_iterator<int, void *>' and 'std::__1::__list_iterator<int, void *>')
*/

void test4 () {
    vector<int> x = {4, 2, 3};
    sort(begin(x), end(x));
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

int main () {
    cout << "Iterators.c++" << endl;
    test1();
    test2();
    test3();
    test4();
    cout << "Done." << endl;
    return 0;}
