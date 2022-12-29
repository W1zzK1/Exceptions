#include <ctime>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <time.h>
using namespace std;

struct dates {
    int day1;
    int month1;
    int year1;

    int day2;
    int month2;
    int year2;

    dates(int xday, int xmonth, int xyear, int xday2, int xmonth2, int xyear2) : day1(xday), month1(xmonth), year1(xyear), day2(xday2), month2(xmonth2), year2(xyear2) {}
};

class exception {};


tm make_tm(int year, int month, int day)
{
    tm tm = {0};
    tm.tm_year = year - 1900; ///для хранениея года
    tm.tm_mon = month - 1;///для хранениея месяца
    tm.tm_mday = day; ///для хранениея дня
    return tm;
}

int date_diff(dates d) {
    if (isnan(d.year2)) 
        throw invalid_argument("Недопустимые значение.");
    if ((d.day1 <= 0)) 
        throw invalid_argument("Недопустимые значение.");
    if (isnan(d.year1)) 
        throw invalid_argument("Недопустимые значение.");

    if (isnan(d.month1)) 
        throw invalid_argument("Недопустимые значение.");
    if (d.month1 > 12) 
        throw invalid_argument("Недопустимые значение.");

    if (isnan(d.month2)) 
        throw invalid_argument("Недопустимые значение.");
    if (d.month2 > 12) 
        throw invalid_argument("Недопустимые значение.");


    tm tm1 = make_tm(2012, 4, 2);
    tm tm2 = make_tm(2003, 2, 2);


    time_t time1 = std::mktime(&tm1);
    time_t time2 = std::mktime(&tm2);


    const int seconds_per_day = 60 * 60 * 24;
    time_t difference = (time1 - time2) / seconds_per_day;


    double portable_difference = difftime(time1, time2) / seconds_per_day;

    return portable_difference;
};


int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите первую дату по частям : " << endl;
    int day1;
    cin >> day1;
    int month1;
    cin >> month1;
    int year1;
    cin >> year1;

    cout << "Введите вторую дату по частям : " << endl;
    int day2;
    cin >> day2;
    int month2;
    cin >> month2;
    int year2;
    cin >> year2;

    dates dts(day1, month1, year1, day2, month2, year2);

    try {
        double resultat = date_diff(dts);
        cout <<"Итоговый результут :" << resultat;
    }

    catch (...) {
        cout << "Не верный ввод данных";
    }
    return 0;
}
