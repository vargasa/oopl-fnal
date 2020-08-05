// ------------
// IsPrimeT.c++
// ------------

// https://en.wikipedia.org/wiki/Primality_test

#include <cmath> // sqrt

#include "gtest/gtest.h"

using namespace std;

bool is_prime (int n) {
    assert(n > 0);
    if (n == 2)
        return true;
    if ((n == 1) || ((n % 2) == 0))
        return false;
    for (int i = 3; i < (std::sqrt(n) + 1); ++++i)
        if ((n % i) == 0)
            return false;
    return true;}

TEST(IsPrimeFixture, test0) {
    ASSERT_FALSE(is_prime( 1));}

TEST(IsPrimeFixture, test1) {
    ASSERT_TRUE(is_prime( 2));}

TEST(IsPrimeFixture, test2) {
    ASSERT_TRUE(is_prime( 3));}

TEST(IsPrimeFixture, test3) {
    ASSERT_FALSE(is_prime( 4));}

TEST(IsPrimeFixture, test4) {
    ASSERT_TRUE(is_prime( 5));}

TEST(IsPrimeFixture, test5) {
    ASSERT_TRUE(is_prime( 7));}

TEST(IsPrimeFixture, test6) {
    ASSERT_FALSE(is_prime( 9));}

TEST(IsPrimeFixture, test7) {
    ASSERT_FALSE(is_prime(27));}

TEST(IsPrimeFixture, test8) {
    ASSERT_TRUE(is_prime(29));}
