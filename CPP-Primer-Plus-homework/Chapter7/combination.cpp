#include <iostream>
long double combination(int choices, int size);
int main()
{
    using namespace std;
    int choices, size;
    cout << "Input the collection size and the number of items you choose:(q to quit)" << endl;
    while ((cin >> size >> choices) && (choices < size))
    {
        cout << "the result is:  " << combination(choices, size) << endl;
    }
    cout << "terminated" << endl;
    return 0;
}

long double combination(int choices, int size)
{
    long double result = 1;
    for(int a = choices, b = size; a > 0; a--, b--)
    {
        result = result * b / a;
    }
    return result;
};