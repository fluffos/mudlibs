/*
 * This stick doesn't actually do anything.  But who cares?
 * Written by Pinkfish -- Today is Setting Orange, the 38th day
 *                        of The Aftermath in the YOLD 3162
 */

inherit HELD_OBJ;

#include <move_failures.h>

int state;

void set_state(int state);

void setup() {
    set_name("stick");
    set_state(0);
    set_weight(2);
    set_value(10);
} /* setup() */

void init() {
    add_command("turn", "<direct:object> {on|off}");
    add_command("flick", "switch on <direct:object>");
    add_command("press", "switch on <direct:object>");
    add_command("push", "switch on <direct:object>");
    add_command("flick", "<direct:object>");
    add_command("turn", "switch {on|off} on <direct:object>");
    add_command("switch", "<direct:object> {on|off}");
} /* init() */

void set_state( int new_state ) {
    state = new_state;
    if( state ) {
        set_long("The long straight black stick vibrates slightly in your "
            "hands, you get a nice massage from it.  There is something "
            "which looks a bit like a switch down near the base of the "
            "stick.  Flashing lights rush up and down the side of the stick "
            "in a mad progression.\n");
    } else {
        set_long("The long straight black stick vibrates slightly in your "
            "hands, you get a nice massage from it.  There is something "
            "which looks a bit like a switch down near the base of the "
            "stick.\n");
    }

    if( environment() ) {
        if( state ) {
            if( living(environment()) )
                environment()->add_extra_look(TO);
        } else
            environment()->remove_extra_look(TO);
    }

} /* set_state() */

string extra_look() {
    return CAP(PO->query_pronoun())+" is surrounded by an aura of bees.\n";
} /* extra_look() */

int do_turn( mixed indirect_obs, string indir_match,
             string dir_match, mixed *args, string pattern ) {
    int new_state;

    new_state = 0;
    if( "<direct:object> {on|off}" == pattern ) {
        if( args[1] == "on")
        new_state = 1;
    } else {
        if( args[0] == "on")
            new_state = 1;
    }

    if( state == new_state ) {
        add_failed_mess("$D is already turned "+(state?"on":"off")+".\n");
        return 0;
    }

    set_state(new_state);

    add_succeeded_mess("$N $V $D "+(state?"on":"off")+".\n");
    return 1;

} /* do_turn() */

int do_flick() {
    set_state(!state);
    add_succeeded_mess("$N $V the switch on $D to the "+
        (state?"on":"off")+" position.\n");
    return 1;
} /* do_flick() */

int do_press() {
    return do_flick();
} /* do_press() */

int do_push() {
    return do_flick();
} /* do_push() */

int do_switch( mixed indirect_obs, string indir_match,
               string dir_match, mixed *args, string pattern) {
    int new_state;

    if( args[1] == "on")
        new_state = 1;
    if( state == new_state ) {
        add_failed_mess("$D is already turned "+(state?"on":"off")+".\n");
        return 0;
    }

    set_state(new_state);

    add_succeeded_mess("$N $V $D "+(state?"on":"off")+".\n");
    return 1;

} /* do_switch() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    mapping m;

    m = ([ "::" : held::query_dynamic_auto_load() ]);

    if( state )
        m["state"] = state;

    return m;

} /* query_dynamic_auto_load() */

/** @ignore yes */
void init_dynamic_arg( mapping map, mixed dummy ) {
    set_state(map["state"]);
    if( map["::"] )
        held::init_dynamic_arg( map["::"], dummy );
} /* init_dynamic_arg() */

/** @ignore yes */
varargs int move( mixed dest, string str1, string str2 ) {
    int ret;
    object old;

    old = environment();
    ret = ::move( dest, str1, str2 );

    if( !ret ) {
        if( state ) {
            if( old )
                old->remove_extra_look(TO);
            if( living(environment()) )
                environment()->add_extra_look(TO);
        }
    }

    return ret;

} /* move() */

/** @ignore yes */
mixed stats() { return ::stats() + ({ ({"state", state }) }); }
