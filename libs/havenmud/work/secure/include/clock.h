#define THE_BEGINNING 0
#define NOW(x) x-THE_BEGINNING

#define SECOND  1
#define MINUTE  15
#define HOUR   (MINUTE * 60)
#define DAY    (HOUR * 24)
#define WEEK   (DAY  * 7)
#define MONTH  (DAY * 30)
#define YEAR   (DAY * 360)

#define CURRENT_YEAR(x)   (1+((NOW(x))/(YEAR)))
#define CURRENT_MONTH(x)  ((NOW(x))%YEAR)/MONTH
#define CURRENT_WEEK(x)   ((NOW(x))%MONTH)/(MONTH/4)
#define CURRENT_DAY(x)    ((NOW(x))%(MONTH/4))/DAY
#define CURRENT_HOUR(x)   ((NOW(x))%DAY)/HOUR
#define CURRENT_MINUTE(x) ((NOW(x))%HOUR)/MINUTE
#define CURRENT_SECOND(x) ((NOW(x))%20)

#define LONGEST_DAY 101
#define SHORTEST_DAY 1

#define DAYS ({ "Shadowday", "Lockday", "Flameday", "Darkday", "Vaigday" })
#define MONTHS ({ "Roki", "Praxi", "Altki", "Ketralki", "Aenterki",\
    "Kepki", "Kortki", "Kantki", "Sartki", "Denki" })
