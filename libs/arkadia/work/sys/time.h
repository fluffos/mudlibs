/*
 * /sys/time.h
 *
 * This file contains a few definitions that make it easy to convert an
 * integer time to a string. Supported macros are:
 *
 * - TIME_FILE
 * - CONVTIME(time)
 * - TIME2STR(time, sig)
 * - TIME2NUM(time)
 *
 * /Mercade, July 1 1995
 */

#ifndef TIME_DEFINITIONS
#define TIME_DEFINITIONS

/*
 * TIME_FILE
 * 
 * The file defining the time converting functions.
 */
#define TIME_FILE      ("/sys/global/time")

/*
 * Name   : CONVTIME(t)
 * Returns: string
 *
 * This takes a number of seconds 't' and converts it into a verbose string
 * with the number of days, hours, minutes and seconds in 't'. A component
 * that is zero will not be printed.
 *
 * Example: CONVTIME(175417) returns "2 days 43 minutes 37 seconds"
 */
#define CONVTIME(t)    ((string)TIME_FILE->convtime(t))

/*
 * Name   : TIME2NUM(t)
 * Returns: int *
 *
 * This takes a number of seconds 't' and returns an array of four integers
 * with the number of days, hours, minutes and seconds in 't'.
 *
 * Example: TIME2NUM(175417) returns ({ 2, 0, 43, 37 })
 */
#define TIME2NUM(t)    ((int *)TIME_FILE->time2num(t))

/*
 * Name   : TIME2STR(t, s)
 * Returns: string
 *
 * This takes a number of seconds 't' and returns a string descripting
 * that time in the 's' largest non-zero denominations. The names of
 * the time-elements are abbreviated to only one letter.
 *
 * Example: TIME2STR(175417, 0) returns ""                    (strlen =  0)
 *          TIME2STR(175417, 1) returns "2 d"             (strlen != fixed)
 *          TIME2STR(175417, 2) returns "  2 d 43 m"          (strlen = 10)
 *          TIME2STR(175417, 3) returns "  2 d 43 m 37 s"     (strlen = 15)
 *          TIME2STR(175417, 4) returns "  2 d  0 h 43 m 37 s"   (len = 20)
 *
 * Since 's' == 1 does not have any leading spaced, the length is not
 * fixed. You may want to use sprintf() to get correct alignment if you
 * use only one significant time-element in a table.
 */
#define TIME2STR(t, s) ((string)TIME_FILE->time2str((t), (s)))

/* No definitions beyond this line. */
#endif TIME_DEFINITIONS
