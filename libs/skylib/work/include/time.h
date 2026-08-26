/**
 * This file defines the array offsets for use in the time functions
 * and the length of things like days, minutes and seconds in the
 * calendar.  It also defines the names of the months and days
 * and their corresponding values.
 * @see /handlers/time_handler
 */

#ifndef __TIME_H
/** @ignore yes */
#define __TIME_H

/**
 * This is the year index into the time_array() return value.
 * @example
 * mixed arr;
 *
 * arr = TIME_H->time_array(time());
 * write("We are in the year " + arr[TIME_YEAR] + ".\n");
 * @see /handlers/time_handler
 */
#define TIME_YEAR 0
/**
 * This is the month index into the time_array() return value.
 * @example
 * mixed arr;
 *
 * arr = TIME_H->time_array(time());
 * write("We are in the " + arr[TIME_MONTH] + " month.\n");
 * @see /handlers/time_handler
 */
#define TIME_MONTH 1
/**
 * This is the day of month index into the time_array() return value.
 * @example
 * mixed arr;
 *
 * arr = TIME_H->time_array(time());
 * write("We are in the " + arr[TIME_DAY_OF_MONTH] + " day of month.\n");
 * @see /handlers/time_handler
 */
#define TIME_DAY_OF_MONTH 2
/**
 * This is the day of week index into the time_array() return value.
 * @example
 * mixed arr;
 *
 * arr = TIME_H->time_array(time());
 * write("We are in the " + arr[TIME_DAY_OF_WEEK] + " day of week.\n");
 * @see /handlers/time_handler
 */
#define TIME_DAY_OF_WEEK 3
/**
 * This is the hour index into the time_array() return value.
 * @example
 * mixed arr;
 *
 * arr = TIME_H->time_array(time());
 * write("Time is " + arr[TIME_HOUR] + ":" + arr[TIME_MINUTE]".\n");
 * @see /handlers/time_handler
 */
#define TIME_HOUR 4
/**
 * This is the minute index into the time_array() return value.
 * @example
 * mixed arr;
 *
 * arr = TIME_H->time_array(time());
 * write("Time is " + arr[TIME_HOUR] + ":" + arr[TIME_MINUTE]".\n");
 * @see /handlers/time_handler
 */
#define TIME_MINUTE 5

/* The month name defines. */

/**
 * This is the value associated with the month of January in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_JANUARY 1
/**
 * This is the value associated with the month of Feburary in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_FEBURARY 2
/**
 * This is the value associated with the month of March in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_MARCH 3
/**
 * This is the value associated with the month of April in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_APRIL 4
/**
 * This is the value associated with the month of May in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_MAY 5
/**
 * This is the value associated with the month of June in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_JUNE 6
/**
 * This is the value associated with the month of July in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_JULY 7
/**
 * This is the value associated with the month of August in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_AUGUST 8
/**
 * This is the value associated with the month of September in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_SEPTEMBER 9
/**
 * This is the value associated with the month of October in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_OCTOBER 10
/**
 * This is the value associated with the month of November in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_NOVEMBER 11
/**
 * This is the value associated with the month of December in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_DECEMBER 12

/* This is the defines for the days of the week. */

/**
 * This is the value associated with the day Monday in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_MONDAY 1
/**
 * This is the value associated with the day Tuesday in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_TUESDAY 2
/**
 * This is the value associated with the day Wednessday in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_WEDNESSDAY 3
/**
 * This is the value associated with the day Thursday in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_THURSDAY 4
/**
 * This is the value associated with the day Friday in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_FRIDAY 5
/**
 * This is the value associated with the day Saturday in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_SATURDAY 6
/**
 * This is the value associated with the day Sunday in the
 * time calendar.
 * @see /handlers/time_handler
 */
#define TIME_SUNDAY 7


/* the length of time defines and stuff. */

/**
 * The number of days in each year in the calendar.
 */
#define DAYS_PER_YEAR 360
/**
 * The number of days in each month in the calendar.
 */
#define DAYS_PER_MONTH 30
/**
 * The numbers of seconds per minute in the calendar.
 */
#define SECONDS_PER_MINUTE 15
/**
 * The numbers of minutes per hour in the calendar.
 */
#define MINUTES_PER_HOUR 60
/**
 * The numbers of minutes per hour in the calendar.
 */
#define HOURS_PER_DAY 24
/**
 * The number of days per week in the calendar.
 */
#define DAYS_PER_WEEK 7
/**
 * The numbers of minutes per day in the calendar.
 */
#define MINUTES_PER_DAY (MINUTES_PER_HOUR * HOURS_PER_DAY)
/**
 * The numbers of seconds in each day in the calendar.
 */
#define SECONDS_PER_DAY (MINUTES_PER_DAY * SECONDS_PER_MINUTE)
/**
 * The number of seconds per year in the calendar.
 */
#define SECONDS_PER_YEAR (SECONDS_PER_DAY * DAYS_PER_YEAR)
/**
 * Offset us by 400 years.
 */
#define YEAR_OFFSET 400
#endif
