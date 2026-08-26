
#include <time.h>

inherit COMMAND_BASE;

#define DAY 86400
#define MAX 30

/** @ignore yes */
int cmd( int days ) {
    int day, start, finish, i, j;
    string date, list;

    if( days < 1 ) {
        add_failed_mess("You cannot display the calendar for "+
            days+" days.\n");
        return 0;
    }

    if( days > MAX ) {
        add_failed_mess("You cannot display the calendar for more than "+
            query_num(MAX)+" days.\n");
        return 0;
    }

    // How many mud days in a real day?
    j = DAY / SECONDS_PER_DAY;
    start = time();
    finish = start + DAY * days;
    list = "";

    for( day = start; day < finish; ) {
        date = ctime( day );

        list += date[0..10]+date[20..23]+": ";
        for( i = 0; i < j; i++, day += SECONDS_PER_DAY ) {
            if( i )
                list += repeat_string(" ", 17 );
            list += mudtime( day, 2 )+"\n";
        }
    }

    TP->more_string( list, "Calendar");
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<number'number of days to display'>", (: cmd( $4[0] ) :),
        "", (: cmd( 7 ) :),
    });
} /* query_patterns() */
