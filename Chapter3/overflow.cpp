#include <iostream>
#include <climits>
int main()
{
    using namespace std;
    short a = SHRT_MAX;
    unsigned short b = a;
    a = a + 1;
    b = b + 1;
    cout << a << endl;
    cout << b << endl;
    return 0;
}