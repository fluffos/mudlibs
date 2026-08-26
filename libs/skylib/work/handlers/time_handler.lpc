/**
 * This handler contains all the stuff needed to handle and deal with
 * mud times.  It contains functions to get names for all the months
 * from indexes and to return a nice string from an input array of
 * values.
 * <p>
 * Some of this code is from Deutha's original amtime() simul_efun and
 * some from the am_time_array() efun which Macchirton wrote, although the
 * latter has mostly been rewritten.
 * @author Pinkfish
 * @changed Dediscified, Sandoz, 2002.
 */

#include <time.h>

int *query_time_array(int number);
string query_hour_minute(int hour, int minute);
string query_day_of_week(int day_of_week);
string query_special_day(int month, int day_of_month);
string query_month(int month);
int query_hour(int time);
int query_minute(int time);

/**
 * This method takes an array generated from time_array() as an input
 * to create the return string.
 * @param arr the array to turn into a string
 * @param flag if the flag is set to 1, then the year will be returned as well,
 * if 2 then hours and minutes will be ignored, in addition to returning the year
 * @return the nice time string
 */
string query_time_from_array( int *arr, int flag ) {
   string special, ret;

   special = query_special_day( arr[TIME_MONTH], arr[TIME_DAY_OF_MONTH] );

   if( flag != 2 )
       ret = query_hour_minute( arr[TIME_HOUR], arr[TIME_MINUTE]) + ", ";
   else
       ret = "";

   ret += ( special ? special : query_day_of_week(arr[TIME_DAY_OF_WEEK])+" "+
                                ordinal(arr[TIME_DAY_OF_MONTH])+" "+
                                query_month(arr[TIME_MONTH]) );
   if( flag )
       ret += ", "+arr[TIME_YEAR]+"AS";

   return ret;

} /* query_time_from_array() */

/**
 * This method returns the time for the input time number.
 * This function takes the same input as the efun ctime().
 * You pass in the time number and it returns a string
 * detailing the in-mud time.
 * @param number the time number
 * @return a string containing the time
 */
varargs string query_time( int number, int flag ) {
   return query_time_from_array( query_time_array(number), flag );
} /* query_time() */

/**
 * This method returns the hour/minute as a string.  It adds the am/pm
 * bits to the number.
 * @param hour the hour of the day
 * @param minute the minute of the hour
 * @return the hour/minute string
 */
string query_hour_minute(int hour, int minute) {
   int print_hour, half_day;

   half_day = HOURS_PER_DAY / 2;
   print_hour = hour % half_day;

   if( print_hour == 0 )
       print_hour = 12;

   return sprintf("%d:%02d%s", print_hour, minute,
                             ( hour >= half_day ? "PM" : "AM" ) );

} /* query_hour_minute() */

/**
 * This method returns the string of the day of the week.
 * @param day_of_week the day of the week
 */
string query_day_of_week( int day_of_week ) {
   switch( day_of_week ) {
     case TIME_FRIDAY :
       return "Friday";
     case TIME_SATURDAY :
       return "Saturday";
     case TIME_SUNDAY :
       return "Sunday";
     case TIME_MONDAY :
       return "Monday";
     case TIME_TUESDAY :
       return "Tuesday";
     case TIME_WEDNESSDAY :
       return "Wednesday";
     case TIME_THURSDAY :
       return "Thursday";
     default :
       return "Error!  Unknown day of week " + day_of_week;
   }
} /* query_day_of_week() */

/**
 * This method returns the day of month as a string.
 * This uses both the month and the day of the month
 * to get the correct strings for special days.
 * @param month the month to print out
 * @param day_of_month the day in the specific month
 */
string query_special_day(int month, int day_of_month) {

   /* Handle special days */
//   switch (month) {
//     case TIME_JANUARY :
//       switch (day_of_month) {
//         case 1 :  return "Hogswatchday";
//       }
//     break;
//     case TIME_JULY :
//       switch (day_of_month) {
//         case 16 : return "Small Gods Day";
//       }
//     break;
//     case TIME_AUGUST :
//       switch (day_of_month) {
//          case 22 : return "Soul Cake Tuesday";
//       }
//     break;
//     case TIME_OCTOBER :
//       switch (day_of_month) {
//         case 1 : return "Sektober Fools' Day";
//       }
//     break;
//   }

   return 0;

} /* query_day_of_month() */

/**
 * This method returns the month passed in as a string.
 * @param month the month to return
 * @return the month as a string
 */
string query_month( int month ) {
   switch( month ) {
     case TIME_JANUARY :
       return "January";
     case TIME_FEBURARY :
       return "February";
     case TIME_MARCH :
       return "March";
     case TIME_APRIL :
       return "April";
     case TIME_MAY :
       return "May";
     case TIME_JUNE :
       return "June";
     case TIME_JULY :
       return "July";
     case TIME_AUGUST :
       return "August";
     case TIME_SEPTEMBER :
       return "September";
     case TIME_OCTOBER :
       return "October";
     case TIME_NOVEMBER :
       return "November";
     case TIME_DECEMBER :
       return "December";
     default :
       return "Error! Month " + month + " is out of range.";
   }
} /* query_month() */

/**
 * This is a simple way to get a helpful array of values
 * for the time in the mud.  Useful in functions you want
 * to act differently for different days, months, etc.
 * It returns a five element array as described below.
 * The return values are similar to those used with
 * localtime().
 * <p>
 * The input parameter to this function should be the return
 * result from a time() system call.
 * <dl>
 *   <dt>1st element, a number for "year" :
 *   <dt>2nd element, a number for "month" :
 *     <dd> 1 = January
 *     <dd> 2 = February
 *     <dd> 3 = March
 *     <dd> 4 = April
 *     <dd> 5 = May
 *     <dd> 6 = June
 *     <dd> 7 = July (incl. Small gods day)
 *     <dd> 8 = August (incl. Soul cake tuesday)
 *     <dd> 9 = September
 *     <dd>10 = October
 *     <dd>11 = November
 *     <dd>12 = December
 *   <dt>3rd element, Day of month.
 *   <dt>4th element. Day of week.
 *     <dd>1 = Monday
 *     <dd>2 = Tuesday
 *     <dd>3 = Wednesday
 *     <dd>4 = Thursday
 *     <dd>5 = Friday
 *     <dd>6 = Saturday
 *     <dd>7 = Sunday
 *   <dt>5th element, hour, from 0 to 23 (military time).
 *   <dt>6th element, minute,
 *  </dl>
 * ie:
 * <pre> ({ year, month, day_of_month, day_of_week, hour, minute }) </pre><p>
 *  This provides the same information as mudtime() in a manner easier to code from.
 *
 * @param  number the time you want to create the array for
 * @return   returns the 5 element time array
 * @example
 * // Here's an example of part of the code for a
 * // room that looks different on Wednesdays.
 *
 *   inherit ROOM_OBJ;
 *
 *   #include <time.h>
 *
 *   string query_the_long();
 *
 *   void setup(){
 *      ...
 *     // Setup a function pointer for the long description.
 *     // This is so it can change dynamically
 *     set_long( (: query_the_long() :));
 *      ...
 *   } /\* setup() *\/
 *
 *   // This method returns the dynamically changing long
 *   // for the room.  It says something different every
 *   // Wednesday
 *   string query_the_long() {
 *       int *time_array;
 *
 *       time_array = TIME_H->query_time_array(time());
 *       if( time_array[TIME_WEEK_DAY] == TIME_WEDNESSDAY )
 *           return "A festival is in full swing, in honour "
 *                  "of the Great Coder MacChirton here, "
 *                  "with much haggis and bagpipes.\n";
 *
 *       return "This town is rather boring, and the streets "
 *              "are abandoned.\n";
 *   } /\* query_the_long() *\/
 * @see efun::time()
 * @see efun::localtime()
 * @see amtime()
 * @see /include/time.h
 */
int *query_time_array( int number ) {
   int year, month, hour, minute, day_of_week, day_of_year, day_of_month;

   year = number / SECONDS_PER_YEAR + YEAR_OFFSET;
   number %= SECONDS_PER_YEAR;
   day_of_year = number / SECONDS_PER_DAY;
   day_of_month = day_of_year;

   /* Figure out what month we are in */
   for( month = 0; month < DAYS_PER_YEAR / DAYS_PER_MONTH; month++ ) {
      if( day_of_month < DAYS_PER_MONTH )
          break;
      day_of_month -= DAYS_PER_MONTH;
   }

   /* Need to increment the month by one to make it start from 1. */
   month++;
   day_of_month++;

   /*
    * day % DAYS_PER_WEEK is not translated into
    * day of week as one would suspect.
    * when day % DAYS_PER_WEEK = 0,  the day is friday.
    * The +4 is used to correct this, and the +1 is so that
    * the first day (monday) is 1, not 0
    */
   day_of_week = ( ( ( day_of_year + 4 ) % DAYS_PER_WEEK ) + 1 );

   number = number / SECONDS_PER_MINUTE;
   hour = ( ( ( number) % MINUTES_PER_DAY) / MINUTES_PER_HOUR );
   minute = number % MINUTES_PER_HOUR;

   return ({ year, month, day_of_month, day_of_week, hour, minute });

} /* query_time_array() */

/**
 * This method returns the hour of the day in the mud.
 * @param time time to convert ( as would be returned by time() )
 * @return the hour of the day in mud in 24 hour clock
 * @see time
 * @see query_minute
 * @see query_time_array
 */
int query_hour( int time ) {
  return ( time % SECONDS_PER_DAY ) / (SECONDS_PER_MINUTE * MINUTES_PER_HOUR);
} /* query_hour() */

/**
 * This method returns the minute of the day in the mud.
 * @param time time to convert ( as would be returned by time() )
 * @return the minutes passed since midnight in the mud
 * @see time
 * @see query_hour
 * @see query_time_array
 */
int query_minute( int time ) {
  return ( time % SECONDS_PER_DAY ) / SECONDS_PER_MINUTE;
} /* query_minute() */

/**
 * This method returns the year in the mud.
 * @param time time to convert ( as would be returned by time() )
 * @return the year
 * @see time
 * @see query_hour
 * @see query_time_array
 */
int query_year( int time ) {
  return time / SECONDS_PER_YEAR + YEAR_OFFSET;
} /* query_year() */
