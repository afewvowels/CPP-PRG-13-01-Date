//
//  main.cpp
//  CPP-PRG-13-01-Date
//
//  Created by Keith Smith on 11/13/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Design a class called Date. The class should store a date in three integers: month, day,
//  and year. There should be member functions to print the date in the following forms:
//
//      12/25/2018
//      December 25, 2018
//      25 December 2018
//
//  Demonstrate the class by writing a complete program implementing it.
//
//  Input Validation: Do not accept values for the day greater than 31 or less than 1. Do
//  not accept values for the month greater than 12 or less than 1.

#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    
    string convertMonth(int intMonth) const
    {
        string strMonth;
        
        switch(intMonth)
        {
            case 1:
                strMonth = "January";
                break;
            case 2:
                strMonth = "February";
                break;
            case 3:
                strMonth = "March";
                break;
            case 4:
                strMonth = "April";
                break;
            case 5:
                strMonth = "May";
                break;
            case 6:
                strMonth = "June";
                break;
            case 7:
                strMonth = "July";
                break;
            case 8:
                strMonth = "August";
                break;
            case 9:
                strMonth = "September";
                break;
            case 10:
                strMonth = "October";
                break;
            case 11:
                strMonth = "November";
                break;
            case 12:
                strMonth = "December";
                break;
            default:
                strMonth = "ERROR";
                break;
                
        }
        
        return strMonth;
    }
public:
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    string getFormat1() const;
    string getFormat2() const;
    string getFormat3() const;
};

void Date::setDay(int intDay)
{
    day = intDay;
}

void Date::setMonth(int intMonth)
{
    month = intMonth;
}

void Date::setYear(int intYear)
{
    year = intYear;
}

string Date::getFormat1() const
{
    string strDate;
    string strTemp;
    
    const string STR_DIVIDER = "/";
    
    strTemp = to_string(day);
    strDate.append(strTemp);
    strDate.append(STR_DIVIDER);
    
    strTemp = to_string(month);
    strDate.append(strTemp);
    strDate.append(STR_DIVIDER);
    
    strTemp = to_string(year);
    strDate.append(strTemp);
    
    return strDate;
}

string Date::getFormat2() const
{
    string strDate;
    string strTemp;
    
    strDate.append(convertMonth(month));
    
    strTemp = " ";
    strDate.append(strTemp);
    
    strTemp = to_string(month);
    strDate.append(strTemp);
    
    strTemp = ", ";
    strDate.append(strTemp);
    
    strTemp = to_string(year);
    strDate.append(strTemp);
    
    return strDate;
}

string Date::getFormat3() const
{
    string strDate;
    string strTemp;
    
    strTemp = to_string(day);
    strDate.append(strTemp);
    
    strTemp = " ";
    strDate.append(strTemp);
    
    strDate.append(convertMonth(month));
    
    strDate.append(strTemp);
    
    strTemp = to_string(year);
    strDate.append(strTemp);
    
    return strDate;
}

int main()
{
    int intTemp;
    Date dateMaker;
    
    cout << "What is the day? ";
    cin >> intTemp;
    while(!cin || intTemp < 1 || intTemp > 31)
    {
        cout << "Enter a number between 1 and 31: ";
        cin.clear();
        cin.ignore();
        cin >> intTemp;
    }
    dateMaker.setDay(intTemp);
    
    cout << "What is the month? ";
    cin >> intTemp;
    while(!cin || intTemp < 1 || intTemp > 12)
    {
        cout << "Enter a number between 1 and 12: ";
        cin.clear();
        cin.ignore();
        cin >> intTemp;
    }
    dateMaker.setMonth(intTemp);
    
    cout << "What is the year? ";
    cin >> intTemp;
    while(!cin || intTemp < 1900 || intTemp > 2018)
    {
        cout << "Enter a number between 1900 and 2018: ";
        cin.clear();
        cin.ignore();
        cin >> intTemp;
    }
    dateMaker.setYear(intTemp);
    
    cout << dateMaker.getFormat1() << endl;
    cout << dateMaker.getFormat2() << endl;
    cout << dateMaker.getFormat3() << endl;
    
    return 0;
}
