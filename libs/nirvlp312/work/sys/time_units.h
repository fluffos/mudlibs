/*
 * sys/time_units.h
 * This file contains common time units measured in seconds.
 * Include it to use the names instead of the large numbers or costly formulas
 */

#ifndef _sys_time_units_h
#define _sys_time_units_h

#define ONE_SECOND             1
#define ONE_MINUTE            60  /* 60*ONE_SECOND */
#define ONE_HOUR            3600  /* 60*ONE_MINUE  */
#define ONE_DAY            86400  /* 24*ONE_HOUR   */
#define ONE_WEEK          604800  /* 7*ONE_DAY     */
#define ONE_MONTH        2629800  /* ONE_YEAR/12   */
#define ONE_YEAR        31557600  /* 365*ONE_DAY + 6*ONE_HOUR  */

#define HALF_MINUTE           30
#define HALF_HOUR           1800
#define HALF_DAY           43200
#define HALF_WEEK         302400
#define HALF_MONTH       1314900
#define HALF_YEAR       15778800

#define MOONDAY 89428  /* seconds ... off by .3 sek
                          should be exactly:
                          Month * 86400 / (Month - 86400) */

#endif
