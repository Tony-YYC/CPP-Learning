#include<iostream>
int main()
{
    using namespace std;
    double *p3 = new double [3];
    short tell[10];
    p3[0]=0.2;
    p3[1]=0.5;
    p3[2] = 0.8;
    cout << "p3[1] is" << p3[1] << ".\n" ;
    p3 = p3 + 1;
    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 - 1;
    cout << &p3 << endl;
    cout << p3 << endl;
    int wages[3];
    int length = 3;
    double *times = new double [length];
    cout <<sizeof(wages) << endl;
    cout << sizeof(times) << endl;
    cout << wages << endl;
    cout << &wages << endl;
    cout << wages + 1 <<endl;
    cout << &wages + 1 << endl;
    delete [] p3;
    return 0;
}