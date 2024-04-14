
#include "Date2.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;

Date::Date(){
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int year, int month, int day){

    map<int, int> month_days; 
    

    month_days.insert(std::pair<int,int>(1,31));
    
    month_days.insert(std::pair<int,int>(3,31));
    month_days.insert(std::pair<int,int>(4,30));
    month_days.insert(std::pair<int,int>(5,31));
    month_days.insert(std::pair<int,int>(6,30));
    month_days.insert(std::pair<int,int>(7,31));
    month_days.insert(std::pair<int,int>(8,31));
    month_days.insert(std::pair<int,int>(9,30));
    month_days.insert(std::pair<int,int>(10,31));
    month_days.insert(std::pair<int,int>(11,30));
    month_days.insert(std::pair<int,int>(12,31));

    if(year > 0 && year < 9999){
        if((year % 4 == 0) || year % 100 == 0){
            month_days.insert(std::pair<int,int>(2,29));
        }else{
            month_days.insert(std::pair<int,int>(2,28));
        }
        this->year = year;
        if(month >= 1 && month <= 12){
            this->month = month;
            if(day > 0 && day < month_days.at(month)){
                this -> day = day;
            }else{
                this-> year = 0;
                this-> month = 0;
                this-> day = 0;
            }
        }else{
        this-> year = 0;
        this-> month = 0;
        this-> day = 0;
        }
    }else{
        this-> year = 0;
        this-> month = 0;
        this-> day = 0;
    }
}

Date::Date(const std::string& year_month_day){
    int year, month, day;

    istringstream iss(year_month_day);

    string token;

    iss >> year;
    getline(iss, token, '/');
    
    iss >> month;
    getline(iss, token, '/');

    iss >> day;

    map<int, int> month_days; 
    

    month_days.insert(std::pair<int,int>(1,31));
    
    month_days.insert(std::pair<int,int>(3,31));
    month_days.insert(std::pair<int,int>(4,30));
    month_days.insert(std::pair<int,int>(5,31));
    month_days.insert(std::pair<int,int>(6,30));
    month_days.insert(std::pair<int,int>(7,31));
    month_days.insert(std::pair<int,int>(8,31));
    month_days.insert(std::pair<int,int>(9,30));
    month_days.insert(std::pair<int,int>(10,31));
    month_days.insert(std::pair<int,int>(11,30));
    month_days.insert(std::pair<int,int>(12,31));

    if(year > 0 && year < 9999){
        if((year % 4 == 0) || year % 100 == 0){
            month_days.insert(std::pair<int,int>(2,29));
        }else{
            month_days.insert(std::pair<int,int>(2,28));
        }
        this->year = year;
        if(month >= 1 && month <= 12){
            this->month = month;
            if(day > 0 && day < month_days.at(month)){
                this -> day = day;
            }else{
                this-> year = 0;
                this-> month = 0;
                this-> day = 0;
            }
        }else{
        this-> year = 0;
        this-> month = 0;
        this-> day = 0;
        }
    }else{
        this-> year = 0;
        this-> month = 0;
        this-> day = 0;
    }
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

bool Date::is_valid() const{
    if(this->day == 0 || this->month == 0 || this->year == 0){
        return false;
    }else{
        return true;
    }

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

    Date d4("1900/1/1"); d4.write(); cout << (d4.is_valid() ? "" : "-invalid") << endl;
    Date d1();
    
    return 0;
}