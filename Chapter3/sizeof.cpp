#include <iostream>
#include <climits>
int main()
{
    using namespace std;

    int n_int = INT_MAX;
    int n_short = SHRT_MAX;
    long long n_long = LONG_MAX;

    cout << n_int << endl;
    cout << n_short << endl;
    cout << n_long << endl;
    cout << LONG_LONG_MAX << endl;
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof(short) << " bytes." << endl;
    cout << "long is " << sizeof(long) << " bytes." << endl;
    cout << "long long is " << sizeof(long long) << " bytes." << endl;
    return 0;
}