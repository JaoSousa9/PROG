
#include "Date1.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Date::Date(){
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int year, int month, int day){
  this->year = year;
  this->month = month;
  this->day = day;
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}


bool is_before(const Date& date1, const Date& date2){

    
    if(date1.get_year() > date2.get_year()){
        return false;
    }else if(date1.get_year() == date2.get_year()){
        if(date1.get_month() > date2.get_month()){
            return false;
        }else if(date1.get_month() == date2.get_month() && date1.get_day() >= date2.get_day()){
            return false;
        }
    }

    return true;
}

int main(){

    Date d6(2023,10,31), d7(2022, 4, 29); d6.write(); cout << '-' << boolalpha << is_before(d6, d7) << '\n';

    return 0;
}