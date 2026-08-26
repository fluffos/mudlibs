/**
 * Sheathe command for sheathing weapons in scabbards.
 * Original - DW, partly rewritten by Sandoz, 2002.
 */

inherit COMMAND_BASE;

int cmd( object *weapons, object *scabbards ) {
    object weapon, scabbard;
    string mess;

    if( sizeof(weapons) > 1 ) {
        add_failed_mess("You can only $V one weapon at a time.\n");
        return 0;
    }

    weapon = weapons[0];

    if( scabbards ) {
        if( sizeof(scabbards) > 1 ) {
            add_failed_mess("You can only $V $I in one scabbard.\n", weapons );
            return 0;
        }

        scabbard = scabbards[0];

        if( ENV(scabbard) != TP ) {
            add_failed_mess("You should take $I out of "+
                ENV(scabbard)->the_short()+" first, if you want to $V "+
                weapon->the_short()+" in it.\n", ({ scabbard }) );
            return 0;
        }

        if( !scabbard->query_scabbard() ) {
            add_failed_mess("$I doesn't appear to be a scabbard.\n",
                scabbards );
            return 0;
        }

        if( !scabbard->test_type_ok( weapon ) ) {
            // no idea why add_failed_mess("") doesn't work here.
            notify_fail("");
            return -1;
        }
    } else {
        scabbards = filter( INV( TP ), (: $1->query_scabbard() &&
            $1->test_type_ok( $(weapon), 0, 1 ) :) );

        if( !sizeof( scabbards ) ) {
            add_failed_mess("You don't appear to have a suitable scabbard "
                "for $I.\n", weapons );
            return 0;
        }

        scabbards = filter( scabbards, (: $1->test_add( $(weapon) ) :) );
        if( !sizeof(scabbards) ) {
            add_failed_mess("You don't have any other scabbards you could $V "
                "$I in.\n", weapons );
            return 0;
        }

        scabbard = scabbards[0];
    }

    if( weapon->query_wielded() && !sizeof( TP->set_unhold(weapon) ) ) {
        add_failed_mess("You cannot let go of "+weapon->the_short()+" for "
            "some reason.\n");
        return 0;
    }

    // This is to get the messages right.
    mess = PLAYER_OBJ->convert_message( TP->one_short()+" $V "+
           weapon->one_short()+" in "+scabbard->poss_short()+".\n");

    if( weapon->move(scabbard) ) {
        add_failed_mess("");
        return 0;
    }

    TP->add_succeeded_mess( scabbard, ({
        "$N $V "+weapon->the_short()+" in $D.\n", mess }) );
    return 1;

} /* cmd() */

mixed query_patterns() {
    return ({"<indirect:object:me'weapon'>", (: cmd( $1, 0 ) :),
             "<indirect:object:me'weapon'> in <indirect:object:me'scabbard'>",
             (: cmd( $1[0], $1[1]) :),
             });
} /* query_patterns() */
