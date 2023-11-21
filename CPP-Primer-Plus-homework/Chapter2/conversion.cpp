#include <iostream>
using namespace std;
int inputTen(string input, int src);
string tenOutput(int number, int des);
string convrt(string input, int src, int des);

int main()
{
    int src, des;
    string input, answer;
    cout << "Please input the source base and the destination base (2-36 supported, split by space): ";
    cin >> src >> des;
    cout << "Please input the number to be converted: ";
    cin >> input;
    cout << "result: " << convrt(input, src, des) << endl;
}

int inputTen(string input, int src)
{
    int Ten = 0;
    int j = 1;
    for (int i = input.size() - 1; i >= 0; i--)
    {
        if (src < 10)
        {
            if (input[i] >= 48 && input[i] <= 57)
                Ten += (input[i] - 48) * j;
            else
                return -1;
        }
        else
        {
            if (input[i] >= 48 && input[i] <= 57)
                Ten += (input[i] - 48) * j;
            else if (input[i] >= 65 && input[i] <= 90)
                Ten += (input[i] - 55) * j;
            else
                return -1;
        }
        j *= src;
    }
    return Ten;
}

string tenOutput(int number, int des)
{
    string output = "";
    while (number > 0)
    {
        output = output + ((number % des < 10) ? (char)((number % des) + 48) : (char)((number % des) + 55));
        number = (number - number % des) / des;
    }
    return output;
}

string convrt(string input, int src, int des)
{
    if (inputTen(input, src) == -1)
        return "Invalid input";
    else
        return tenOutput(inputTen(input, src), des);
}