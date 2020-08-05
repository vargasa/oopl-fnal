// ---------
// IncrT.c++
// ---------

// https://en.cppreference.com/w/cpp/language/operator_incdec

#include "gtest/gtest.h"

int& pre_incr (int& r) {
    return r += 1;}

int post_incr (int& r) {
    int v = r;
    r += 1;
    return v;}

TEST(IncrFixture, test0) {
    int i = 2;
    int j = pre_incr(i);
    ASSERT_EQ(i, 3);
    ASSERT_EQ(j, 3);}

TEST(IncrFixture, test1) {
    int i = 2;
    int j = pre_incr(pre_incr(i));
    ASSERT_EQ(i, 4);
    ASSERT_EQ(j, 4);}

TEST(IncrFixture, test2) {
    int i = 2;
    int j = post_incr(i);
    ASSERT_EQ(i, 3);
    ASSERT_EQ(j, 2);}

TEST(IncrFixture, test3) {
    int i = 2;
//  post_incr(post_incr(i)); // error: no matching function for call to 'post_incr'
    ASSERT_EQ(2, i);}
