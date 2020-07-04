#include "datel.h"
#include <sstream>
#include <iomanip>
#include <iostream>

short unsigned monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};

short unsigned getDaysToMonth(short unsigned month,short unsigned year){
    short unsigned sum = 0;
    for(int i=0;i<month-1;i++){
        sum +=  monthDays[month-1];
    }
    if(year%4==0)
        (sum+=1);
    return sum-1;
}

DateL::DateL()
{
    time_t  timev;
    time(&timev);
    memcpy(&timeST, localtime(&timev), sizeof (struct tm));
}
DateL::DateL(short unsigned year,short unsigned month,short unsigned day){

    year -=1900;
    if(month>12)
        throw DateError();
    else if(month==2 && year%4==0 && day>29)
        throw DateError();
    else if (day>monthDays[month-1])
        throw DateError();

    struct tm t;


    t.tm_year = year;
    t.tm_mon = month-1;// Month, where 0 = jan
    t.tm_mday = day;
    t.tm_isdst = -1;

    this->timeST = t;
}

DateL::DateL(short unsigned hour,short unsigned minute){
    if(hour>=24 || minute >= 60)
        throw DateError();
    struct tm t;
    t.tm_min = minute;
    t.tm_hour = hour;
    timeST = t;

}
DateL::DateL(short unsigned year,short unsigned month,short unsigned day,short unsigned hour,short unsigned minute){

    year -=1900;
    if(month>12 || hour>=24 || minute >= 60)
        throw DateError();
    else if(month==2 && year%4==0 && day>29)
        throw DateError();
    else if (day>monthDays[month-1])
        throw DateError();

    struct tm t;
    t.tm_year = year;
    t.tm_mon = month-1;// Month, where 0 = jan
    t.tm_mday = day;
    t.tm_isdst = -1;

    t.tm_min = minute;
    t.tm_hour = hour;
    timeST = t;
}

DateL::DateL(long long unsigned unixTime){
    long long  a= (time_t)unixTime;
    memcpy(&timeST, localtime(&a), sizeof (struct tm));
}

bool DateL::setYear(short unsigned year){
    timeST.tm_year = year;
    return 1;
}

bool DateL::setMonth(short unsigned month){
    if(month>12)
        throw DateError();
    timeST.tm_mon = month;
    return 1;
}

bool DateL::setDay(unsigned short day){
    timeST.tm_mday = (day);
    return 1;
}

bool DateL::setHour(short unsigned hour){
    timeST.tm_hour = hour;
    return 1;
}
bool DateL::setMinute(short unsigned minute){
    timeST.tm_min = minute;
    return 1;
}

short unsigned DateL::getYear(){
    return timeST.tm_year + 1900;
}
short unsigned DateL::getMonth(){
    return timeST.tm_mon+1;
}
short unsigned DateL::getYDay(){
    return timeST.tm_yday;
}
short unsigned DateL::getMDay(){
    return timeST.tm_mday;
}
short unsigned DateL::getHour(){
    return timeST.tm_hour;
}
short unsigned DateL::getMinute(){
    return timeST.tm_min;
}

void DateL::addYear(){
    timeST.tm_year += 1;
}
void DateL::addDay(){
    time_t tmp = mktime(&timeST);
    tmp += 24*60*60;
    memcpy(&timeST, localtime(&tmp), sizeof (struct tm));
}
void DateL::addHour(){
    time_t tmp = mktime(&timeST);
    tmp += 60*60;
    memcpy(&timeST, localtime(&tmp), sizeof (struct tm));
}
void DateL::addMinute(){
    time_t tmp = mktime(&timeST);
    tmp += 60;
    memcpy(&timeST, localtime(&tmp), sizeof (struct tm));
}

void DateL::addYear(short unsigned year){
    timeST.tm_year += year;
}
void DateL::addDay(short unsigned day){
    time_t tmp = mktime(&timeST);
    tmp += 24*60*60*day;
    memcpy(&timeST, localtime(&tmp), sizeof (struct tm));
}
void DateL::addHour(short unsigned hour){
    time_t tmp = mktime(&timeST);
    tmp += 60*60*hour;
    memcpy(&timeST, localtime(&tmp), sizeof (struct tm));
}
void DateL::addMinute(short unsigned minute){
    time_t tmp = mktime(&timeST);
    tmp += 60*minute;
    memcpy(&timeST, localtime(&tmp), sizeof (struct tm));
}

void DateL::setDateFormat(DateFormat dateFormat){
    this->dateFormat = dateFormat;
}
void DateL::setDateSeparator(char separator){
    this->dateSeparator = separator;
}
std::string DateL::getFullDate(){
    std::stringstream yearS;
    yearS << std::setw(4) << std::setfill('0') << getYear();
    std::string year = yearS.str();

    std::stringstream monthS;
    monthS << std::setw(2) << std::setfill('0') << getMonth();
    std::string month = monthS.str();

    std::stringstream dayS;
    dayS << std::setw(2) << std::setfill('0') << getMDay();
    std::string day = dayS.str();

    std::stringstream hourS;
    hourS << std::setw(2) << std::setfill('0') << getHour();
    std::string hour = hourS.str();

    std::stringstream minuteS;
    minuteS << std::setw(2) << std::setfill('0') << getMinute();
    std::string minute = minuteS.str();



    switch (dateFormat) {
    case DateL::DateFormat::ddmmyy:{
        return day+dateSeparator+month+dateSeparator+year+" "+hour+':'+minute;
    }
    case DateL::DateFormat::mmddyy:{
        return month+dateSeparator+day+dateSeparator+year+" "+hour+':'+minute;
    }
    case DateL::DateFormat::yymmdd:{
        return year+dateSeparator+month+dateSeparator+day+" "+hour+':'+minute;
    }
    }
    return "";
}
std::string DateL::getDate(){
    std::stringstream yearS;
    yearS << std::setw(4) << std::setfill('0') << getYear();
    std::string year = yearS.str();

    std::stringstream monthS;
    monthS << std::setw(2) << std::setfill('0') << getMonth();
    std::string month = monthS.str();

    std::stringstream dayS;
    dayS << std::setw(2) << std::setfill('0') << getMDay();
    std::string day = dayS.str();


    switch (dateFormat) {
    case DateL::DateFormat::ddmmyy:{
        return day+dateSeparator+month+dateSeparator+year;
    }
    case DateL::DateFormat::mmddyy:{
        return month+dateSeparator+day+dateSeparator+year;
    }
    case DateL::DateFormat::yymmdd:{
        return year+dateSeparator+month+dateSeparator+day;
    }
    }
    return "";
}
std::string DateL::getHours(){
    std::stringstream hourS;
    hourS << std::setw(2) << std::setfill('0') << getHour();
    std::string hour = hourS.str();

    std::stringstream minuteS;
    minuteS << std::setw(2) << std::setfill('0') << getMinute();
    std::string minute = minuteS.str();

    return hour+':'+minute;
}

DateL *DateL::operator -(DateL &date){
    return  new DateL(mktime(&timeST)-date());
}
DateL *DateL::operator +(DateL &date){
    return  new DateL(mktime(&timeST+date()));
}
bool DateL::operator <(DateL &date){
    return  mktime(&timeST)<date();
}
bool DateL::operator >(DateL &date){
    return  mktime(&timeST)>date();
}
bool DateL::operator ==(DateL &date){
    return  mktime(&timeST)==date();
}
bool DateL::operator >=(DateL &date){
    return  mktime(&timeST)>=date();
}
bool DateL::operator <=(DateL &date){
    return  mktime(&timeST)<=date();
}
long long DateL::operator ()(){
    return mktime(&timeST);
}
