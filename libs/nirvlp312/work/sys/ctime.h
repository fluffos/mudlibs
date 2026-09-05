/*
 * sys/ctime.h
 * This file includes useful macros to be used in combination with the
 * efun ctime()
 */
#ifndef _sys_ctime_h
#define _sys_ctime_h

#define CTIME_WEEKDAY 0..2
#define CTIME_DATE 4..9
#define CTIME_TIME 11..18
#define CTIME_YEAR 20..23
#define CTIME_SHORTYEAR 22..23
#define CTIME_MONTH 4..6
#define CTIME_MONTHDAY 4..9
#define CTIME_DAY 8..9
#define CTIME_HOUR 11..12
#define CTIME_HOURMINUTE 11..15
#define CTIME_MINUTE 14..15
#define CTIME_SECOND 17..18

/* The following is meant as an example how to create more complex patterns
 * using regreplace():
 */
#define CTIME_GET_DATE(x) regreplace(x,                                \
                                     "... (...) (..) ..:..:.. (....)", \
                                     "\\3-\\1-\\2",1)

#endif
