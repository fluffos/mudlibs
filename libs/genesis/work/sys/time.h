/*
 * /sys/time.h
 *
 * This file contains a few definitions that make it easy to convert an
 * integer time to a string. Supported macros are:
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
 * TIMESTAMP - Simply a shortcut for the ubiquitous ctime(time()).
 */
#define TIMESTAMP      (ctime(time()))

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

/*
 * Name   : TIME2FORMAT(t, f)
 * Returns: string
 *
 * Takes a time() value 't' and returns it as string formatted by the format
 * specifier 'f'. The format may be custom built from the following elements:
 *
 *     yyyy - year in four digits (Example: "2001")
 *     yy   - year in two digis (Example: "01", please try to avoid this)
 *     mmm  - month in string (Example: "Sep")
 *     mm   - month in number with prefix 0 (Example: "09")
 *     -m   - month in number in 2 characters (Example: " 9")
 *     m    - month in number without prefix 0 (Example: "9")
 *     ddd  - day of the week in string (Example: "Mon")
 *     dd   - day of the month in number with prefix 0 (Example: "03")
 *     -d   - day of the month in number in 2 characters (Example: " 3")
 *     d    - day of the month in number without prefix 0 (Example: "3")
 *     All other characters are literally copied to the target string.
 *
 * Examples: "d mmm yyyy" yields "3 Sep 2001"
 *           "yyyymmdd" yields "20010903"
 */
#define TIME2FORMAT(t, f) ((string)TIME_FILE->time2format((t), (f)))

/*
 * Name   : STAMP2TIME(s)
 * Returns: int
 *
 * Takes a string timestamp and transforms it into the corresponding time()
 * value or 0 on failure. It accepts the following formats:
 *
 * "mmm dd yyyy"          Example: "Mar 01 2013"          -> 1362092400
 * "mmm dd yyyy hh:mm"    Example: "Mar 01 2013 01:05"    -> 1362096300
 * "mmm dd yyyy hh:mm:ss" Example: "Mar 01 2013 01:05:10" -> 1362096310
 */
#define STAMP2TIME(s) ((int)TIME_FILE->stamp2time(s))

/*
 * Name   : MKTIME(s)
 * Returns: int
 *
 * Converts time components into time() value.
 *     y - year    (Example 2001)
 *     m - month   (Example 7)
 *     d - day     (Example 31)
 *     h - hour    (Example 23)
 *     m - minute  (Example 59)
 *     s - seconds (Example 59)
 */
#define MKTIME(y, m, d, h, m, s) ((int)TIME_FILE->mktime(y, m, d, h, m, s))

/* No definitions beyond this line. */
#endif TIME_DEFINITIONS
