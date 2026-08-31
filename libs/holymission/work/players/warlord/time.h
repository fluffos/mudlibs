#define THE_BEGINNING 710010900
#define YEAR2K        946681200 // Calculation thanks to Sauron
#define NOW(x) x-THE_BEGINNING

#define SECOND      1
#define MINUTE     15
#define HOUR    MINUTE*60
#define DAY     HOUR*24
#define WEEK    DAY*7
#define MONTH   YEAR/12
#define YEAR    WEEK*52

#define CURRENT_YEAR(x)   (1+((NOW(x))/(YEAR)))
#define CURRENT_MONTH(x)  ((NOW(x))%YEAR)/MONTH
#define CURRENT_WEEK(x)   ((NOW(x))%MONTH)/(MONTH/5)
#define CURRENT_DAY(x)    ((NOW(x))%(MONTH/5))/DAY
#define CURRENT_HOUR(x)   ((NOW(x))%DAY)/HOUR
#define CURRENT_MINUTE(x) ((NOW(x))%HOUR)/MINUTE
#define CURRENT_SECOND(x) ((NOW(x))%MINUTE)

#define LONGEST_DAY  101
#define SHORTEST_DAY 1

#define DAYS ({ "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" })
#define MONTHS ({ "January","February","March","April","May","June","July","August","September","October","November","December" })
