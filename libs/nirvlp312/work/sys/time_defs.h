#ifndef _sys_time_defs_h
#define _sys_time_defs_h

/* return values of query_moon() */
#define WAXING_MOON 1
#define FULL_MOON   2
#define WANING_MOON 3
#define NEW_MOON    4

#define WEEKDAYS ({ "sunday", "monday", "tuesday", "wednesday", "thursday", \
                    "friday", "saturday" })
#define SUNDAY     0
#define MONDAY     1
#define TUESDAY    2
#define WEDNESDAY  3
#define THURSDAY   4
#define FRIDAY     5
#define SATURDAY   6

#define MONTHS ({ "january", "february", "march", "april", "may", "june", \
                  "july", "august", "september", "october", "november", \
                  "december" })
#define JANUARY    0
#define FEBRUARY   1
#define MARCH      2
#define APRIL      3
#define MAY        4
#define JUNE       5
#define JULY       6
#define AUGUST     7
#define SEPTEMBER  8
#define OCTOBER    9
#define NOVEMBER  10
#define DECEMBER  11

#define SEASONS ({ "sprint", "summer", "autumn", "winter" })
#define SPRING     0
#define SUMMER     1
#define AUTUMN     2
#define WINTER     3

#define SUN ({ "night", "dawn", "sunrise", "noon", "sunset", "dusk" })
#define NIGHT      0
#define DAWN       1
#define SUNRISE    2
#define NOON       3
#define SUNSET     4
#define DUSK       5

#endif  /* _sys_time_defs_h */
