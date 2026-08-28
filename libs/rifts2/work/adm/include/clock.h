#define THE_BEGINNING 720561600
#define NOW(x) x-THE_BEGINNING

//don't use second because it doesn't really exist.
//#define SECOND 1
#define MINUTE 8
#define HOUR 480
#define DAY 11520
#define WEEK 80640
// used for the day of the month (CURRENT_DATE)
#define MONTH_DAY 139776
#define MONTH 4193280
#define YEAR 50319360

#define CURRENT_YEAR(x) (1+((NOW(x))/(YEAR)))
#define CURRENT_MONTH(x) ((NOW(x))%YEAR)/MONTH
#define CURRENT_WEEK(x) ((NOW(x))%MONTH)/WEEK
#define CURRENT_DAY(x) ((NOW(x))%WEEK)/DAY

#define CURRENT_DATE(x) (1+((NOW(x))%MONTH)/MONTH_DAY)
//hour of the day
#define CURRENT_HOUR(x) ((NOW(x))%DAY)/HOUR
//minute of the hour
#define CURRENT_MINUTE(x) ((NOW(x))%HOUR)/MINUTE
// second of the hour
#define CURRENT_SECOND(x) ((NOW(x))%MINUTE)*MINUTE

#define LONGEST_DAY 101
#define SHORTEST_DAY 1

#define DAYS ({ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" })
#define MONTHS ({ "January", "February", "March", "April", "May",\
"June", "July", "August", "September", "October", "November", "December" })
