/**
 * A generalised watch object. Taken from a watch I found in /obj/misc
 * and made into an inheritable object.
 * @author Ceres
 */

#include <time.h>

inherit OBJECT_OBJ;

#define HOURS ({"twelve", "one", "two", "three", "four", "five", "six", \
                "seven", "eight", "nine", "ten", "eleven" })

int show_date;

/** @ignore yes */
void create() {
    do_setup++;
    ::create();
    do_setup--;

    if( !do_setup )
        TO->setup();

    add_extra_look(TO);

} /* create() */

/** @ignore yes */
string extra_look( object thing ) {
    string mess;
    int minute, hour, *arr;

    minute = TIME_H->query_minute( time() ) % 60;
    hour = TIME_H->query_hour( time() );

    if( minute > 32 )
        hour = hour + 1;

    hour = hour % 12;
    mess = "It is ";

    switch(minute) {
      case 53..57:
        mess += "five to " + HOURS[hour]; break;
      case 48..52:
        mess += "ten to " + HOURS[hour]; break;
      case 43..47:
        mess += "quarter to " + HOURS[hour]; break;
      case 38..42:
        mess += "twenty to " + HOURS[hour]; break;
      case 33..37:
        mess += "twenty-five to " + HOURS[hour]; break;
      case 28..32:
        mess += "half past " + HOURS[hour]; break;
      case 23..27:
        mess += "twenty-five past " + HOURS[hour]; break;
      case 18..22:
        mess += "twenty past " + HOURS[hour]; break;
      case 13..17:
        mess += "a quarter past " + HOURS[hour]; break;
      case 8..12:
        mess += "ten past " + HOURS[hour]; break;
      case 3..7:
        mess += "five past " + HOURS[hour]; break;
      default:
        mess += HOURS[hour] + " o'clock";
    }

    if( show_date ) {
        arr = TIME_H->query_time_array( time() );
        mess += " on "+TIME_H->query_day_of_week(arr[TIME_DAY_OF_WEEK])+
                " the "+ordinal(arr[TIME_DAY_OF_MONTH])+" of "+
                TIME_H->query_month(arr[TIME_MONTH]);
    }

    return mess + ".\n";

} /* extra_look() */

/**
 * This method sets the clock to show the date as well as the time.
 */
void set_show_date() { show_date = 1; }

/**
 * This method sets up chimes for this clock.
 * @param num 1 = every hour, 2 = every half hour, 4 = every quarter hour
 * @param mess the message to be displayed when the clock chimes
 */
void set_chimes( int num, string mess ) {
    CHIME_H->register_for_chimes( TO, num, mess );
} /* set_chimes() */

/**
 * This function is called by the chime handler.
 * Overload this if you wish to have your own chime code.
 * @param mess the message set with set_chimes.
 * @param type the type of chime (quarter/half/hour)
 * @see set_chimes
 */
void do_chime( string mess, int type ) {
    say( mess );
} /* do_chime() */
