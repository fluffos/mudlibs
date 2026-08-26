/**
 * Smell command started 3/04/2001 12:41PM
 * Shaydz
 */

inherit COMMAND_BASE;

/** @ignore yes */
int cmd() {
    string *smell;

    if( !ENV(TP) ) {
        add_failed_mess("It would help to be standing somewhere first.\n");
        return 0;
    }

    if( WEATHER_H->query_day() ) {
        if( !( smell = ENV(TP)->query_room_day_smell() ) &&
            !( smell = ENV(TP)->query_room_smell() ) ) {
            add_failed_mess("You can't really smell much at all.\n");
            return 0;
        }
    } else {
        if( !( smell = ENV(TP)->query_room_night_smell() ) &&
            !( smell = ENV(TP)->query_room_smell() ) ) {
            add_failed_mess("You can't really smell much at all.\n");
            return 0;
        }
    }

    tell_object( TP, choice(smell)+"\n");
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() { return ({ "", (: cmd() :) }); }
