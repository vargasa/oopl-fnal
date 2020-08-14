// --------------
// UniquePtrT.c++
// --------------

// http://en.cppreference.com/w/cpp/memory/unique_ptr
// https://gcc.gnu.org/onlinedocs/gcc-10.2.0/libstdc++/api/a00689_source.html

#include <algorithm> // swap
#include <memory>    // unique_ptr
#include <utility>   // move

#include "gtest/gtest.h"

using namespace std;
using namespace testing;

template <typename T>
class my_unique_ptr {
    private:
        T* _p = nullptr;

    public:
        my_unique_ptr () = default;

        explicit my_unique_ptr (T* p) {
            _p = p;}

        my_unique_ptr (const my_unique_ptr&) = delete;

        my_unique_ptr (my_unique_ptr&& rhs) {
            swap(_p, rhs._p);}

        my_unique_ptr& operator = (const my_unique_ptr&) = delete;

        my_unique_ptr& operator = (my_unique_ptr&& rhs) {
            if (this == &rhs)
                return *this;
            my_unique_ptr that(move(rhs));
            swap(_p, that._p);
            return *this;}

        ~my_unique_ptr () {
            delete _p;}

        T* get () const {
            return _p;}};

struct A {
    static int c; // number of current A instances

    A () {
        ++c;}

    ~A () {
        --c;}};

int A::c = 0;

template <typename T>
struct UniquePtrFixture : Test {
    using unique_ptr_type = T;};

using
    unique_ptr_types =
    Types<
           unique_ptr<A>,
        my_unique_ptr<A>>;

#ifdef __APPLE__
    TYPED_TEST_CASE(UniquePtrFixture, unique_ptr_types,);
#else
    TYPED_TEST_CASE(UniquePtrFixture, unique_ptr_types);
#endif

TYPED_TEST(UniquePtrFixture, test0) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    unique_ptr_type x;            // default constructor
    ASSERT_EQ(A::c,    0);
    ASSERT_EQ(x.get(), nullptr);}

TYPED_TEST(UniquePtrFixture, test1) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(A::c, 0);
    {
//  unique_ptr_type x = new A;   // error: conversion from 'A*' to non-scalar type 'unique_ptr_type' {aka 'std::unique_ptr<A>'} requested
    unique_ptr_type x(new A);
    ASSERT_EQ(A::c,    1);
    ASSERT_NE(x.get(), nullptr);
    }                            // destructor
    ASSERT_EQ(A::c, 0);}

TYPED_TEST(UniquePtrFixture, test2) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(A::c, 0);
    {
    unique_ptr_type x(new A);
    ASSERT_EQ(A::c, 1);
//  unique_ptr_type y = x;       // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]'
    unique_ptr_type y = move(x); // move constructor
    ASSERT_EQ(A::c,    1);
    ASSERT_EQ(x.get(), nullptr);
    ASSERT_NE(y.get(), nullptr);
    }
    ASSERT_EQ(A::c, 0);}

TYPED_TEST(UniquePtrFixture, test3) {
    using unique_ptr_type = typename TestFixture::unique_ptr_type;
    ASSERT_EQ(A::c, 0);
    {
    unique_ptr_type x(new A);
    unique_ptr_type y(new A);
    ASSERT_EQ(A::c, 2);
//  y = x;                       // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]'
    y = move(x);                 // move assignment operator
    ASSERT_EQ(A::c,    1);
    ASSERT_EQ(x.get(), nullptr);
    ASSERT_NE(y.get(), nullptr);
    }
    ASSERT_EQ(A::c, 0);}



unique_ptr<A> f () {
    assert(A::c == 0);
    unique_ptr<A> x(new A);
    assert(A::c == 1);
    return x;}

TEST(UniquePtrFixture, test6) {
    ASSERT_EQ(A::c, 0);
    {
    unique_ptr<A> x = f();
    ASSERT_EQ(A::c, 1);
    }
    ASSERT_EQ(A::c, 0);}



my_unique_ptr<A> g () {
    assert(A::c == 0);
    my_unique_ptr<A> x(new A);
    assert(A::c == 1);
    return x;}

TEST(UniquePtrFixture, test7) {
    ASSERT_EQ(A::c, 0);
    {
    my_unique_ptr<A> x = g();
    ASSERT_EQ(A::c, 1);
    }
    ASSERT_EQ(A::c, 0);}
