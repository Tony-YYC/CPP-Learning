#include <iostream>
#include <fstream>
#include <cstdlib>
const int SIZE = 60;
int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;
    cout << "Enter name of data file:";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file" << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;

    inFile >> value;
    while (inFile.good())
    {
        ++count;
        sum += value;
        inFile >> value;
    }
    //while(inFile >> value)
    //{
    //    ++count;
    //    sum += value;
    //}
    //may be the latter is better and also more concise
    if (inFile.eof())
        cout << "End of File reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data dismatch.\n";
    else
        cout << "Input terminated by unknown reason.";

    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read" << count << endl;
        cout << "Sum" << sum << endl;
        cout << "Average" << sum / count << endl;
    }
    inFile.close();
    return 0;
}