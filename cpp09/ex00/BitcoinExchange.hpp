#pragma once

#include <iostream>
#include <vector>

class Info
{
    private :
    int year;
    int month;
    int day;
    int value;
    public :
     Info() : year(0), month(0), day(0), value(0) {}
    int get_year() {return(year);}
    int get_month() {return(month);}
    int get_day() {return(day);}
    int get_value(){return value;}
    void set_year(int n){year = n;}
    void set_month(int n){ month= n;}
    void set_day(int n){day = n;}
    void set_value(int n){value = n;}
};