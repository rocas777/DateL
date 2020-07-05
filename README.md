# DateL 

Simple class with CRUD functions and formated output, changeable in runtime, with exception handling;
Handles both date and hours,minute;  
Whenever a date input is illegal, an exception is raised of the type **DateError";

## Functions  

### Output Function
 There are three possible outputs(specific date formats(order) and separators can be changed,see **Configuration Functions** section), considering the date class is initialized with the date of 05 of July of 2020, 17 hours and 12 minutes, the possible outputs are:
 * 05-07-2020 17:12
 * 05-07-2020
 * 17:12
 
 Such outpus are, respectively, the return of the following functions:
 * std::string getFullDate()
 * std::string getDate()
 * std::string getHours()

### Configuration Functions
Output Functions use one of three formats:
 * ddmmyy
 * yymmdd
 * mmddyy

By default the date output is in the format **ddmmyy**, where the separator used is '-'.  
The default output is -> dd-mm-yyyy  
Both the separator and the format can be changed using the following functions:  

* **setDateFormat**(DateFormat dateFormat)
* **setDateSeparator**(char separator)


### Set Functions
* **setYear**(short unsigned )
* **setMonth**(short unsigned )
* **setDay**(short unsigned ) (day of the month)
* **setHour**(short unsigned )
* **setMinute**(short unsigned )

### Get Functions
* short unsigned **getYear()**
* short unsigned **getMonth()**
* short unsigned **getMDay()** (return day of the month)
* short unsigned **getYDay()** (return day of the year)
* short unsigned **getHour()**
* short unsigned **getMinute()**


### Implementation details
The class is implemented on top of struct tm;  
It uses a unix time schema, with the initial date being 01-01-1900 00:00

### Dependencies
The class depends o the following libraries:
* sstream
* iomanip
* iostream
