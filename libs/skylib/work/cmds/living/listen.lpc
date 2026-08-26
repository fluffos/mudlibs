
inherit COMMAND_BASE;

/** @ignore yes */
int cmd() {
    string *sound;

    if( !ENV(TP) ) {
        add_failed_mess("It would help to be standing somewhere first.\n");
        return 0;
    }

    if( WEATHER_H->query_day() ) {
        if( !( sound = ENV(TP)->query_room_day_sound() ) &&
            !( sound = ENV(TP)->query_room_sound() ) ) {
            add_failed_mess("You can't really hear much at all.\n");
            return 0;
        }
    } else {
        if( !( sound = ENV(TP)->query_room_night_sound() ) &&
            !( sound = ENV(TP)->query_room_sound() ) ) {
            add_failed_mess("You can't really hear much at all.\n");
            return 0;
        }
    }

    tell_object( TP, choice(sound)+"\n");
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() { return ({ "", (: cmd() :) }); }
