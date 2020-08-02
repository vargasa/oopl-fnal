// -----------------------
// OperatorOverloading.c++
// -----------------------

#include <cassert>  // assert
#include <iostream> // cout, endl

template <typename T>
class A {
    private:
        T _v;

    public:
        A (const T& v) :
                _v (v)
            {}

        bool operator == (const A& rhs) const {
            return _v == rhs._v;}};

void test1 () {
    const A<int> x = 2;
    const A<int> y = 2;
    assert(x == y);     // x.operator==(y)
    assert(x == 2);     // x.operator==(2)
//  assert(2 == x);     // 2.operator==(x); error: no match for 'operator==' (operand types are 'int' and 'A<int>')
    }

template <typename T>
class B {
    friend bool operator == (const B& lhs, const B& rhs) {
        return (lhs._v == rhs._v);}

    private:
        T _v;

    public:
        B (const T& v) :
            _v (v)
            {}};

void test2 () {
    const B<int> x = 2;
    const B<int> y = 2;
    assert(x == y);     // operator==(x, y)
    assert(x == 2);     // operator==(x, 2)
    assert(2 == x);}    // operator==(2, x)

int main () {
    using namespace std;
    cout << "OperatorOverloading.c++" << endl;
    test1();
    test2();
    cout << "Done." << endl;
    return 0;}
