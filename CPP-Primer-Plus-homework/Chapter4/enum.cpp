#include <iostream>
int main()
{
    using namespace std;
    enum bits{one = 1,two = 2,four = 4,eight = 8};
    bits myflag;
    myflag = bits(32);
    cout << myflag << endl;
    return 0;
}