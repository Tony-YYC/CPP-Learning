#include <iostream>
int main()
{
    using namespace std;
    float a = 2.34e+22f;
    float b = a + 1.0f;
    double a1 = 2.34e+22f;
    double b1 = a + 1.0f;

    cout << "a =" << a << endl;
    cout << "b - a = " << b - a << endl;
    cout << "a1 =" << a1 << endl;
    cout << "b1 - a1 = " << b1 - a1 << endl;
    return 0;
}