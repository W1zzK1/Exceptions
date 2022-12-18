#include <iostream>
#include "date.h" 
using namespace std;

int main()
{
    using namespace date;
    int a;
    cin >> a;
    int b;
    cin >> b;
    try
    {
        sys_days birthday;
        sys_days today = floor<days>(std::chrono::system_clock::now());
        cout << (today - birthday).count() << endl;
    }
    catch (...) {
        cout << "Данные введены не коректно";
    }
}