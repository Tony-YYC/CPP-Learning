#include <iostream>
double LYtoAU(double lightYear);
int main()
{
    using namespace std;
    double lightYear;
    cout << "Enter the number of light years: ";
    cin >> lightYear;
    cout << lightYear << " light years = " << LYtoAU(lightYear) << " astronomical units." << endl;
    return 0;
}

double LYtoAU(double lightYear)
{
    return lightYear * 63240;
}