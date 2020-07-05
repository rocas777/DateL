# DateL 

Simple class with some CRUD functions to use in projects where Time manipulations are made  
Implemented on top of the c tm struct.

## Functions  

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
