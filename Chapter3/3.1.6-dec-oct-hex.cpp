#include <iostream>
#include <climits>
int main()
{
    using namespace std; 
    int chest = 42;
    int waist = 0x42;
    int inseam = 042;

    cout << "???" << endl;
    cout << "chest = " << chest << "(42 in dec)" << endl;
    cout << hex;
    cout << "waist = " << waist << "(0x42 in hex)" << endl;
    cout << oct;
    cout << "inseam = " << inseam << "(042 in oct)" << endl;
    return 0;
}