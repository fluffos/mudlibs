/**
 * Health command by Ceres
 * @change Rewritten completely, Sandoz, 2001, though it's still not good.
 */

#define CONV(x) CAP( TP->convert_message(x) )

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *who ) {
    object person;
    string health, ret;

    if( TP->check_dark( (int)ENV(TP)->query_light() ) ) {
        add_failed_mess("You cannot see well enough to examine someone's "
                        "health.\n");
        return 0;
    }

    ret = "";

    foreach( person in who ) {
        if( person->query_property("dead") ) {
            if( person == TP )
                ret += "You appear to be dead.\n";
            else
                ret += CONV( person->one_short() )+" appears to be dead.\n";
        } else if( health = person->health_string( person, 1 ) ) {
            if( person == TP )
                ret += replace_string( health, "$who$ is", "You are")+"\n";
            else
                ret += replace_string( health, "$who$",
                    CONV( person->one_short() ) )+"\n";
        } else {
            ret += person->one_short()+" is so unhealthy "+person->HE+" "
                   "has forgotten how healthy "+person->HE+" is.\n";
        }
    }

    add_succeeded_mess( ({ ret, "$N studies $I.\n" }), who );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<indirect:living:here>", (: cmd($1) :) });
} /* query_patterns() */
