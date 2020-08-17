// -----------
// StrCmpT.c++
// -----------

// https://en.cppreference.com/w/c/string/byte/strcmp
// https://gcc.gnu.org/onlinedocs/gcc-10.2.0/libstdc++/api/a00332_source.html

#include <cstring>    // strcmp
#include <functional> // function

#include "gtest/gtest.h"

int my_strcmp (const char* a, const char* b) {
    while ((*a != 0) && (*a == *b)) {
        ++a;
        ++b;}
    return (*a - *b);}

using namespace std;
using namespace testing;

using StrCmpSignature = function<int (const char*, const char*)>;

struct StrCmpFixture : TestWithParam<StrCmpSignature> {};

INSTANTIATE_TEST_CASE_P(
    StrCmpInstantiation,
    StrCmpFixture,
    Values(
           strcmp,
        my_strcmp),);

TEST_P(StrCmpFixture, test0) {
    ASSERT_EQ(GetParam()("", ""), 0);}

TEST_P(StrCmpFixture, test1) {
    ASSERT_EQ(GetParam()("abc", "abc"), 0);}

TEST_P(StrCmpFixture, test2) {
    ASSERT_GT(GetParam()("abc", "ab"), 0);}

TEST_P(StrCmpFixture, test3) {
    ASSERT_GT(GetParam()("abc", "aba"), 0);}

TEST_P(StrCmpFixture, test4) {
    ASSERT_LT(GetParam()("ab", "abc"), 0);}

TEST_P(StrCmpFixture, test5) {
    ASSERT_LT(GetParam()("aba", "abc"), 0);}
