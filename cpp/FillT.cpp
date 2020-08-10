// ---------
// FillT.c++
// ---------

// https://en.cppreference.com/w/cpp/algorithm/fill

#include <algorithm>  // equal, fill
#include <functional> // function
#include <list>       // list

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename FI, typename T>
void my_fill (FI b, FI e, const T& v) {
    while (b != e) {
        *b = v;
        ++b;}}



using FillArraySignature = function<void (int*, int*, int)>;

struct FillArrayFixture : TestWithParam<FillArraySignature>
    {};

INSTANTIATE_TEST_CASE_P(
    FillArrayInstantiation,
    FillArrayFixture,
    Values(
           fill<int*, int>,
        my_fill<int*, int>),);

TEST_P(FillArrayFixture, test0) {
    int  a[5]   = {};
    int* b      = begin(a) + 1;
    int* e      = end(a)   - 1;
    const int v = 2;
    GetParam()(b, e, v);
    ASSERT_TRUE(equal(begin(a), end(a), begin({0, 2, 2, 2, 0})));}



using FillListSignature = function<void (list<int>::iterator, list<int>::iterator, int)>;

struct FillListFixture : TestWithParam<FillListSignature>
    {};

INSTANTIATE_TEST_CASE_P(
    FillListInstantiation,
    FillListFixture,
    Values(
           fill<list<int>::iterator, int>,
        my_fill<list<int>::iterator, int>),);

TEST_P(FillListFixture, test2) {
    list<int>           x(5);
    list<int>::iterator b = begin(x);
    list<int>::iterator e = end(x);
    const int           v = 2;
    ++b;
    --e;
    GetParam()(b, e, v);
    ASSERT_TRUE(equal(begin(x), end(x), begin({0, 2, 2, 2, 0})));}
