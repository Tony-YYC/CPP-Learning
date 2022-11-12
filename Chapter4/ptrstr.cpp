#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    char animal[20] = "bearWinnie";
    const char *bird = "wren"; // can't use *bird to modify the value
    char *ps;

    cout << animal << "and" << bird << endl;
    cout << ps << endl;

    cout << "input a kind of animal" << endl;
    ps = animal;
    cin >> ps;
    cout << (int *)ps << "\t" << (int *)animal << endl;

    ps = new char[strlen(animal) + 1];
    strcpy(ps, animal);
    cout << (int *)animal << endl;
    cout << (int *)ps << endl;
    delete[] ps;
    return 0;
}