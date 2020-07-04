#ifndef DATEL_H
#define DATEL_H
#include <string>


class DateError
{
public:
    DateError(){}
};


class DateL
{
public:
    enum class DateFormat{
        ddmmyy = 0,
        yymmdd = 1,
        mmddyy = 2
    };

    DateL();
    DateL(short unsigned year,short unsigned month,short unsigned day);
    DateL(short unsigned hour,short unsigned minute);
    DateL(short unsigned year,short unsigned month,short unsigned day,short unsigned hour,short unsigned minute);
    DateL(long long unsigned unixTime);

    bool setYear(short unsigned year);
    bool setMonth(short unsigned month);
    bool setDay(short unsigned day);
    bool setHour(short unsigned hour);
    bool setMinute(short unsigned minute);

    short unsigned getYear();
    short unsigned getMonth();
    short unsigned getMDay();
    short unsigned getYDay();
    short unsigned getHour();
    short unsigned getMinute();

    void addYear();
    void addDay();
    void addHour();
    void addMinute();

    void addYear(short unsigned year);
    void addDay(short unsigned day);
    void addHour(short unsigned hour);
    void addMinute(short unsigned minute);

    void setDateFormat(DateFormat dateFormat);
    void setDateSeparator(char separator);

    std::string getFullDate();
    std::string getDate();
    std::string getHours();

    DateL *operator -(DateL &date);
    DateL *operator +(DateL &date);
    bool operator <(DateL &date);
    bool operator >(DateL &date);
    bool operator ==(DateL &date);
    bool operator >=(DateL &date);
    bool operator <=(DateL &date);
    long long operator ()();


private:
    DateFormat dateFormat = DateFormat::ddmmyy;
    char dateSeparator = '-';
    struct tm timeST;
};



#endif // DATEL_H
