// ----------
// EqualT.c++
// ----------

// https://en.cppreference.com/w/cpp/algorithm/equal

#include <algorithm>  // equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II1, typename II2>
bool my_equal (II1 b1, II1 e1, II2 b2) {
    while (b1 != e1) {
        if (*b1 != *b2)
            return false;
        ++b1;
        ++b2;}
    return true;}



using EqualArraySignature = function<bool (const int*, const int*, const int*)>;

struct EqualArrayFixture : TestWithParam<EqualArraySignature>
    {};

INSTANTIATE_TEST_CASE_P(
    EqualArrayInstantiation,
    EqualArrayFixture,
    Values(
        my_equal<const int*, const int*>,
        my_equal<const int*, const int*>),);

TEST_P(EqualArrayFixture, test0) {
    const int  a[] = {2, 3, 4};
    const int  b[] = {0, 2, 3, 4, 0};
    const int* b1  = begin(a);
    const int* e1  = end(a);
    const int* b2  = begin(b);
    ASSERT_TRUE(!GetParam()(b1, e1, b2));}

TEST_P(EqualArrayFixture, test1) {
    const int  a[] = {2, 3, 4};
    const int  b[] = {0, 2, 3, 4, 0};
    const int* b1  = begin(a);
    const int* e1  = end(a);
    const int* b2  = begin(b) + 1;
    ASSERT_TRUE(GetParam()(b1, e1, b2));}



using EqualListSignature = function<bool (list<int>::const_iterator, list<int>::const_iterator, vector<int>::const_iterator)>;

struct EqualListFixture : TestWithParam<EqualListSignature>
    {};

INSTANTIATE_TEST_CASE_P(
    EqualListInstantiation,
    EqualListFixture,
    Values(
        my_equal<list<int>::const_iterator, vector<int>::const_iterator>,
        my_equal<list<int>::const_iterator, vector<int>::const_iterator>),);

TEST_P(EqualListFixture, test3) {
    const list<int>             x  = {2, 3, 4};
    const vector<int>           y  = {0, 2, 3, 4, 0};
    list<int>::const_iterator   b1 = begin(x);
    list<int>::const_iterator   e1 = end(x);
    vector<int>::const_iterator b2 = begin(y) + 1;
    ASSERT_TRUE(GetParam()(b1, e1, b2));}
