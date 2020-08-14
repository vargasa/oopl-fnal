// ----------
// ArrayT.c++
// ----------

// https://en.cppreference.com/w/cpp/container/array
// https://gcc.gnu.org/onlinedocs/gcc-10.2.0/libstdc++/api/a00047_source.html

#include <algorithm> // equal
#include <array>     // array
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <utility>   // !=

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

using rel_ops::operator!=;

template <typename T, size_t N>
struct my_array {
    friend bool operator == (const my_array& lhs, const my_array& rhs) {
        return equal(lhs.begin(), lhs.end(), rhs.begin());}

    T _a[N];

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

template <typename T>
struct ArrayFixture : Test {
    using array_type = T;};

using
    array_types =
    Types<
           array<int, 3>,
        my_array<int, 3>>;

#ifdef __APPLE__
    TYPED_TEST_CASE(ArrayFixture, array_types,);
#else
    TYPED_TEST_CASE(ArrayFixture, array_types);
#endif

TYPED_TEST(ArrayFixture, test0) {
    using array_type = typename TestFixture::array_type;
    array_type x;
    assert(x.size() == 3);}

TYPED_TEST(ArrayFixture, test1) {
    using array_type = typename TestFixture::array_type;
//  array_type x = {2, 3, 4, 5}; // error: too many initializers for 'array_type'
    array_type x = {2, 3, 4};
    assert(x[1] == 3);
    x[1] = 5;
    assert(x[1] == 5);}

TYPED_TEST(ArrayFixture, test2) {
    using array_type = typename TestFixture::array_type;
    const array_type x = {2, 3, 4};
    assert(x[1] == 3);
//  x[1] = 5;                             // error: assignment of read-only location 'x.array_type::operator[](1)'
    assert(x[1] == 3);}

TYPED_TEST(ArrayFixture, test3) {
    using array_type = typename TestFixture::array_type;
    const array_type x = {2, 3, 4};
    assert(equal(begin(x), end(x), begin({2, 3, 4})));}

TYPED_TEST(ArrayFixture, test4) {
    using array_type = typename TestFixture::array_type;
    array_type       x = {2, 3, 4};
    const array_type y = x;
    assert(&*begin(x) != &*begin(y));
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}

TYPED_TEST(ArrayFixture, test5) {
    using array_type = typename TestFixture::array_type;
    const array_type x = {2, 3, 4};
    array_type       y = {5, 6, 7};
    y = x;
    assert(&*begin(x) != &*begin(y));
    assert(equal(begin(y), end(y), begin({2, 3, 4})));}

TYPED_TEST(ArrayFixture, test6) {
    using array_type = typename TestFixture::array_type;
    const array_type x = {2, 3, 4};
    const array_type y = {2, 3, 4};
    assert(  x == y);
    assert(!(x != y));}

TYPED_TEST(ArrayFixture, test7) {
    using array_type = typename TestFixture::array_type;
    const array_type x = {2, 3, 4};
    const array_type y = {2, 3, 5};
    assert(  x != y);
    assert(!(x == y));}
