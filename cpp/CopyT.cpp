// ---------
// CopyT.c++
// ---------

// https://en.cppreference.com/w/cpp/algorithm/copy
// https://gcc.gnu.org/onlinedocs/gcc-10.2.0/libstdc++/api/a00041_source.html

#include <cstdio>

#include <algorithm>  // copy, equal
#include <functional> // function
#include <list>       // list
#include <vector>     // vector

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename II, typename OI>
OI my_copy (II b1, II e1, OI b2) {
    while (b1 != e1) {
        *b2 = *b1;
        ++b1;
        ++b2;}
    return b2;}



using CopyArraySignature = function<int* (const int*, const int*, int*)>;

struct CopyArrayFixture : TestWithParam<CopyArraySignature>
    {};

INSTANTIATE_TEST_CASE_P(
    CopyArrayInstantiation,
    CopyArrayFixture,
    Values(
           copy<const int*, int*>,
        my_copy<const int*, int*>),);

TEST_P(CopyArrayFixture, test0) {
    const int  a[]  = {2, 3, 4};
    int        b[5] = {};
    const int* b1   = begin(a);
    const int* e1   = end(a);
    int*       b2   = begin(b) + 1;
    int*       e2   = GetParam()(b1, e1, b2);
    ASSERT_EQ(e2, begin(b) + 4);
    ASSERT_TRUE(equal(begin(b), end(b), begin({0, 2, 3, 4, 0})));}



using CopyListSignature = function<vector<int>::iterator (list<int>::const_iterator, list<int>::const_iterator, vector<int>::iterator)>;

struct CopyListFixture : TestWithParam<CopyListSignature>
    {};

INSTANTIATE_TEST_CASE_P(
    CopyListInstantiation,
    CopyListFixture,
    Values(
           copy<list<int>::const_iterator, vector<int>::iterator>,
        my_copy<list<int>::const_iterator, vector<int>::iterator>),);

TEST_P(CopyListFixture, test1) {
    const list<int>           x = {2, 3, 4};
    vector<int>               y(5);
    list<int>::const_iterator b1 = begin(x);
    list<int>::const_iterator e1 = end(x);
    vector<int>::iterator     b2 = begin(y) + 1;
    vector<int>::iterator     e2 = GetParam()(b1, e1, b2);
    ASSERT_EQ(e2, begin(y) + 4);
    ASSERT_TRUE(equal(begin(y), end(y), begin({0, 2, 3, 4, 0})));}
