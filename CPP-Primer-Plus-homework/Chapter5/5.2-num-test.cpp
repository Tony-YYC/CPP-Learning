#include<iostream>
int main(void)
{
    using namespace std;
    int limit;
    cout << "Enter the starting countdown value :";
    cin >> limit;
    int i;
    for(i=limit;i;i--) cout << "i = " << i << endl;
    cout << "Done now that i = " << i << endl;
    return 0;
}