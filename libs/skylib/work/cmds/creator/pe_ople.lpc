/* people command, trial out by Turrican for a commands daemon. */

#include <peopler.h>
#include <creator.h>

inherit COMMAND_BASE;

/** @ignore yes */
int num_sort( object first, object second ) {
    int one, two;

    one = first->query_level();
    two = second->query_level();

    if( one < two )
        return 1;
    if( one > two )
        return -1;

    return 0;

} /* num_sort() */

/** @ignore yes */
int age_sort( object first, object second ) {
    int one, two;

    one = first->query_time_on();
    two = second->query_time_on();

    if( one < two )
        return -1;
    if( one > two )
        return 1;

    return 0;

} /* age_sort() */

/** @ignore yes */
int cmd( string str ) {
    mixed stuff;
    string bit, *bits;
    function sort_func;

    stuff = TP->query_property("people list");
    if( !stuff )
        stuff = P_DEFAULT;

    if( str ) {
        bits = explode( str, " ");
        str = 0;
        foreach( bit in bits ) {
            switch( bit ) {
            case "-l":
              sort_func = (: num_sort :);
            break;
            case "-a":
              sort_func = (: age_sort :);
            break;
            default:
              if( str )
                  str += " "+bit;
              else
                  str = bit;
            }
        }
    }

    return (int)PEOPLER->do_command( stuff, str, sort_func );

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "", (: cmd(0) :), "<string>", (: cmd($4[0]) :) });
} /* query_patterns() */
