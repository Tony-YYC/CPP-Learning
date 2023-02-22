#include <iostream>
void output1(void);
void output2(void);

int main()
{
    using namespace std;
    output1();
    output1();
    output2();
    output2();
    return 0;
}

void output1(void)
{
    std::cout << "Three blind mice" << std::endl;
}

void output2(void)
{
    std::cout << "See how they run" << std::endl;
}