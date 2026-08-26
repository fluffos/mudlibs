
inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *who, object *with ) {
    int pwet, twet, max, *enums;
    object person, ob;

    if( sizeof(who) > 1 ) {
        add_failed_mess("You cannot dry several people at once.\n");
        return 0;
    }

    if( sizeof(with) > 1 ) {
        add_failed_mess("You cannot dry $I with several things at "
            "once.\n", who );
        return 0;
    }

    person = who[0];
    ob = with[0];

    if( !ob->id("towel") && !ob->query_property("dryer") ) {
        add_failed_mess("You cannot dry anyone with $I.\n", with );
        return 0;
    }

    if( person->query_property("dead") ) {
        add_failed_mess("$I is dead and has more immediate problems than "
            "being wet.\n", who );
        return 0;
    }

    max = 200 * (int)ob->query_weight();
    enums = (int *)ob->effects_matching("object.wet");

    if( sizeof( enums ) )
        twet = (int)ob->arg_of( enums[ 0 ] );

    if( twet > max / 2 ) {
        add_failed_mess("$I is already dripping wet and would not make "
            "anyone drier.\n", with );
        return 0;
    }

    if( sizeof( enums = (int *)person->effects_matching("body.wetness") ) )
        pwet = (int)person->arg_of( enums[ 0 ] );

    if( pwet < 10 ) {
        if( person == TP )
            add_failed_mess("You do not need drying.\n");
        else
            add_failed_mess("$I does not need drying.\n", who );
        return 0;
    }

    if( pwet + twet > max )
        pwet = max - twet;

    pwet -= random( 10 );

    if( pwet > 0 ) {
        person->add_effect("/std/effects/other/wetness",  -pwet );
        ob->add_effect("/std/effects/object/wet", pwet );
    }

    if( person == TP ) {
        tell_object( TP, "You dry yourself with "+ob->poss_short()+".\n");
        tell_room( ENV(TP), TP->one_short()+" $V$0=dries,dry$V$ "+
            verbalize("themselves", TP->HIM+"self")+" with "+
            ob->poss_short()+".\n", TP );
    } else {
        tell_object( TP, "You dry "+person->one_short()+" with "+
            ob->poss_short()+".\n");
        tell_room( ENV(TP), TP->one_short()+" $V$0=dries,dry$V$ "+
            person->one_short()+" with "+ob->poss_short()+".\n", TP );
    }

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({
        "<indirect:living'person'> with <indirect:object:me>",
        (: cmd( $1[0], $1[1] ) :),
        "myself with <indirect:object:me>",
        (: cmd( ({ TP }), $1 ) :),
    });
} /* query_patterns() */
