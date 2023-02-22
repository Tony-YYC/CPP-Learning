#include <iostream>
double tempCtoF(double tempC);
int main()
{
    using namespace std;
    double tempC;
    cout << "Please enter a Celsius value: ";
    cin >> tempC;
    cout << tempC << " degrees Celsius is " << tempCtoF(tempC) << " degrees Fahrenheit." << endl;
    return 0;
}
double tempCtoF(double tempC)
{
    return 32 + tempC * 1.8;
}