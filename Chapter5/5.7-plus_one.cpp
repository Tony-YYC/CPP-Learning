#include <iostream>
int main()
{
    using std::cout;
    using std::endl;
    int a = 20;
    int b = 20;
    cout << "a = " << a << ": b=" << b << endl;
    cout << "a++ = " << a++ << ": ++b = " << ++b << endl;
    cout << "a = " << a << ";b = " << b << endl;
    int x = 1;
    x = 2 * x++ * (3 - ++x);
    cout << x << endl;
}