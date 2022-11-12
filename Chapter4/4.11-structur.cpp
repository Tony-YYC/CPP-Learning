#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};
struct inflatable;
int main()
{
    using namespace std;
    inflatable guest =
    {
        "Gloria",
        1.88,
        29.99
    };
    inflatable pal =
    {
        "Arthur",
        3.12,
        32.99
    };
    cout << "Expand your guest list with" << guest.name;
    cout << " and " << pal.name << "!\n";
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    return 0;
}