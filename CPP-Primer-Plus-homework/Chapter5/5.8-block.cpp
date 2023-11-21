#include <iostream>
int main()
{
    using namespace std;
    cout << "The Amazing Accounto will sum and average";
    cout << "five numbers for you. \n";
    cout << "Please enter five values:\n";
    double number;
    double sum = 0.0;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Value" << i << ":";
        cin >> number;
        sum += number;
    }
    cout << "Five exquisite choices indeee!";
    cout << "They sum to " << sum << endl;
    cout << "and average to " << sum / 5 << endl;
    cout << "The amazing Accouto bids you adieu!" << endl;
    return 0;
}